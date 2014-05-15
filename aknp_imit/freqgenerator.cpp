#include "freqgenerator.h"
#include <QLocale>
#include <QStyle>

FreqGenerator::FreqGenerator(int canal, QWidget *parent) : QWidget(parent)
{
  //  QLocale::setDefault(QLocale::C);
  //  this->setLocale(QLocale::C);

    freqBox = new QDoubleSpinBox;
    stepBox = new QDoubleSpinBox;
    stepPowerBox = new QDoubleSpinBox;

    plusButton = new QPushButton;
    minusButton = new QPushButton;

    selMode_0 = new QRadioButton;
    selMode_1 = new QRadioButton;


    QLabel *freqLabel =new QLabel;

    stepLabel =new QLabel;
    powLabel =new QLabel;

    QString style = QString("background-color:lightgrey;\
                            color:dark; padding:0px;\
border:0px");

    minusButton->setFixedHeight(35);
    plusButton->setFixedHeight(35);

    //freqLabel->setStyleSheet(style);
    //stepLabel->setStyleSheet(style);

    QHBoxLayout *freqLayout = new QHBoxLayout;
    QHBoxLayout *stepLayout =new QHBoxLayout;
    QHBoxLayout *powLayout = new QHBoxLayout;
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QVBoxLayout *mainLayout = new QVBoxLayout;


    freqLayout->addWidget(freqLabel);
    freqLayout->addWidget(freqBox);

    stepLayout->addWidget(selMode_1);
    stepLayout->addWidget(stepLabel);
    stepLayout->addStretch(1);
    stepLayout->addWidget(stepBox);

    powLayout->addWidget(selMode_0);

    powLayout->addWidget(powLabel);
      powLayout->addStretch(1);
    powLayout->addWidget(stepPowerBox);

    buttonLayout ->addWidget(minusButton);
    buttonLayout ->addWidget(plusButton);

    mainLayout->addLayout(freqLayout);
    mainLayout->addLayout(stepLayout);
    mainLayout->addLayout(powLayout);
    mainLayout->addLayout(buttonLayout);

    this->canal = canal;
    freqBox->setMaximum(MAX_FREQ);
    stepBox->setMaximum(MAX_STEP);
    stepPowerBox->setMaximum(MAX_STEP_POWER);
    stepPowerBox->setMinimum(0.1);
   // stepPowerBox->setL

    freqLabel->setText("Частота(F), Гц");
    stepLabel->setText(QString("Шаг F(%1F),%").arg(QChar(0x03B4)));
    powLabel->setText("Шаг F,Гц");

    plusButton->setText(QString("+%1F").arg(QChar(0x03B4)));
    minusButton->setText(QString("-%1F").arg(QChar(0x03B4)));

    freqBox->setValue(0.1);
    stepBox ->setValue(10.00);
    stepPowerBox->setRange(0.1,1000);

    connect(plusButton,SIGNAL(clicked()),this,SLOT(plusFreq()));
    connect(minusButton,SIGNAL(clicked()),this,SLOT(minusFreq()));
    connect(freqBox,SIGNAL(editingFinished()),this,SLOT(start()));
    connect(freqBox,SIGNAL(editingFinished()),stepBox,SLOT(setFocus()));

    connect(selMode_1,SIGNAL(toggled(bool)),this,SLOT(setMode(bool)));


    plusButton->setAutoRepeat(true);
    minusButton->setAutoRepeat(true);

    plusButton->setAutoRepeatInterval(500);
    minusButton->setAutoRepeatInterval(500);

   // stepPowerBox->setStyleSheet("background-color:rgb(160,160,160);color:grey; padding:0px;");
    //stepPowerBox->setDisabled(true);
    this->setLayout(mainLayout);


    start_freq =0.1;
    step =10.0;
    freq =0.1;

    setMode(false);
    selMode_0->setChecked(true); //default mode =true;
   //this->setFixedWidth(150);

}
void FreqGenerator::setMode(bool mode){

    powLabel->setDisabled(mode);
    stepPowerBox->setDisabled(mode);

    stepLabel->setDisabled(!mode);
    stepBox->setDisabled(!mode);

    this->mode = mode;

}


void FreqGenerator::plusFreq(){

    if(mode){
        step = stepBox->value();
        freq = freq+(freq*step*0.01);
    }
    else{
        step = stepPowerBox->value();
        freq = freq+step;
    }


    if(freq >= MAX_FREQ)
        freq = MAX_FREQ;
    if(freq ==0)
        freq = 0;

    freqBox->setValue(freq);

    emit setFreq(canal,freq);
}

void FreqGenerator::minusFreq(){
    if(mode){
    step = stepBox->value();
    freq = freq-(step*0.01*freq);
}
    else{
        step = stepPowerBox->value();
        freq = freq-step;
    }

    if(freq <= 0)
        freq = 0;

    freqBox->setValue(freq);
    emit setFreq(canal,freq);
}

void FreqGenerator::start(){

    freq = freqBox->value();
    start_freq = freq;

    emit setFreq(canal, freq);
}


