#include "akr_widget.h"
#include <QDebug>
#define PASSWORD 1234
akr_widget::akr_widget(QWidget *parent) :
    QWidget(parent)
{
    qRegisterMetaType <QVector<int> > ("QVector<int>");
    toggled=false;
    timer = new QTimer;

    QFont font("Monospace",9);
    this->setFont(font);
    
    QHBoxLayout *layout[18];// = new QHBoxLayout;

    QVBoxLayout *right_layout = new QVBoxLayout;
    QVBoxLayout *central_layout = new QVBoxLayout;
    QHBoxLayout *top_layout = new QHBoxLayout;
    
    for(int i=0;i<17;i++){
        layout[i]= new QHBoxLayout;
        layout[i]->addWidget(label[i]=new QLabel);
        label[i]->setMaximumHeight(30);
        layout[i]->addStretch(1);
    }
    
    central_layout->addWidget(box =new QComboBox(this));
    save_btn =  new QPushButton("Пароль");
    reset_btn = new QPushButton("Отмена");
    layout[17] = new QHBoxLayout;
    
    layout[17]->addWidget(save_btn);
    layout[17]->addStretch(1);
    layout[17]->addWidget(reset_btn);
    
    layout[0]->addWidget(diaposon_line = new QLineEdit(this));
    
    
    central_layout->addLayout(layout[0]);
    
    for(int i=1;i<5;i++){
        layout[i]->addWidget(analog_line[i-1]= new QLineEdit(this));
        central_layout->addLayout(layout[i]);
    }
    
    central_layout->addStretch(1);
    right_layout->addSpacing(30);
    layout[5]->addWidget(analog_line[4] = new QLineEdit(this));
    right_layout->addLayout(layout[5]);
    
    for(int i=6;i<11;i++){
        layout[i]->addWidget(discret_box[i-6] = new QComboBox(this));
        right_layout->addLayout(layout[i]);
    }

    for(int i=11;i<16;i++){
        layout[i]->addWidget(analog_line[i-6] = new QLineEdit(this));
        right_layout->addLayout(layout[i]);
        analog_line[i-6]->setReadOnly(true);
    }

    layout[16]->addWidget(cannel_label = new QLabel(this));
    right_layout->addLayout(layout[16]);
    right_layout->addSpacing(40);
    right_layout->addLayout(layout[17]);
    right_layout->addStretch(1);
    
    label[0]->setText("Диапазон контроля");
    label[1]->setText(QString("Реактивность, %1").arg(QChar(0x03B2)));
    label[2]->setText("Мощность, %");
    label[3]->setText("Частота, Гц");
    label[4]->setText("Скорость, c");
    
    label[5]->setText("Ns,%");
    label[6]->setText("Pu/U");
    label[7]->setText("Усреднение");
    label[8]->setText("Fгр ПД2 <-> РД1,Гц");
    label[9]->setText("Fгр ПД1 <-> ПД2,Гц");
    label[10]->setText("Fгр ИД <-> ПД1,Гц");
    label[11]->setText("N/F рд1,рд2");
    label[12]->setText("N/Fпд2");
    label[13]->setText("N/Fпд1");
    label[14]->setText("N/Fид");
    label[15]->setText("F0,Гц");
    label[16]->setText("N канала");


    QString style = QString("background-color:lightgrey;\
            color:dark; padding:0px;\
            border:0px");

  //  for(int i=0;i<17;i++)
  //      label[i]->setStyleSheet(style);
    
    list_select_diap << "автомат.выбор" << "РД1" << "ПД2"  << "ПД1"<<"ИД";
    list_puu << "0.000"<<"0.100"<<"0.193" <<"402"<<"0.672"<<"1.051"<<"1.604"<<"24.950"<<"0.00k";
    list_f <<"0.15 - 0.3" << "0.3 - 0.6" <<"0.6 - 1.2" <<"1.2 - 2.4" << "2.4 - 4.8" <<"4.8 - 9.6"<<"9.6 - 19.2"<<"19.2 - 38.4";
    list_sr << "без усреднения "<<"по 2 значениям"<<"по 4 значениям"<<"по 16 значениям"<<"по 32 значениям"<<"по 8/32 значениям";
    
    
    diaposon_line->setReadOnly(true);
    diaposon_line->setStyleSheet("background-color:rgb(235,235,235)");
    diaposon_line->setFocusPolicy(Qt::NoFocus);
    diaposon_line->setFixedSize(50,25);
    //diaposon_line->setFont(font);
    box ->addItems(list_select_diap);
    box->setMaximumWidth(150);
    
    discret_box[0]->addItems(list_puu);
    discret_box[1]->addItems(list_sr);
    discret_box[2]->addItems(list_f);
    discret_box[3]->addItems(list_f);
    discret_box[4]->addItems(list_f);
    
    for(int i=0;i<10;i++){
        analog_line[i]->setReadOnly(true);
        analog_line[i]->setFocusPolicy(Qt::NoFocus);
        analog_line[i]-> setStyleSheet("background-color:rgb(235,235,235)");
        analog_line[i]->setFixedSize(70,25);

    }
    for(int i =0;i<5;i++){
        discret_box[i]->setFocusPolicy(Qt::NoFocus);
        discret_box[i]->setEnabled(false);
    }
    
    top_layout->addLayout(central_layout);
    top_layout->addSpacing(20);
    top_layout->addLayout(right_layout);
    setLayout(top_layout);
    
    for(int i=4;i<10;i++)
        analog_line[i]->setFocusPolicy(Qt::NoFocus);
    
    save_btn->setVisible(true);
    
    reset_btn->setVisible(false);

    connect(box,SIGNAL(activated(int)),this,SLOT(slot_save()));
    connect(save_btn,SIGNAL(clicked()),this,SLOT(input_password()));
    connect(reset_btn,SIGNAL(clicked()),this,SLOT(slot_reset()));

    box->setVisible(false);
    
    QTimer::singleShot(1000,this,SLOT(init()));

    connect(timer,SIGNAL(timeout()),this,SLOT(clear()));  //clear form if no send data


}

void akr_widget::clear(){
    
    for(int i=0;i<9;i++)
        analog_line[i]->clear();

    
}



void akr_widget::input_password(){
    bool ok;
    if(toggled){
        slot_save();
        slot_reset();
        toggled =false;
    }
    else {
        
        QString text = QInputDialog::getText( this,tr("пароль"),"",
                                              QLineEdit::Password, QString(""), &ok);
        
        if(ok && (text == QString::number(PASSWORD))){
            for(int i=4;i<10;i++){
                analog_line[i] ->setFocusPolicy(Qt::StrongFocus);
                analog_line[i]->setStyleSheet("background-color: white");
                //  analog_line[i]->setInputMask("0.00e-00");
                analog_line[i]->setReadOnly(false);
            }
            analog_line[4]->setInputMask("0.00e-00");
            
            for(int i=5;i<9;i++)
                analog_line[i]->setInputMask("0.0e-00");
            
            
            
            for (int i=0;i<5;i++){
                discret_box[i]->setEnabled(true);
                discret_box[i]->setFocusPolicy(Qt::TabFocus);
            }
            
            save_btn->setText("Сохранить");
            reset_btn->setEnabled(true);
            reset_btn->setVisible(true);
            toggled =true;;
        }
        else{
            emit slot_reset();
        }
    }
}



void akr_widget::slot_save(){
    
    //float koef_nfrd = analog_line[5]->text()
    QVector<int> koef_nf0;
    QVector<int> koef_nf1;
    QVector<int> power_dd;
    QVector<int> freq0;
    
    koef_nf0 << 0x281;
    koef_nf1 << 0x282;
    power_dd << 0x283;
    freq0 << 0x284;
    
    koef_nf0 << toVector(analog_line[5]->text());
    koef_nf0 << toVector(analog_line[6]->text());
    
    koef_nf1 << toVector(analog_line[7]->text());
    koef_nf1 << toVector(analog_line[8]->text());
    
    freq0 << toVector(analog_line[9]->text());
    power_dd << toVector(analog_line[4]->text());
    
    quint8 byte[4];
    
    byte[0] = box->currentIndex();
    byte[0] |= (discret_box[0]->currentIndex() << 4);
    
    byte[1] = discret_box[2]->currentIndex();
    byte[1] |=(discret_box[3]->currentIndex() << 4);
    
    byte[2] = discret_box[1]->currentIndex();
    byte[2]|=(discret_box[4]->currentIndex() << 4);
    
    byte[3] = 0x0;
    
    // qDebug() << bin <<  byte[3] << byte[2] << byte[1] << byte[0];
    
    for(int i=0;i<4;i++)
        power_dd << byte[i];
    for(int i=0;i<10;i++){
        mutex.lock();
        emit send(koef_nf0);
        
        emit send(koef_nf1);
        
        emit send(power_dd);
        
        emit send(freq0);
        
        QVector<int> save;
        save << 0x285;
        emit send(save);
        
        mutex.unlock();
    }
    //slot_reset();
}




QVector<int> akr_widget::toVector(const QString &str){
    
    float f;
    bool ok;
    f =str.toFloat(&ok);
    
    QVector <int> tmp;
    
    quint8 *N = (quint8*)&f;
    
    for(int i =0;i<4;i++)
        tmp.append(N[i]);
    
    return tmp;
}

void akr_widget::slot_reset(){
    for(int i=4;i<10;i++){
        analog_line[i]->setStyleSheet("background-color: rgb(235,235,235)");
        analog_line[i]->setInputMask("");
        analog_line[i]->setReadOnly(true);
        analog_line[i]->setFocusPolicy(Qt::NoFocus);
        save_btn->setText("Пароль");
        reset_btn->setEnabled(false);
        
    }
    
    for (int i=0;i<5;i++){
        discret_box[i]->setEnabled(false);
        
        discret_box[i]->setFocusPolicy(Qt::NoFocus);
    }
    save_btn->setText("Пароль");
    reset_btn->setVisible(false);
    
    QVector<int> reset;
    reset<< 0x280<<0<<0;
    emit send(reset);
    
}

void akr_widget::select(const QVector<int> &value){
    mutex.lock();
    mutex.unlock();
    int id = value.at(0);
    QVector <int> data_l;
    QVector <int> data_h;
    data_l = value.mid(1,4);
    data_h = value.mid(5,4);
    float analog_l = toFloat(data_l);
    float analog_h = toFloat(data_h);
    
    switch (id) {
    case 0x201 :
        if(analog_l <-99)
            analog_l =-99.0000;
        else
            analog_l = analog_l;
        
        analog_line[0]->setText(QString::number(analog_l,'f',4));
        analog_line[1]->setText(QString::number(analog_h,'e',2));
        timer->stop();
        timer->start(500);

        break;
        
    case 0x202 :
        analog_line[2]->setText(QString::number(analog_l,'e',2));
        analog_line[3]->setText(QString::number(analog_h,'e',2));
        break;
        
        
    case 0x203:
    {
        if(value.at(1) == 0b00001)
            diaposon_line->setText("Неисправность");
        
        else if(value.at(1) == 0b00010)
            diaposon_line->setText("РД1");
        
        else if(value.at(1) == 0b00100)
            diaposon_line->setText("ПД2");
        else if(value.at(1)== 0b01000)
            diaposon_line->setText("ПД1");
        else if(value.at(1) == 0b10000)
            diaposon_line->setText("ИД");
        else {}
    }
        
        break;
        
    case 0x204:
        // qDebug()<< "id 204";
        analog_line[5]->setText(QString::number(analog_l,'e',1));
        analog_line[6]->setText(QString::number(analog_h,'e',1));
        break;
        
    case 0x205:
        analog_line[7]->setText(QString::number(analog_l,'e',1));
        analog_line[8]->setText(QString::number(analog_h,'e',1));
        break;
        
        
    case 0x206:{
        analog_line[4]->setText(QString::number(analog_l,'e',2));
        // set discret
        int diap = value.at(5) & 0xF;
        int puu =  (value.at(5) >> 4 )& 0xF;
        int sred = value.at(7) & 0xF;
        int pd2rd1 = value.at(6) & 0xF;
        int pd1pd2 = (value.at(6) >> 4) & 0xF;
        int pd2id = (value.at(7) >>4 ) & 0xF;
        
        box->setCurrentIndex(diap);
        discret_box[0]->setCurrentIndex(puu);//puu
        discret_box[1]->setCurrentIndex(sred);  // Sred
        discret_box[2]->setCurrentIndex(pd2rd1); //  PD2 -RD1
        discret_box[3]->setCurrentIndex(pd1pd2);  //PD1 -PD2
        discret_box[4]->setCurrentIndex(pd2id);//PD2 -ID
        break;
    }
        
    case 0x207:
        analog_line[9]->setText(QString::number(analog_l,'g',4));
        break;
        
    default:
        break;
    }
}


float akr_widget::toFloat(QVector<int> value){
    
    float f;
    quint8 *str = (quint8*) &f;
    str[0] = value.at(0);
    str[1] = value.at(1);
    str[2] = value.at(2);
    str[3] = value.at(3);
    
    return f;
}

void akr_widget::init(){
    
    QVector<int> initFrame;
    initFrame << 0x280;
    emit send(initFrame);
    
}
