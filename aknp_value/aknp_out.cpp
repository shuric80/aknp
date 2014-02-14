#include "aknp_out.h"
#define CF 145
#include <QDebug>

aknp_out::aknp_out(QWidget *parent)
{



    TWidget = new top_diaposon;
    PDWidget = new pd_diaposon;
    RD1Widget = new rd1_diaposon;
    RD2Widget = new rd2_diaposon;
    //ake_imit = new AkeSlideImitator;

  //  PD1Widget->setVisible(false);


   // TWidget->setFixedHeight(140);
  //  RD2Widget ->setFixedHeight(140);
  //  RD1Widget->setFixedHeight(140);
  //  PDWidget->setFixedHeight(140);

    QVBoxLayout *verticalLayout = new QVBoxLayout;
    QHBoxLayout *diap_layout[4];

    verticalLayout->addWidget(TWidget);
    verticalLayout->addLayout(diap_layout[0] = new QHBoxLayout);//("Поддиапазон РД2"));
    verticalLayout->addWidget(RD2Widget);
    verticalLayout->addSpacing(30);
    verticalLayout->addLayout( diap_layout[1]= new QHBoxLayout);//("Поддиапазон РД1"));
    verticalLayout->addWidget(RD1Widget);
    verticalLayout->addSpacing(30);
    verticalLayout->addLayout(diap_layout[2] = new QHBoxLayout);//("Поддиапазон ПД1"));
    verticalLayout->addWidget(PDWidget);
    verticalLayout->addLayout(diap_layout[3] = new QHBoxLayout);//("Поддиапазон ПД1"));
    //verticalLayout->addWidget(PD1Widget);
    verticalLayout->addStretch(1);

    for(int i =0;i<3;i++){


        diap_layout[i]->addWidget(label[i] = new QLabel);
        diap_layout[i]->addStretch(1);
        diap_layout[i]->addWidget(ind[i] = new QLabel);
        diap_layout[i]->addStretch(1);
        label[i]->setStyleSheet(" background-color: rgb(150,150,150);border-radius: 5px; border-color: beige; padding: 1px;");
        label[i]-> setFrameStyle(QFrame::Panel | QFrame::Raised);
        label[i]-> setLineWidth(1);
        label[i]->setMinimumHeight(15);
        ind[i]->setFixedSize(6,6);
        ind[i]->setStyleSheet("background-color:rgb(240,240,240);border-radius:2px;padding :1px");
    }
    label[0]->setText("Поддиапазон РД2");
    label[1]->setText("Поддиапазон РД1");
    label[2]->setText("Поддиапазон ПД");


    QHBoxLayout *topLayout = new QHBoxLayout;
    //topLayout->addLayout(akeLayout);
    topLayout->addLayout(verticalLayout);
    this->setLayout(topLayout);
    //	RD2Widget->set_analog(5,120);


    count[0]=0;
    count[1]=0;
    count[2]=0;
    for(int i=0;i<3;i++){
        timer[i] =new  QTimer(this);
        timer[i]->setInterval(500);
    }
    connect(timer[0],SIGNAL(timeout()),RD2Widget,SLOT(clean()));
    connect(timer[1],SIGNAL(timeout()),RD1Widget,SLOT(clean()));
    connect(timer[2],SIGNAL(timeout()),PDWidget,SLOT(clean()));

    //connect(timer[0],SIGNAL(timeout()),this,SLOT(setNG()));

    //	timer->start(500);
}

void aknp_out::select(const QVector<int> &value){

    int id = value.at(0);
    QVector <int> data_l;
    QVector <int> data_h;

    data_l = value.mid(1,4);
    data_h = value.mid(5,4);
    float analog_l = toFloat(data_l);
    float analog_h = toFloat(data_h);

    switch(id){

    case 0x401:
        RD2Widget-> set_analog(0,analog_l,4);
        RD2Widget-> set_analog(3,analog_h,1);
        break;

    case 0x404:
        RD2Widget->set_discret(0,discret(value.at(5),0));  // az rd2
        RD2Widget->set_discret(1,discret(value.at(5),1));   // pz rd2
        RD2Widget->set_discret(12,discret(value.at(5),3));  //  start diap rd2
        RD2Widget->set_discret(9,discret(value.at(5),4));   // >5%
        RD2Widget->set_discret(10,discret(value.at(5),5));   // >75
        RD2Widget->set_discret(13,!discret(value.at(5),6));   //  err
        RD2Widget->set_discret(14,!discret(value.at(7),0));   //  err bh rd2

        RD1Widget->set_discret(14,!discret(value.at(7),1));   //err bh rd1

        TWidget->set_discret(12,discret(value.at(7),5));
        TWidget->set_discret(0,discret(value.at(7),6));
        TWidget->set_discret(1,discret(value.at(7),7));

        TWidget->set_discret(3,!discret(value.at(6),0)); // ГЦН1
        TWidget->set_discret(4,!discret(value.at(6),1)); // ГЦН2
        TWidget->set_discret(6,!discret(value.at(6),2)); // ГЦН3
        TWidget->set_discret(7,!discret(value.at(6),3)); // ГЦН4
        TWidget->set_discret(13,discret(value.at(6),6));

        count[0]++;

        if(count[0] == 5)
            ind[0]->setStyleSheet("background-color:rgb(0,255,0);border-radius:2px;padding :1px");
        else if(count[0] ==10){
            ind[0]->setStyleSheet("background-color:rgb(240,240,240);border-radius:2px;padding :1px");
            count[0]=0;
        }
        else{
            timer[0]->stop();
            timer[0]->start();
        }
        break;

    case 0x102:
        RD1Widget->set_analog(0,analog_l,2);
        RD1Widget->set_analog(3,analog_h,2);
        break;

    case 0x103:
        RD1Widget->set_analog(1,analog_l);
        RD1Widget->set_analog(4,analog_h);
        break;

    case 0x104:
        PDWidget->set_analog(0,analog_l,2);
        PDWidget->set_analog(3,analog_h,2);
        break;

    case 0x105:
        PDWidget->set_analog(1,analog_l);
        PDWidget->set_analog(4,analog_h);
        break;

    case 0x106:
        TWidget->set_analog(0,analog_l,2);
        TWidget->set_analog(1,analog_h);
        break;

    case 0x107:
        RD1Widget->set_discret(0,discret(value.at(1),0));
        RD1Widget->set_discret(3,discret(value.at(1),2));
        RD1Widget->set_discret(1,discret(value.at(1),1));
        RD1Widget->set_discret(4,discret(value.at(1),3));
        RD1Widget->set_discret(12,discret(value.at(1),4));
        RD1Widget->set_discret(13,!discret(value.at(1),5));

        PDWidget->set_discret(0,discret(value.at(2),0));
        PDWidget->set_discret(1,discret(value.at(2),1));
        PDWidget->set_discret(3,discret(value.at(2),2));
        PDWidget->set_discret(4,discret(value.at(2),3));
        PDWidget->set_discret(12,discret(value.at(2),4));
        PDWidget->set_discret(13,!discret(value.at(2),5));

        label[0]->setStyleSheet(discret(value.at(3),0) ? " background-color:rgb(0,250,0) ;border-radius: 5px; border-color: beige; padding: 2px;":
                                                         " background-color:rgb(CF,CF,CF) ;border-radius: 5px; border-color: beige; padding: 2px;");
        label[1]->setStyleSheet(discret(value.at(3),1) ? " background-color:rgb(0,250,0) ;border-radius: 5px; border-color: beige; padding: 2px;":
                                                         " background-color:rgb(CF,CF,CF) ;border-radius: 5px; border-color: beige; padding: 2px;");
        label[2]->setStyleSheet(discret(value.at(3),2) ? " background-color:rgb(0,250,0) ;border-radius: 5px; border-color: beige; padding: 2px;":
                                                         " background-color:rgb(CF,CF,CF) ;border-radius: 5px; border-color: beige; padding: 2px;");
        label[3]->setStyleSheet(discret(value.at(3),3) ? " background-color:rgb(0,250,0) ;border-radius: 5px; border-color: beige; padding: 2px;":
                                                         " background-color:rgb(CF,CF,CF) ;border-radius: 5px; border-color: beige; padding: 2px;");
        label[4]->setStyleSheet(discret(value.at(3),4) ? " background-color:rgb(0,250,0) ;border-radius: 5px; border-color: beige; padding: 2px;":
                                                         " background-color:rgb(CF,CF,CF) ;border-radius: 5px; border-color: beige; padding: 2px;");
        count[1]++;
        if(count[1] == 5){
            ind[1]->setStyleSheet("background-color:rgb(0,255,0) ;border-radius:2px;padding :1px");
            ind[2]->setStyleSheet("background-color:rgb(240,240,240);;border-radius:2px;padding :1px");
        }
        else if(count[1] ==10){
            ind[1]->setStyleSheet("background-color:rgb(240,240,240);border-radius:2px;padding :1px");
            ind[2]->setStyleSheet("background-color:rgb(0,255,0);;border-radius:2px;padding :1px");
            count[1]=0;
        }
        timer[1]->stop();
        timer[1]->start();
        break;


    default:
        break;
    }
}

bool aknp_out::discret( int byte,int bit){

    if(!((byte >> bit) & 0x1))
        return  false;
    else
        return true;
}

float aknp_out::toFloat(QVector<int> value){

    float f;
    quint8 *str = (quint8*) &f;
    str[0] = value.at(0);
    str[1] = value.at(1);
    str[2] = value.at(2);
    str[3] = value.at(3);

    return f;
}
