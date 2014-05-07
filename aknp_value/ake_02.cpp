#include "ake_02.h"
#define WIDTH 180
#define HEIGHT 40
#include <QDebug>

ake_02::ake_02(QWidget *parent) :
    QWidget(parent)
{

    QHBoxLayout *hlayout[10];
    QVBoxLayout *topLayout = new QVBoxLayout;
    QString style = QString("background-color:rgb(200,200,200);color:rgb(0,0,0);\
                            padding:0px;border-radius:10px");
    QFont font("Monospace",12);
   // this->setFont(font);

    for(int i=0;i<8;i++){
        topLayout->addLayout(hlayout[i] = new QHBoxLayout);
        hlayout[i]->addWidget(label[i][0] = new QLabel);
        hlayout[i]->addWidget(label[i][1] = new QLabel);
        hlayout[i]->addStretch(1);

    //    label[i][0]->setStyleSheet(style);

    }

    topLayout->addLayout(hlayout[8] = new QHBoxLayout);
    topLayout->addLayout(hlayout[9] = new QHBoxLayout);


    hlayout[8]->addWidget(label[8][1] = new QLabel);
    hlayout[8]->addStretch(1);


    hlayout[9]->addWidget(label[9][1] = new QLabel);
     hlayout[9]->addStretch(1);

    str[4][1] = QString(" Nh = %1");




    for(int i=0;i<8;i++){
        for(int j=0;j<2;j++){
            //label[i][j]->setText(str[i][j]);
            label[i][j]->setFixedSize(WIDTH,HEIGHT);
            label[i][j]->setFont(font);
              label[i][j]->setStyleSheet(style);

        }
        for(int i=8;i<=9;i++){
            label[i][1]->setFont(font);
            label[i][1]->setFixedSize(WIDTH,HEIGHT);
            label[i][1]->setStyleSheet(style);
        }
    }
    this->setLayout(topLayout);

    {
        label[8][1] ->setText(QString(" Fнкор = %1").arg(0));
        label[9][1] ->setText(QString(" Fккор = %1").arg(0));
        label[7][1] ->setText(QString(" %1kf0 = %2").arg(QChar(0x03B1)).arg(0));
        label[0][0] ->setText(QString(" %1t = %2").arg(QChar(0x03B1)).arg(0));
        label[1][0] ->setText(QString(" %1h = %2").arg(QChar(0x03B1)).arg(0));
        label[2][0] ->setText(QString(" %1w = %2").arg(QChar(0x03B1)).arg(0));
        label[2][1] ->setText(QString(" %1d = %2").arg(QChar(0x03B1)).arg(0));
        label[0][1] ->setText(QString(" Q2 = %1").arg(0));
        label[1][1] ->setText(QString(" Q3 = %1").arg(0));
        label[3][0] ->setText(QString(" %1%2 = %3").arg(QChar(0x03B1)).arg(QChar(0x0033)).arg(0));
        label[3][1] ->setText(QString(" %1%2* = %3").arg(QChar(0x03B1)).arg(QChar(0x0033)).arg(0));
        label[4][0] ->setText(QString(" Nh1 = %1").arg(0));
        label[5][0] ->setText(QString(" Nh1_2 = %1").arg(0));
        label[6][0] ->setText(QString(" Nh1_3 = %1").arg(0));
        label[7][0] ->setText(QString(" Nh1_1 = %1").arg(0));
        label[6][1] ->setText(QString(" Tэфф = %1 дней").arg(0));
        label[5][1] ->setText(QString(" Tkf = %1 дня").arg(0));

    }

}

void ake_02::selectId(const QVector<int> &data){

    int id = data.at(0);
    QVector<int> data_01;
    QVector<int> data_02;
    QVector<int> data_03;
    QVector<int> data_04;

    data_01 = data.mid(1,2);
    data_02 = data.mid(3,2);
    data_03 = data.mid(5,2);
    data_04 = data.mid(7,2);

    QVector <int> dataFl;
    QVector <int> dataFh;

    dataFl = data.mid(1,4);
    dataFh = data.mid(5,4);

    switch(id){
    case 0x404:
        label[8][1] ->setText(QString(" Fнкор = %1").arg(toInt(data_01)*1.1111));
        label[9][1] ->setText(QString(" Fккор = %1").arg(toInt(data_02)*1.1111));
        break;

    case 0x40A:
        label[7][1] ->setText(QString(" %1kf0 = %2").arg(QChar(0x03B1)).arg(toFloat(dataFl),0,'g',3));
        break;

    case 0x40B:
        label[0][0] ->setText(QString(" %1t = %2").arg(QChar(0x03B1)).arg(toFloat(dataFh),0,'g',3));
        label[1][0] ->setText(QString(" %1h = %2").arg(QChar(0x03B1)).arg(toFloat(dataFl),0,'g',3));
        break;

    case 0x40C:
        label[2][0] ->setText(QString(" %1w = %2").arg(QChar(0x03B1)).arg(toFloat(dataFh),0,'g',3));
        label[2][1] ->setText(QString(" %1d = %2").arg(QChar(0x03B1)).arg(toFloat(dataFl),0,'g',3));
        break;

    case 0x40d:
        //qDebug()<< hex << data;
        label[0][1] ->setText(QString(" Q2 = %1").arg(toFloat(dataFl),0,'g',3));
        label[1][1] ->setText(QString(" Q3 = %1").arg(toFloat(dataFh),0,'g',3));
        break;

    case 0x40E:
        label[3][0]->setText(QString(" %1%2 = %3").arg(QChar(0x03B1)).arg(QChar(0x0033)).arg(toFloat(dataFh),0,'g',3));
        break;

    case 0x40F:
        label[3][1] ->setText(QString(" %1%2* = %3").arg(QChar(0x03B1)).arg(QChar(0x0033)).arg(toFloat(dataFh),0,'g',3));
        break;

    case 0x407:
        label[4][0] ->setText(QString(" Nh1 = %1").arg(data.at(6)));
        label[5][0] ->setText(QString(" Nh1_2 = %1").arg(data.at(4)));
        label[6][0] ->setText(QString(" Nh1_3 = %1").arg(data.at(5)));
        label[7][0] ->setText(QString(" Nh1_1 = %1").arg(data.at(3)));
        break;

    case 0x408:
        label[6][1] ->setText(QString(" Tэфф = %1 дней").arg(toInt(data_01)));
        label[5][1] ->setText(QString(" Tkf = %1 дня").arg(toInt(data_02)));
        break;

    default:
        break;
    }

}

int ake_02::toInt(const QVector<int> &data){

    int I = data.at(1) <<8 | data.at(0);

    return I;
}

float ake_02::toFloat(const QVector<int> &data){

    float f;
    quint8 *str = (quint8*) &f;
    str[0] = data.at(0);
    str[1] = data.at(1);
    str[2] = data.at(2);
    str[3] = data.at(3);

    return f;

}
