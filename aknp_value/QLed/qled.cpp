#include "qled.h"
#define  GREY   0x888888

QLed::QLed(QWidget *parent) :
    QWidget(parent){

    timer = new QTimer(this);
    timer->setInterval(500);
    connect(timer,SIGNAL(timeout()),this,SLOT(NoActive()));

   // this->setMinimumSize(50,5);
    this->str ="test";
    this->on =0x0f0f0f;
    this->off=0xf0f0f0;
    this->set=true;

    timer->start();
}

void QLed::setLed(bool on){

    off = this->colorOff;

    if(!set == on){
    this -> set = on;
    this->update();
   }
  else {}

  timer->stop();
  timer->start();

}

void QLed::setText(QString str){
    this->str =QString(" %1").arg(str);
}

void QLed::setColor(QString color){

    if(color == QString("R")){
        on = 0xff0000;
        off = GREY ;
    }
    else if(color == QString ("G")){
        on  = 0x00ff00;
        off = GREY;
    }
    else if(color == QString("Y")){
        on = 0xffff00;
        off= GREY;
    }
    else if(color == QString("RG")){
        on = 0x00ff00;
        off = 0xff0000;
    }

    else {
        on =  0x000000;
        off = 0xffffff;
    }

    this->colorOff = off;
}


void QLed::NoActive(){


    off = GREY;
    set = FALSE;

    this->update();
    timer->stop();

}

void QLed::paintEvent(QPaintEvent *){

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setWindow(0,0,25,18);
    QRadialGradient gradient(2,3,20);
    gradient.setColorAt(0,Qt::white);

    set ?   gradient.setColorAt(0.05,on)
             :gradient.setColorAt(0.05,off);

    painter.setPen(QPen(Qt::black,1,Qt::SolidLine,Qt::RoundCap));
    painter.setBrush(gradient);
    painter.drawRoundRect(0,0,20,15);
    QPainter test(this);
    test.setPen(Qt::black);
    test.drawText(-10,-10,60,40, Qt::AlignCenter ,str);
  }
