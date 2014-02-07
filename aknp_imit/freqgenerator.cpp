#include "freqgenerator.h"
#include <QLocale>
#include <QStyle>

FreqGenerator::FreqGenerator(int canal, QWidget *parent) : QWidget(parent)
{
    QLocale::setDefault(QLocale::C);
    this->setLocale(QLocale::C);

    QString style = QString("color:white");


    QString style_0 = QString("border-width: 2px;\
                              border-radius: 4px;\
            padding: 6px;\
    border-style: outset;\
    background-color:rgb(120,120,120);\
    border-color:grey;\
    text-align:center;\
    color:white;\
    selection-background-color:white;\
    selection-color:black");

    QString style_tst= QString("background-color: grey;\
    border-style: outset;\
    border-width: 2px;\
    border-radius: 4px;\
    border-color: beige;\
    font: bold 14px;\
    min-width: 10em;\
    padding: 6px"
    );

   // this->setStyleSheet("QPushButton#minusButton:pressed {background-color: rgb(224, 0, 0)}");


    freqBox = new QDoubleSpinBox;
    stepBox = new QDoubleSpinBox;
    plusButton = new QPushButton;
    minusButton = new QPushButton;
//
  // freqBox->setStyleSheet(style);
  //  stepBox->setStyleSheet(style);
  //  plusButton->setStyleSheet(style);
   // minusButton->setStyleSheet(style);

    QLabel *freqLabel =new QLabel;
    QLabel *stepLabel =new QLabel;

    freqLabel->setStyleSheet(style);
    stepLabel->setStyleSheet(style);


    freqBox->setStyleSheet(style_0);
    stepBox->setStyleSheet(style_0);
    minusButton->setStyleSheet(style_tst);



    plusButton->setStyleSheet(style_tst);



    QHBoxLayout *freqLayout = new QHBoxLayout;
    QHBoxLayout *stepLayout =new QHBoxLayout;
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QVBoxLayout *mainLayout = new QVBoxLayout;


    freqLayout->addWidget(freqLabel);
    freqLayout->addWidget(freqBox);
    stepLayout->addWidget(stepLabel);
    stepLayout->addWidget(stepBox);

    buttonLayout ->addWidget(minusButton);
    buttonLayout->addWidget(plusButton);

    mainLayout->addLayout(freqLayout);
    mainLayout->addLayout(stepLayout);
    mainLayout->addLayout(buttonLayout);

    this->canal = canal;
    freqBox->setMaximum(MAX_FREQ);
    stepBox->setMaximum(MAX_STEP);

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

    plusButton->setAutoRepeat(true);
    minusButton->setAutoRepeat(true);

    this->setLayout(mainLayout);


    start_freq =0.1;
    step =10.0;
    freq =0.1;
}

void FreqGenerator::plusFreq(){

    step = stepBox->value();
    
    freq = freq+(freq*step*0.01);

    if(freq >= MAX_FREQ)
        freq = MAX_FREQ;
    if(freq ==0)
        freq = 0;

    freqBox->setValue(freq);

    emit setFreq(canal,freq);
}

void FreqGenerator::minusFreq(){

    step = stepBox->value();
    freq = freq-(step*0.01*freq);

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


