#include "privod.h"
#include <QLocale>
#include <QStyle>

PrivodImit::PrivodImit(int canal, QWidget *parent) : QWidget(parent)
{
    QLocale::setDefault(QLocale::C);
    this->setLocale(QLocale::C);



    freqBox = new QDoubleSpinBox;
    stepBox = new QDoubleSpinBox;
    privBox = new QSpinBox;
    plusButton = new QPushButton;
    minusButton = new QPushButton;


    QLabel *privodLabel =new QLabel;
    QLabel *freqLabel =new QLabel;
    QLabel *stepLabel =new QLabel;

    QString style = QString("background-color:lightgrey;\
                            color:dark; padding:0px;\
border:0px");

    minusButton->setFixedHeight(25);
    plusButton->setFixedHeight(25);

    //freqLabel->setStyleSheet(style);
    //stepLabel->setStyleSheet(style);
    QHBoxLayout *privLayout = new QHBoxLayout;
    QHBoxLayout *freqLayout = new QHBoxLayout;
    QHBoxLayout *stepLayout =new QHBoxLayout;
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QVBoxLayout *mainLayout = new QVBoxLayout;

    privLayout->addWidget(privodLabel);
    privLayout->addWidget(privBox);

    freqLayout->addWidget(freqLabel);
    freqLayout->addWidget(freqBox);
    stepLayout->addWidget(stepLabel);
    stepLayout->addWidget(stepBox);

    buttonLayout ->addWidget(minusButton);
    buttonLayout->addWidget(plusButton);

    mainLayout->addLayout(privLayout);
    mainLayout->addLayout(freqLayout);
    mainLayout->addLayout(stepLayout);
    mainLayout->addLayout(buttonLayout);

    this->canal = canal;
    freqBox->setMaximum(MAX_FREQ);
    stepBox->setMaximum(MAX_STEP);

    privodLabel->setText("H");
    freqLabel->setText("Частота(F), Гц");
    stepLabel->setText(QString("Шаг изм. F(%1F),%").arg(QChar(0x03B4)));
    plusButton->setText(QString("+%1F").arg(QChar(0x03B4)));
    minusButton->setText(QString("-%1F").arg(QChar(0x03B4)));

    freqBox->setValue(0.1);
    stepBox ->setValue(10.00);

    connect(plusButton,SIGNAL(clicked()),this,SLOT(plusFreq()));
    connect(minusButton,SIGNAL(clicked()),this,SLOT(minusFreq()));
    connect(freqBox,SIGNAL(editingFinished()),this,SLOT(start()));
    connect(freqBox,SIGNAL(editingFinished()),stepBox,SLOT(setFocus()));
    connect(privBox,SIGNAL(valueChanged(int)),SLOT(slotPrivod()));

    plusButton->setAutoRepeat(true);
    minusButton->setAutoRepeat(true);

    plusButton->setAutoRepeatInterval(500);
    minusButton->setAutoRepeatInterval(500);

    privBox->setRange(0,255);
    privBox->setValue(181);

    this->setLayout(mainLayout);


    start_freq =0.1;
    step =10.0;
    freq =0.1;

   //this->setFixedWidth(150);
}

void PrivodImit::plusFreq(){

    step = stepBox->value();
    
    freq = freq+(freq*step*0.01);

    if(freq >= MAX_FREQ)
        freq = MAX_FREQ;
    if(freq ==0)
        freq = 0;

    freqBox->setValue(freq);

    emit setFreq(canal,freq);
}

void PrivodImit::minusFreq(){

    step = stepBox->value();
    freq = freq-(step*0.01*freq);

    if(freq <= 0)
        freq = 0;

    freqBox->setValue(freq);
    emit setFreq(canal,freq);
}

void PrivodImit::start(){

    freq = freqBox->value();
    start_freq = freq;

    emit setFreq(canal, freq);
}

void PrivodImit::slotPrivod(){

    int pv = privBox->value();
    if(pv == 182)
      privBox->setValue(255);
    else if(pv == 254 )
      privBox->setValue(181);
    else if((182 < pv) & (pv <254)){
      privBox ->setStyleSheet("background-color:pink");
      //btnMinus->setEnabled(false);
      //btnPlus->setEnabled(false);
     }
    else{
      privBox->setStyleSheet("background-color:white");
      //btnPlus->setEnabled(true);
      //btnMinus->setEnabled(true);
     }

    //send
    int data = privBox->value();
    //emit sgnlSetValue(data);
}



