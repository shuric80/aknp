#include "outwidget.h"
#define W_ANALOG 70
#define H_ANALOG 30
#define W_DISCRET 55
#define H_DISCRET 25
#define H_LABEL 20
#define W_LABEL 40

#define SPACE  25

outWidget::outWidget(QWidget *parent) :
    QWidget(parent){

    QFont font("Monospace",9);
    //font.setPixelSize(11);
    this->setFont(font);

    QFont font_led("Monospace");
    font_led.setPixelSize(9);

    for(int i=0;i<6;i++){
        analog[i] = new QLineEdit(this);
        analog[i]->setMaxLength(9);
        analog[i]->setReadOnly(true);
    }

    {
        //geometry analog
        for(int i=0;i<3;i++)
            analog[i]->setGeometry(100,20+40*i,W_ANALOG,H_ANALOG);
        for(int i=3;i<6;i++)
            analog[i]->setGeometry(230,20+40*(i-3),W_ANALOG,H_ANALOG);
     }

     for(int i=0;i<15;i++){
         led[i] = new QLed(this);
         led[i]->setFont(font_led);

    }
     {
         for(int i=0;i<3;i++)
             led[i]->setGeometry(320,20+30*i,W_DISCRET,H_DISCRET);
         for(int i=3;i<6;i++)
             led[i]->setGeometry(370,20+30*(i-3),W_DISCRET,H_DISCRET);
         for(int i=6;i<9;i++)
             led[i]->setGeometry(420,20+30*(i-6),W_DISCRET,H_DISCRET);
         for(int i=9;i<12;i++)
             led[i]->setGeometry(470,20+30*(i-9),W_DISCRET,H_DISCRET);
         for(int i=12;i<15;i++)
             led[i]->setGeometry(0,20+30*(i-12),W_DISCRET,H_DISCRET);
}

     for(int i=0;i<8;i++){

         analog_lab[i] = new QLabel(this);
         analog_lab[i]->setFont(font_led);
     }
     {
         for(int i=0;i<3;i++)
             analog_lab[i]->setGeometry(60,50*i+20,W_LABEL,H_LABEL);
         for(int i=3;i<6;i++)
             analog_lab[i]->setGeometry(180,50*(i-3)+20,W_LABEL,H_LABEL);
     }

    this->setFixedSize(650,200);

   this->err = 1;
}

void outWidget:: set_analog(unsigned int number, float value,int mode ){

    this->err = 0;

    if(mode ==1)
        analog[number] ->setText(QString(" ") +QString::number(value,'f',1));
    else if(mode ==2)
        analog[number]->setText(QString(" ") +QString::number(value,'e',2));
    else if(mode==3)
        analog[number]->setText(QString(" ") + QString ::number(value,'f',3));
    else if (mode==4)
        analog[number]->setText(QString(" ")+ QString::number(value,'f',2));
    else{
        QString str = QString::number(value,'f',0);
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

     this->err = 1;
}

outWidget::~outWidget()
{
}
