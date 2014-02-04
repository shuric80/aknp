#include "ake_01.h"

#define WIDTH 180
#define HEIGHT 40


ake_01::ake_01(QWidget *parent) :
  QWidget(parent)
{
  QHBoxLayout *hlayout[8];
  QVBoxLayout *topLayout = new QVBoxLayout;
  QString style = QString("border-width: 2px; border-radius: 10px; padding: 6 px; border-style: outset; background-color:rgb(80,80,80);border-color:grey;text-align:center;color:white");
  QFont font("Arial Cyr",14);
  
  for(int i=0;i<8;i++){
	topLayout->addLayout(hlayout[i] = new QHBoxLayout);
    hlayout[i]->addWidget(label[i][0] = new QLabel);
    hlayout[i]->addWidget(label[i][1] = new QLabel);
  }

  topLayout->addWidget(label[8][0] = new QLabel);
  topLayout->addWidget(label[8][1] = new QLabel);
  topLayout->addWidget(label[9][1] = new QLabel);

   
  {

	str[0][0] = QString(" Tвх = 000.0 %1C").arg(QChar(0x00b0));
	str[1][0] = QString(" H10 = %1 см");
	str[2][0] = QString(" H9 = %1 см");
	str[3][0] = QString(" H8 = %1 см");   
	str[4][0] = QString(" Fв = %1 Гц");
	str[5][0] = QString(" Fc = %1 Гц");
	str[6][0] = QString(" Fн = %1 Гц");
	str[7][0] = QString(" Fкор = %1 Гц");
	str[8][0] = QString(" AO = %1");

	str[0][1] = QString(" Nk = %1 %");
	str[1][1] = QString(" N = %1 %");
	str[2][1] = QString(" Kk = %1");
	str[3][1] = QString(" K = %1");
	str[4][1] = QString(" Ftx1 = %1 Гц");
	str[5][1] = QString(" Ftx2 = 00000 Гц");
	str[6][1] = QString(" T1 = %2 %1С 1").arg(QChar(0x00b0));
	str[7][1] = QString(" T2 = %2 %1С 0").arg(QChar(0x00b0));
	str[8][1] = QString(" Kz = %1");
  }

  for(int i=0;i<8;i++){
	for(int j=0;j<2;j++){
	  label[i][j]->setText(str[i][j]);
	  label[i][j]->setMaximumSize(WIDTH,HEIGHT);
	  label[i][j]->setStyleSheet(style);
      label[i][j]->setFont(font);
	}

	label[8][0]->setText(str[8][0]);
	label[8][1]->setText(str[8][1]);

	label[8][0]->setMaximumSize(WIDTH,HEIGHT);
    label[8][1]->setMaximumSize(2*WIDTH,HEIGHT);
	label[9][1]->setMaximumSize(2*WIDTH,HEIGHT);

    label[8][0]->setStyleSheet(style);
	label[8][1]->setStyleSheet(style);
	label[9][1]->setStyleSheet(style);
    label[8][0]->setFont(font);
    label[8][1]->setFont(font);
    label[9][1]->setFont(font);
 

}
   this->setStyleSheet("background-color:qlineargradient(x1: 0,y1: 0,x2: 0,y2: 1,stop: 0#aaaaaa,stop: 0.5 #434343, stop: 0.31 #000000, stop: 1 #585c5f)");
  this->setLayout(topLayout); 
}
