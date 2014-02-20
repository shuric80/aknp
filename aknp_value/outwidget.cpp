#include "outwidget.h"
#define W_ANALOG 75
#define H_ANALOG 35
#define W_DISCRET 55
#define H_DISCRET 25


#define SPACE  10

outWidget::outWidget(QWidget *parent) :
    QWidget(parent){

    QFont font("Monospace");
    font.setPixelSize(12);
    this->setFont(font);

    QString style = QString("background-color:rgb(100,100,100);color:rgb(250,250,250);\
                            padding:0px;border-radius:10px");


    for(int i=0;i<6;i++){
       analog[i] = new QLabel(this);
       analog[i]->setStyleSheet(style);
       analog[i]->setFont(font);
    }

    {
        //geometry analog
        for(int i=0;i<3;i++)
            analog[i]->setGeometry(100,20+40*i,W_ANALOG,H_ANALOG);
        for(int i=3;i<6;i++)
            analog[i]->setGeometry(200,20+40*(i-3),W_ANALOG,H_ANALOG);
     }


     for(int i=0;i<15;i++){
         led[i] = new QLed(this);
        //led[i]->setFixedSize(55,25);

    }
     {
         for(int i=0;i<3;i++)
             led[i]->setGeometry(300,20+35*i,W_DISCRET,H_DISCRET);
         for(int i=3;i<6;i++)
             led[i]->setGeometry(350,20+35*(i-3),W_DISCRET,H_DISCRET);
         for(int i=6;i<9;i++)
             led[i]->setGeometry(400,20+35*(i-6),W_DISCRET,H_DISCRET);
         for(int i=9;i<12;i++)
             led[i]->setGeometry(450,20+35*(i-9),W_DISCRET,H_DISCRET);
         for(int i=12;i<15;i++)
             led[i]->setGeometry(10,20+35*(i-12),W_DISCRET,H_DISCRET);
}

//     for(int i=0;i<8;i++){

//         analog_lab[i] = new QLabel(this);
//     }
//     {
//         for(int i=0;i<3;i++)
//             analog_lab[i]->setGeometry(120,40*i,W_LABEL,H_LABEL);
//         for(int i=3;i<6;i++)
//             analog_lab[i]->setGeometry(220,40*(i-3),W_LABEL,H_LABEL);


//     }

    this->setFixedSize(580,200);

}


void outWidget:: set_analog(unsigned int number, float value,int mode ){

    if(mode ==1)
        analog[number] ->setText(prefix[number]+QString::number(value,'f',1));
    else if(mode ==2)
        analog[number]->setText(prefix[number]+QString::number(value,'e',2));
    else if(mode==3)
        analog[number]->setText(prefix[number]+QString ::number(value,'f',3));
    else if (mode==4)
        analog[number]->setText(prefix[number]+QString::number(value,'f',2));
    else{
        QString str = prefix[number]+ QString::number(value,'f',0);
        if(value <0)
            analog[number] ->setText(QString("%1").arg(str));//,10,'f',0));//,'f',0));
        else
            analog[number]->setText(QString(" %1").arg(str));//,'f',0))
    }
}


void outWidget::set_discret(unsigned int number ,bool toogle){
      if(number <15)
          led[number]->setLed(toogle);
}

void outWidget::clean(){

    for(int i=0;i<6;i++)
        analog[i]->clear();
    for(int i=0;i<14;i++)
          led[i]->setLed(0);


}


outWidget::~outWidget()
{
}
