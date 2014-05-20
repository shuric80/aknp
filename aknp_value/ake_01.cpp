#include "ake_01.h"

#define WIDTH 180
#define HEIGHT 40
#include <QDebug>

ake_01::ake_01(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout *hlayout[10];
    QVBoxLayout *layout = new QVBoxLayout;


    for(int i=0;i<10;i++)
        layout->addLayout(hlayout[i] = new QHBoxLayout);

    for(int i =0;i<8;i++){
        hlayout[i]->addWidget(label[i][0] = new QLabel);
        hlayout[i]->addWidget(lineEdit[i][0] = new QLineEdit);

        hlayout[i]->addSpacing(60);

        hlayout[i]->addWidget(label[i][1] = new QLabel);
        hlayout[i]->addWidget(lineEdit[i][1] = new QLineEdit);
    }

    hlayout[8]->addWidget(label[8][0] = new QLabel);
    hlayout[8] -> addWidget(lineEdit[8][0] = new QLineEdit);

    hlayout[9]->addWidget(label[8][1] = new QLabel);
    hlayout[9]->addWidget(lineEdit[8][1] = new QLineEdit);

    for(int i=0;i<9;i++){
        lineEdit[i][0] ->setReadOnly(true);
        lineEdit[i][0]->setFocusPolicy(Qt::NoFocus);

        lineEdit[i][1] ->setReadOnly(true);
        lineEdit[i][1]->setFocusPolicy(Qt::NoFocus);


        label[i][0]->setFixedWidth(70);
        label[i][1]->setFixedWidth(70);
    }


    {
        label[0][1]->setText(QString(" Nk, %"));
        label[5][1]->setText(QString(" Ftx2, Гц"));
        label[4][1]->setText(QString(" Ftx1, Гц"));
        label[6][0] ->setText(QString(" Fн, Гц"));
        label[4][0] ->setText(QString(" Fв, Гц"));
        label[5][0] ->setText(QString(" Fc, Гц"));
        label[7][0]-> setText(QString(" Fкор, Гц"));
        label[1][1]->setText(QString(" N, %"));
        label[8][0] ->setText(QString(" AO"));
        label[8][1]->setText(QString(" Kz"));

        label[6][1]->setText(QString(" T1, %1С 1").arg(QChar(0x00b0)));
        label[7][1]->setText(QString(" T2, %1С 0").arg(QChar(0x00b0)));
        label[0][0] ->setText(QString(" Tвх, %1C").arg(QChar(0x00b0)));
        label[1][0] ->setText(QString(" H10, см"));
        label[2][0] ->setText(QString(" H9, см"));
        label[3][0] ->setText(QString(" H8, см"));
        label[2][1] ->setText(QString(" Kk"));
    }

    QHBoxLayout *topLayout = new QHBoxLayout;

    topLayout->addStretch(1);
    topLayout->addLayout(layout);


    this->setLayout(topLayout);

    // set style
    //  this->err=1;
}

void ake_01::selectId(int id, const QVector<int> &data){

    QVector<int> data_01;
    QVector<int> data_02;
    QVector<int> data_03;
    QVector<int> data_04;

    data_01 << data.mid(0,2);
    data_02 << data.mid(2,2);
    data_03 << data.mid(4,2);
    data_04 << data.mid(6,2);

    QVector <int> dataFl;
    QVector <int> dataFh;

    dataFl << data.mid(0,4);
    dataFh << data.mid(4,4);

    switch(id){

    case 0x401:
        lineEdit[0][1]->setText(QString("%1").arg(toFloat(dataFl),0,'f',2));
        break;
    case 0x402:
        lineEdit[5][1]->setText(QString("%1").arg(toInt(data_01)*10));
        lineEdit[4][1]->setText(QString("%1").arg(toInt(data_03)*10));
        break;
    case 0x403:
        lineEdit[6][0] ->setText(QString("%1").arg(toInt(data_01)*11.111));
        lineEdit[4][0] ->setText(QString("%1").arg(toInt(data_02)*11.111));
        lineEdit[5][0] ->setText(QString("%1").arg(toInt(data_03)*11.111));
        lineEdit[7][0]-> setText(QString("%1").arg(toInt(data_04)*11.111));
        break;
    case 0x405:
        lineEdit[1][1]->setText(QString("%1").arg(toFloat(dataFh),0,'f',2));
        lineEdit[8][0] ->setText(QString("%1").arg(toFloat(dataFl),0,'f',3));
        break;

    case 0x406:
        lineEdit[8][1]->setText(QString("%1 %2  %3  %4  %5  %6  %7  %8  %9")
                                .arg(data.at(0)*0.01,0, 'f', 2)
                                .arg(data.at(1)*0.01,0, 'f', 2)
                                .arg(data.at(2)*0.01,0, 'f', 2)
                                .arg(data.at(3)*0.01,0, 'f', 2)
                                .arg(data.at(4)*0.01,0, 'f', 2)
                                .arg(data.at(5)*0.01,0,'f',2)
                                .arg(data.at(6)*0.01,0,'f',2)
                                .arg(data.at(7)*0.01,0,'f',2).arg(Kz));
        break;
    case 0x407:
        Kz = QString("%1  %2").arg(data.at(0)*0.01,0,'g',3).arg(data.at(2)*0.01,0,'g',3);
        break;

    case 0x408:
        lineEdit[6][1]->setText(QString("%1").arg(toInt(data_03)*0.01));
        lineEdit[7][1]->setText(QString("%1").arg(toInt(data_04)*0.01));
        break;

    case 0x409:
        lineEdit[0][0] ->setText(QString("%1").arg((int)(toInt(data_01)*0.01)));
        lineEdit[1][0] ->setText(QString("%1").arg((int)(toInt(data_02)*0.01)));
        lineEdit[2][0] ->setText(QString("%1").arg((int)(toInt(data_03)*0.01)));
        lineEdit[3][0] ->setText(QString("%1").arg((int)(toInt(data_04)*0.01)));
        break;

    case 0x40A:
        lineEdit[2][1] ->setText(QString("%1").arg(toFloat(dataFl),0,'f',4));
        break;

    default:
        break;
    }
}

int ake_01::toInt(const QVector<int> &data){

    int I = data.at(1) <<8 | data.at(0);

    return I;
}

float ake_01::toFloat(const QVector<int> &data){

    float f;
    quint8 *str = (quint8*) &f;
    str[0] = data.at(0);
    str[1] = data.at(1);
    str[2] = data.at(2);
    str[3] = data.at(3);

    return f;
}


