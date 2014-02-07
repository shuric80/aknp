#include "aknp_imit.h"
#define TIME 200

aknp_imit::aknp_imit(QWidget *parent):QWidget(parent){

    stack = new QStackedWidget(this);
    combo = new QComboBox(this);

    QString style = QString("color:white");


    {   combo->setStyleSheet("color:black; background-color:white;color:black;\
                             selection-color:white;selection-background-color:grey");

        combo->addItem("Генератор частоты");
        combo->addItem("Имитатор времени удвоения");
        combo->addItem("Имитатор реактивности");
        combo->addItem("Проверка имитатора реактивности");
        combo->addItem("Проверка НП");
    }
//this->setStyleSheet("background-color:rgb(50,50,50)");
    FreqGenerator *freq[4];

    periodimit =new PeriodImit(this);
    reactimit =new react_imit(true,this);
    test_react_imit  = new  react_imit(false,this);
    verify_widget =new verify(this);

    QVBoxLayout *freq_layout =new QVBoxLayout;
    QVBoxLayout *vert_layout = new QVBoxLayout;

    vert_layout->addWidget(combo);
    vert_layout->addWidget(stack);

    QLabel *label[4];
    QWidget *freq_widget = new QWidget(this);

    for(int i=3;i>=0;i--){
      //  freq_layout->addWidget(label[i]  =new QLabel);//(QString("КАНАЛ %1").arg(i)));
        freq_layout->addWidget(freq[i] =new FreqGenerator(i));
        freq[i]->setFixedHeight(150);

    };
    /*{
        label[3]->setText("Поддиапазон РД");
        label[2]->setText("Поддиапазон ПД2");
        label[1]->setText("Поддиапазон ПД1");
        label[0]->setText("Поддиапазон ИД");

    }
    */
    //freq_layout->addStretch(1);
    freq_widget->setLayout(freq_layout);

    stack->addWidget(freq_widget);
    stack->addWidget(periodimit);
    stack->addWidget(reactimit);
    stack->addWidget(test_react_imit);
    stack->addWidget(verify_widget);

    this->setLayout(vert_layout);

    connect(combo,SIGNAL(activated(int)),stack,SLOT(setCurrentIndex(int)));
    connect(combo,SIGNAL(activated(int)),this,SLOT(stopFreq(int)));

    for(int i=0;i<4;i++)
        connect(freq[i],SIGNAL(setFreq(int,float)),this,SLOT(slot_freqgenerator(int,float)));

    connect(periodimit,SIGNAL(send(QVector<float>)),this,SLOT(slot_periodImit(QVector<float>)));
    connect(periodimit,SIGNAL(mode_imit(int)),this,SLOT(mode_imit(int)));
    connect(reactimit,SIGNAL(send(QVector<float>)),this,SLOT(slot_reactImit(QVector<float>)));
    connect(reactimit,SIGNAL(mode_imit(int)),this,SLOT(mode_imit(int)));
    connect(test_react_imit,SIGNAL(mode_imit(int)),this,SLOT(mode_imit(int)));
    connect(test_react_imit,SIGNAL(send(QVector<float>)),this,SLOT(slot_reactImit(QVector<float>)));
    connect(verify_widget,SIGNAL(send_verify(int)),this,SLOT(mode_imit(int)));
}



void aknp_imit::stopFreq(int n){

    mode_imit(0);
    periodimit->reset();
    reactimit->reset();
    test_react_imit->reset();
}

void aknp_imit::select(const QVector<int> &value){

    int id = value.at(0);
    QVector <int> data_h;
    QVector <int> data_l;

    data_l = value.mid(1,4);
    data_h = value.mid(5,4);
    float val_l = toFloat(data_l);
    float val_h = toFloat(data_h);

    switch (id) {
    case 0x381:{
        reactimit->input_power(val_l);
        reactimit->input_react(val_h);
        break;
    }
    case 0x382:{
        periodimit->input_power(val_l);
        test_react_imit->input_power(val_l);
        break;
    }
    default:
        break;
    }

}

void aknp_imit::slot_freqgenerator(int channel, float value){

    QVector<int> buffer;

    switch (channel) {
    case 0:
        buffer.append(0x301);
        break;
    case 1:
        buffer.append(0x302);
        break;
    case 2:
        buffer.append(0x303);
        break;
    case 3:
        buffer.append(0x304);
        break;
    default:
        break;
    }
    buffer << toVector(value);

    emit send(buffer);

}

float aknp_imit::toFloat(QVector<int> value){

    float f;
    quint8 *str = (quint8*) &f;
    str[0] = value.at(0);
    str[1] = value.at(1);
    str[2] = value.at(2);
    str[3] = value.at(3);

    return f;
}

QVector<int> aknp_imit::toVector(float val){

    QVector <int> tmp;

    quint8 *N = (quint8*)&val;

    for(int i =0;i<4;i++)
        tmp.append(N[i]);

    return tmp;
}

void aknp_imit::mode_imit(int m){

    QVector<int> tmp;
    tmp << 0x30B;
    tmp << m;

    emit send(tmp);
}

void aknp_imit::slot_reactImit(QVector<float> value){

    QVector<int> power_st;
    QVector<int> power_en;
    QVector<int>  time;
    QVector<int> react;

    power_st << 0x305 << toVector(value.at(0));
    power_en << 0x306 << toVector(value.at(1));
    time << 0x309 << toVector(value.at(2));
    react << 0x308 << toVector(value.at(3));

    for(int i=0;i<10;i++){

        emit send(power_en);
        emit send(power_st);
        emit send(time);
        emit send(react);
    }

}


void aknp_imit::slot_periodImit(QVector<float> value){

    QVector<int> power_st;
    QVector<int> power_en;
    QVector<int>  time;

    power_st << 0x305 << toVector(value.at(0));
    power_en << 0x306 << toVector(value.at(1));
    time << 0x307 << toVector(value.at(2));

    for(int i=0;i<5;i++){

        emit send(power_en);
        emit send(power_st);
        emit send(time);
    }
}

aknp_imit::~aknp_imit(){

    mode_imit(0);
}
