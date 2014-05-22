#include "ake_02.h"
#define WIDTH 180
#define HEIGHT 40
#include <QDebug>

ake_02::ake_02(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout *hlayout[10];
    QVBoxLayout *layout = new QVBoxLayout;


    for(int i=0;i<10;i++)
        layout->addLayout(hlayout[i] = new QHBoxLayout);

    for(int i =0;i<9;i++){
        hlayout[i]->addWidget(label[i][0] = new QLabel);
        hlayout[i]->addWidget(lineEdit[i][0] = new QLineEdit);

        hlayout[i]->addSpacing(100);

        hlayout[i]->addWidget(label[i][1] = new QLabel);
        hlayout[i]->addWidget(lineEdit[i][1] = new QLineEdit);

    }

    for(int i=0;i<9;i++){

        lineEdit[i][0] ->setReadOnly(true);
        lineEdit[i][0]->setFocusPolicy(Qt::NoFocus);
        lineEdit[i][1] ->setReadOnly(true);
        lineEdit[i][1]->setFocusPolicy(Qt::NoFocus);


        label[i][0]->setFixedWidth(50);
        label[i][1]->setFixedWidth(50);
    }

    QHBoxLayout *topLayout = new QHBoxLayout;

    topLayout->addStretch(1);
    topLayout->addLayout(layout);

    this->setLayout(topLayout);

    {   label[8][0] ->setText(QString(" Fнкор"));
        label[8][1] ->setText(QString(" Fккор"));
        label[7][1] ->setText(QString(" %1kf0").arg(QChar(0x03B1)));
        label[0][0] ->setText(QString(" %1t").arg(QChar(0x03B1)));
        label[1][0] ->setText(QString(" %1h").arg(QChar(0x03B1)));
        label[2][0] ->setText(QString(" %1w").arg(QChar(0x03B1)));
        label[2][1] ->setText(QString(" %1d").arg(QChar(0x03B1)));
        label[0][1] ->setText(QString(" Q2"));
        label[1][1] ->setText(QString(" Q3"));
        label[3][0] ->setText(QString(" %1%2").arg(QChar(0x03B1)).arg(QChar(0x0033)));

        label[3][1] ->setText(QString(" %1%2*").arg(QChar(0x03B1)).arg(QChar(0x0033)));
        label[4][0] ->setText(QString(" Nh1"));

        label[5][0] ->setText(QString(" Nh1_2"));
        label[6][0] ->setText(QString(" Nh1_3"));
        label[7][0] ->setText(QString(" Nh1_1"));
        label[6][1] ->setText(QString(" Tэфф, дней"));
        label[5][1] ->setText(QString(" Tkf, дня"));
    }
}

void ake_02::selectId(int id,const QVector<int> &data){

    QVector<int> data_01;
    QVector<int> data_02;
    QVector<int> data_03;
    QVector<int> data_04;

    data_01 = data.mid(0,2);
    data_02 = data.mid(2,2);
    data_03 = data.mid(4,2);
    data_04 = data.mid(6,2);

    QVector <int> dataFl;
    QVector <int> dataFh;

    dataFl = data.mid(0,4);
    dataFh = data.mid(4,4);

    switch(id){
    case 0x404:
        lineEdit[8][1] ->setText(QString("%1").arg(toInt(data_01)*1.1111));
        lineEdit[8][0] ->setText(QString("%1").arg(toInt(data_02)*1.1111));
        break;

    case 0x40A:
        lineEdit[7][1] ->setText(QString(" %1").arg(toFloat(dataFl),0,'g',3));
        break;

    case 0x40B:
        lineEdit[0][0] ->setText(QString(" %1").arg(toFloat(dataFh),0,'g',3));
        lineEdit[1][0] ->setText(QString(" %1").arg(toFloat(dataFl),0,'g',3));
        break;

    case 0x40C:
        lineEdit[2][0] ->setText(QString(" %1").arg(toFloat(dataFh),0,'g',3));
        lineEdit[2][1] ->setText(QString(" %1").arg(toFloat(dataFl),0,'g',3));
        break;

    case 0x40d:
        //qDebug()<< hex << data;
        lineEdit[0][1] ->setText(QString(" %1").arg(toFloat(dataFl),0,'g',3));
        lineEdit[1][1] ->setText(QString(" %1").arg(toFloat(dataFh),0,'g',3));
        break;

    case 0x40E:
        lineEdit[3][0]->setText(QString(" %1").arg(toFloat(dataFh),0,'g',3));
        break;

    case 0x40F:
        lineEdit[3][1] ->setText(QString(" %1").arg(toFloat(dataFh),0,'g',3));
        break;

    case 0x407:
        lineEdit[4][0] ->setText(QString(" %1").arg(data.at(6)));
        lineEdit[5][0] ->setText(QString(" %1").arg(data.at(4)));
        lineEdit[6][0] ->setText(QString(" %1").arg(data.at(5)));
        lineEdit[7][0] ->setText(QString(" %1").arg(data.at(3)));
        break;

    case 0x408:
        lineEdit[6][1] ->setText(QString(" %1").arg(toInt(data_01)));
        lineEdit[5][1] ->setText(QString(" %1").arg(toInt(data_02)));
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
