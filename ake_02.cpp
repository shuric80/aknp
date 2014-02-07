#include "ake_02.h"

#define WIDTH 180
#define HEIGHT 40

ake_02::ake_02(QWidget *parent) :
    QWidget(parent)
{

    QHBoxLayout *hlayout[10];
    QVBoxLayout *topLayout = new QVBoxLayout;

    QString style = QString("border-width:2px;\
                            border-radius: 10px;\
            padding: 6 px;\
            border-style: outset;\
            background-color:rgb(80,80,80);\
            border-color:grey;\
            text-align:center;\
            color:white");

            QFont font("Arial Cyr",14);

    for(int i=0;i<8;i++){
        topLayout->addLayout(hlayout[i] = new QHBoxLayout);
        hlayout[i]->addWidget(label[i][0] = new QLabel);
        hlayout[i]->addWidget(label[i][1] = new QLabel);
    }

    topLayout->addLayout(hlayout[8] = new QHBoxLayout);
    topLayout->addLayout(hlayout[9] = new QHBoxLayout);

    hlayout[8]->addStretch(1);
    hlayout[8]->addWidget(label[8][1] = new QLabel);

    hlayout[9]->addStretch(1);
    hlayout[9]->addWidget(label[9][1] = new QLabel);

    {
        str[0][0] = QString(" %1t = %2").arg(QChar(0x03B1));
        str[1][0] = QString(" %1h = %2").arg(QChar(0x03B1));
        str[2][0] = QString(" %1w = %2").arg(QChar(0x03B1));
        str[3][0] = QString(" %1%2 = %3").arg(QChar(0x03B1)).arg(QChar(0x0033));
        str[4][0] = QString(" Nh1 = %1");
        str[5][0] = QString(" Nh1_2 = %1");
        str[6][0] = QString(" Nh1_3 = %1");
        str[7][0] = QString(" Nh1_1 = %1");

        str[0][1] = QString(" Q2 = %1");
        str[1][1] = QString(" Q3 = %1");
        str[2][1] = QString(" %1d = %2").arg(QChar(0x03B1));
        str[3][1] = QString(" %1%2* = %4").arg(QChar(0x03B1)).arg(QChar(0x0033));
        str[4][1] = QString(" Nh = %1");
        str[5][1] = QString(" Tkf = %1 дня");
        str[6][1] = QString(" Tэфф = %1 дней");
        str[7][1] = QString(" %1kf0 = %2").arg(QChar(0x03B1));
        str[8][1] = QString(" Fнкор = %1");
        str[9][1] = QString(" Fккор = %1");
    }

    for(int i=0;i<8;i++){
        for(int j=0;j<2;j++){
            label[i][j]->setText(str[i][j]);
            label[i][j]->setMaximumSize(WIDTH,HEIGHT);
            label[i][j]->setStyleSheet(style);
            label[i][j]->setFont(font);
        }
        for(int i=8;i<=9;i++){
            label[i][1]->setText(str[i][1]);
            label[i][1]->setFixedHeight(HEIGHT);
            label[i][1]->setFixedWidth(WIDTH);

            label[i][1]->setStyleSheet(style);
            label[i][1]->setFont(font);
        }



    }
    // this->setStyleSheet("background-color:qlineargradient(x1: 0,y1: 0,x2: 0,y2: 1,stop: 0#aaaaaa,stop: 0.5 #434343, stop: 0.31 #000000, stop: 1 #585c5f)");
    this->setLayout(topLayout);
}
