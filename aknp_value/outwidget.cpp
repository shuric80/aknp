#include "outwidget.h"

outWidget::outWidget(QWidget *parent) :
    QWidget(parent){

    QFont font("Monospace");
    font.setPixelSize(9);
    this->setFont(font);

    main_layout = new QHBoxLayout;
    QVBoxLayout *lay[6];

    analog_layout =new QGridLayout;
    left_layout = new QVBoxLayout;

    for(int i=12;i<15;i++)
        left_layout ->addWidget(led[i] = new QLed);

    left_layout->addStretch(1);

    for(int i=0;i<6;i++){

        lay[i] = new  QVBoxLayout;
        lay[i] ->addStretch(1);
        lay[i]->addWidget(analog_lab[i] = new QLabel);
       // analog_lab[i]->setFixedSize(40,20);
        lay[i]->addStretch(1);
        lay[i]->addWidget(analog[i] = new QLineEdit);
        analog[i]->setFocusPolicy(Qt::NoFocus);

    }

    for(int i=0;i<6;i++){

        analog_layout->addLayout(lay[i],setPosX(i),setPosY(i));
    }

    discret_layout = new QGridLayout;

    for(int i=0;i<12;i++){

        discret_layout->addWidget(led[i] =new QLed,setPosX(i),setPosY(i));
    }

    for(int i=0;i<6;i++){

        analog[i]->setMaxLength(9);
        analog[i]->setFixedSize(64,20);
        analog[i]->setReadOnly(true);
}

    for(int i=0;i<15;i++){
        led[i]->setFixedSize(55,25);

    }

   // main_layout->addStretch(1);
    main_layout->addLayout(left_layout);
    main_layout->addLayout(analog_layout);
    main_layout->addSpacing(10);
    main_layout->addLayout(discret_layout);

    this->setLayout(main_layout);

}

int outWidget::setPosX(int n){

    if(n<3)
        return n;
    else if( n<6)
        return n-3;
    else if(n<9)
        return n-6;
    else
        return n-9;
}
int outWidget::setPosY(int n){

    if(n<3)
        return 0;
    else if(n<6)
        return 1;
    else if(n<9)
        return 2;
    else
        return 3;
}


void outWidget:: set_analog(unsigned int number, float value,int mode ){

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
    for(int i=0;i<14;i++)
        led[i]->setLed(0);


}


outWidget::~outWidget()
{
}
