#include "aknp_imit.h"
#define TIME 200

aknp_imit::aknp_imit(QWidget *parent):QWidget(parent){

    stack = new QStackedWidget(this);
    //  combo = new QComboBox(this);


    QFont font("Monospace",9);
    this->setFont(font);

    FreqGenerator *freq[2];

    periodimit =new PeriodImit(this);
    reactimit =new react_imit(true,this);
    test_react_imit  = new  react_imit(false,this);
    verify_widget =new verify(this);


    QVBoxLayout *freq_layout =new QVBoxLayout;
    QVBoxLayout *vert_layout = new QVBoxLayout;

    //vert_layout->addWidget(combo);
    vert_layout->addWidget(stack);

    QLabel *label[2];
    QWidget *freq_widget = new QWidget(this);

    for(int i=1;i>=0;i--){
        freq_layout->addWidget(label[i]  =new QLabel);//(QString("КАНАЛ %1").arg(i)));
        freq_layout->addWidget(freq[i] = new FreqGenerator(i));
    };

    freq_layout->addStretch(1);

    label[0]->setText("Поддиапазон ПД");
    label[1]->setText("Поддиапазон РД");

    freq_widget->setLayout(freq_layout);

    QWidget *privodWidget = new QWidget(this);
    QVBoxLayout *privodLayout = new QVBoxLayout;

    PrivodImit *privodImit[4];

    for(int i=0;i<4;i++)
        privodLayout->addWidget(privodImit[i] = new PrivodImit(i));

    {
        QHBoxLayout *layout_0 = new QHBoxLayout;
        QHBoxLayout *layout_1 = new QHBoxLayout;
        QLabel *label[4];

        layout_0->addWidget(label[0] = new QLabel("H"));
        layout_0->addWidget(privodBox[0] = new QSpinBox);

        layout_0->addWidget(label[1] = new QLabel("H"));
        layout_0->addWidget(privodBox[1] = new QSpinBox);

        layout_1->addWidget(label[2] = new QLabel("H"));
        layout_1->addWidget(privodBox[2] = new QSpinBox);

        layout_1->addWidget(label[3] = new QLabel("H"));
        layout_1->addWidget(privodBox[3] = new QSpinBox);

        privodLayout->addLayout(layout_0);
        privodLayout->addLayout(layout_1);

        for(int i=0;i<4;i++)
            privodBox[i]->setRange(0,255);

        privodWidget->setLayout(privodLayout);

    }
    {
        stack->addWidget(freq_widget);
        stack->addWidget(periodimit);
        stack->addWidget(reactimit);
        stack->addWidget(test_react_imit);
        stack->addWidget(verify_widget);
        stack->addWidget(privodWidget);
    }

    this->setLayout(vert_layout);

    //  connect(combo,SIGNAL(activated(int)),stack,SLOT(setCurrentIndex(int)));
    //  connect(combo,SIGNAL(activated(int)),this,SLOT(stopFreq(int)));

    for(int i=0;i<2;i++)
        connect(freq[i],SIGNAL(setFreq(int,float)),this,SLOT(slot_freqgenerator(int,float)));

    connect(periodimit,SIGNAL(send(QVector<float>)),this,SLOT(slot_periodImit(QVector<float>)));
    connect(periodimit,SIGNAL(mode_imit(int)),this,SLOT(mode_imit(int)));
    connect(reactimit,SIGNAL(send(QVector<float>)),this,SLOT(slot_reactImit(QVector<float>)));
    connect(reactimit,SIGNAL(mode_imit(int)),this,SLOT(mode_imit(int)));
    connect(test_react_imit,SIGNAL(mode_imit(int)),this,SLOT(mode_imit(int)));
    connect(test_react_imit,SIGNAL(send(QVector<float>)),this,SLOT(slot_reactImit(QVector<float>)));
    connect(verify_widget,SIGNAL(send_verify(int)),this,SLOT(mode_imit_byte2(int)));

    for(int i=0;i<4;i++)
        connect(privodImit[i],SIGNAL(setFreq(int,float)),this,SLOT(slot_freqgenerator(int,float)));

    for(int i=0;i<4;i++)
        connect(privodBox[i],SIGNAL(valueChanged(int)),SLOT(slot_privod(int)));

    mode_imit(0);
    ::usleep(1000);
    mode_imit(0b10000);// mode imit power

}



void aknp_imit::stopFreq(int n){

    mode_imit(0);
    periodimit->reset();
    reactimit->reset();
    test_react_imit->reset();
    if(n==6){
        stack->setDisabled(true);
        stack->setCurrentIndex(0);
    }
    else if(n==0)
        mode_imit(0b10000);// mode imit power
    else if(n==5)
        mode_imit(0b100000);
    else
        stack->setDisabled(false);


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

  //  mode_imit(16);

    QVector<int> buffer;

    switch (channel) {
    case 3:
        buffer.append(0x301);
        break;
    case 2:
        buffer.append(0x302);
        break;
    case 1:
        buffer.append(0x304);
        break;
    case 0:
        buffer.append(0x303);
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
    tmp << 0;

    emit send(tmp);
}

void aknp_imit::mode_imit_byte2(int m){

    QVector<int> tmp;
    tmp << 0x30B;
    tmp << 0;
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

    //for(int i=0;i<10;i++){

        emit send(power_en);
         ::usleep(1000);
        emit send(power_st);
         ::usleep(1000);
        emit send(time);
         ::usleep(1000);
        emit send(react);
    //}

}


void aknp_imit::slot_periodImit(QVector<float> value){

    QVector<int> power_st;
    QVector<int> power_en;
    QVector<int>  time;

    power_st << 0x305 << toVector(value.at(0));
    power_en << 0x306 << toVector(value.at(1));
    time << 0x307 << toVector(value.at(2));

  //  for(int i=0;i<5;i++){

        emit send(power_en);
        ::usleep(1000);
        emit send(power_st);
        ::usleep(1000);
        emit send(time);
  //  }
}


void aknp_imit::slot_privod(int value){

    if((value >182) &&(value<255)){
        for(int i =0;i<4;i++)
            privodBox[i]->setStyleSheet("background-color:pink");
        }
    else{
        for(int i=0;i<4;i++)
            privodBox[i]->setStyleSheet("background-color:white");


    mode_imit(32);

    QVector<int> data;
    data << 0x30C;

    for(int i=0;i<4;i++)
        data << privodBox[i]->value();
    emit send(data);
    //qDebug()<<hex << data;
   }

}

aknp_imit::~aknp_imit(){

    mode_imit(0);
}
