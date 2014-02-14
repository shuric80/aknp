#include "qled.h"

QLed::QLed(QWidget *parent) :
    QWidget(parent){

   // this->setMinimumSize(50,5);
    this->str ="test";
    this->on =0x0f0f0f;
    this->off=0xf0f0f0;
    this->set=false;
}

void QLed::setLed(bool on){
  if(!set == on){
    this -> set = on;
    this->update();
   }
  else {}
}

void QLed::setText(QString str){
    this->str =QString(" %1").arg(str);
}

void QLed::setColor(QString color){

    if(color == QString("red")){
        on = 0xff0000;
        off =0x800000 ;
    }
    else if(color == QString ("green")){
        on  = 0x00ff00;
        off = 0x008000;
    }
    else if(color == QString("yellow")){
        on = 0xffff00;
        off= 0x808000;
    }
    else {
        on =  0x000000;
        off = 0xffffff;
    }

}

void QLed::paintEvent(QPaintEvent *){

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setWindow(0,0,25,18);
    QRadialGradient gradient(2,3,20);
    gradient.setColorAt(0,Qt::white);

    set ?   gradient.setColorAt(0.05,on)
             :gradient.setColorAt(0.05,Qt::gray);

    painter.setPen(QPen(Qt::black,1,Qt::SolidLine,Qt::RoundCap));
    painter.setBrush(gradient);
    painter.drawRoundRect(0,0,20,15);
    QPainter test(this);
    test.setPen(Qt::black);
    test.drawText(-10,-10,60,40, Qt::AlignCenter ,str);
  }
