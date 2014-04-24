#include "ake_01.h"

#define WIDTH 180
#define HEIGHT 40
#include <QDebug>

ake_01::ake_01(QWidget *parent) :
  QWidget(parent)
{
  QHBoxLayout *hlayout[8];
  QVBoxLayout *layout = new QVBoxLayout;

  QFont font("Arial Cyr",12);

  QString style = QString("background-color:rgb(100,100,100);color:rgb(250,250,250);\
                          padding:0px;border-radius:10px");
  
  for(int i=0;i<8;i++){
    layout->addLayout(hlayout[i] = new QHBoxLayout);
    hlayout[i]->addWidget(label[i][0] = new QLabel);
    hlayout[i]->addWidget(label[i][1] = new QLabel);
    hlayout[i]->addStretch(1);
    label[i][0]->setStyleSheet(style);
    label[i][1]->setStyleSheet(style);
  }

  layout->addWidget(label[8][0] = new QLabel);
  layout->addWidget(label[8][1] = new QLabel);
  layout->addWidget(label[9][1] = new QLabel);

  for(int i=0;i<8;i++){
	for(int j=0;j<2;j++){

      label[i][j]->setFixedSize(WIDTH,HEIGHT);
      //label[i][j]->setFrameStyle(6);
      label[i][j]->setFont(font);
	}

    label[8][0]->setFixedSize(WIDTH,HEIGHT);
    label[8][1]->setFixedSize(2*WIDTH,HEIGHT);
    label[9][1]->setFixedSize(2*WIDTH,HEIGHT);

    label[8][0]->setFont(font);
    label[8][1]->setFont(font);
    label[9][1]->setFont(font);


    label[8][0]->setStyleSheet(style);
    label[8][1]->setStyleSheet(style);
    label[9][1]->setStyleSheet(style);
}

 {
          label[0][1]->setText(QString(" Nk = %1 %").arg(00.0));
          label[5][1]->setText(QString(" Ftx2 = %1 Гц").arg(0));
          label[4][1]->setText(QString(" Ftx1 = %1 Гц").arg(0));
          label[6][0] ->setText(QString(" Fн = %1 Гц").arg(0));
          label[4][0] ->setText(QString(" Fв = %1 Гц").arg(0));
          label[5][0] ->setText(QString(" Fc = %1 Гц").arg(0));
          label[7][0]-> setText(QString(" Fкор = %1 Гц").arg(0));
          label[1][1]->setText(QString(" N = %1 %").arg(0));
          label[8][0] ->setText(QString(" AO = %1").arg(0));
          label[8][1]->setText(QString(" Kz = %1 %2 %3 %4 %5")
                               .arg(0)
                               .arg(0)
                               .arg(0)
                               .arg(0)
                               .arg(0));

          label[9][1]->setText(QString("          %1 %2 %3 %4 ")
                               .arg(0)
                               .arg(0)
                               .arg(0)
                               .arg(0));

          label[6][1]->setText(QString(" T1 = %2 %1С 1").arg(QChar(0x00b0)).arg(0));
          label[7][1]->setText(QString(" T2 = %2 %1С 0").arg(QChar(0x00b0)).arg(0));
          label[0][0] ->setText(QString(" Tвх = %2 %1C").arg(QChar(0x00b0)).arg(0));
          label[1][0] ->setText(QString(" H10 = %1 см").arg(0));
          label[2][0] ->setText(QString(" H9 = %1 см").arg(0));
          label[3][0] ->setText(QString(" H8 = %1 см").arg(0));
          label[2][1] ->setText(QString(" Kk = %1").arg(0));

  }

  /*QVBoxLayout *akeLayout = new QVBoxLayout;
  {
      for(int i=0;i<4;i++)
          akeLayout->addWidget(ake_imit[i] = new AkeSlideImitator);

  }

*/
  QHBoxLayout *topLayout = new QHBoxLayout;
//  topLayout->addLayout(akeLayout);
  topLayout->addLayout(layout);
  this->setLayout(topLayout);
  // set style
 //  this->err=1;
}

void ake_01::selectId(const QVector<int> &data){



    int id = data.at(0);
    QVector<int> data_01;
    QVector<int> data_02;
    QVector<int> data_03;
    QVector<int> data_04;

    data_01 << data.mid(1,2);
    data_02 << data.mid(3,2);
    data_03 << data.mid(5,2);
    data_04 << data.mid(7,2);

    QVector <int> dataFl;
    QVector <int> dataFh;

    dataFl << data.mid(1,4);
    dataFh << data.mid(5,4);


    switch(id){

    case 0x401:
        label[0][1]->setText(QString(" Nk = %1 %").arg(toFloat(dataFl),0,'f',2));
        break;
    case 0x402:
        label[5][1]->setText(QString(" Ftx2 = %1 Гц").arg(toInt(data_01)*10));
        label[4][1]->setText(QString(" Ftx1 = %1 Гц").arg(toInt(data_03)*10));
        break;
    case 0x403:
        label[6][0] ->setText(QString(" Fн = %1 Гц").arg(toInt(data_01)*11.111));
        label[4][0] ->setText(QString(" Fв = %1 Гц").arg(toInt(data_02)*11.111));
        label[5][0] ->setText(QString(" Fc = %1 Гц").arg(toInt(data_03)*11.111));
        label[7][0]-> setText(QString(" Fкор = %1 Гц").arg(toInt(data_04)*11.111));
        break;
     case 0x405:
        label[1][1]->setText(QString(" N = %1 %").arg(toFloat(dataFh),0,'f',2));
        label[8][0] ->setText(QString(" AO = %1").arg(toFloat(dataFl),0,'f',3));
        break;

     case 0x406:
        label[8][1]->setText(QString(" Kz = %1 %2 %3 %4 %5")
                             .arg(data.at(1)*0.01,0, 'f', 2)
                             .arg(data.at(2)*0.01,0, 'f', 2)
                             .arg(data.at(3)*0.01,0, 'f', 2)
                             .arg(data.at(4)*0.01,0, 'f', 2)
                             .arg(data.at(5)*0.01,0, 'f', 2));

        label[9][1]->setText(QString("          %1 %2 %3 %4")
                             .arg(data.at(6)*0.01,0,'f',2)
                             .arg(data.at(7)*0.01,0,'f',2)
                             .arg(data.at(8)*0.01,0,'f',2).arg(Kz));
        break;
     case 0x407:
        Kz = QString(" %1 %2").arg(data.at(1)*0.01,0,'g',3).arg(data.at(2)*0.01,0,'g',3);
        break;

     case 0x408:
        label[6][1]->setText(QString(" T1 = %2 %1С 1").arg(QChar(0x00b0)).arg(toInt(data_03)*0.01));
        label[7][1]->setText(QString(" T2 = %2 %1С 0").arg(QChar(0x00b0)).arg(toInt(data_04)*0.01));
        break;

      case 0x409:
        label[0][0] ->setText(QString(" Tвх = %2 %1C").arg(QChar(0x00b0)).arg(toInt(data_01)*0.01));
        label[1][0] ->setText(QString(" H10 = %1 см").arg(toInt(data_02)*0.01));
        label[2][0] ->setText(QString(" H9 = %1 см").arg(toInt(data_03)*0.01));
        label[3][0] ->setText(QString(" H8 = %1 см").arg(toInt(data_04)*0.01));
        break;

    case 0x40A:
        label[2][1] ->setText(QString(" Kk = %1").arg(toFloat(dataFl),0,'f',4));
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


