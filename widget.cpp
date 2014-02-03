#include "widget.h"
#define WIDTH 160
#define HEIGHT 40

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
 
  QGridLayout *layout = new QGridLayout;
  QHBoxLayout *lbLayout[8];// = new QHBoxLayout;
  //  create label 10 - row 0,3
  for(int i=0;i<10;i++){
      layout->addWidget(label_0[i] = new QLabel,i,0);
      layout->addWidget(label_3[i] = new QLabel,i,2);
  }

  layout->addWidget(label_1[8]=new QLabel,8,1);
  layout->addWidget(label_1[9]=new QLabel,9,1);
 
  // create  label[8] row 2,3 
  for(int i=0;i<8;i++)
	layout->addLayout(lbLayout[i] = new QHBoxLayout,i,1);

  for(int i=0;i<8;i++){

	lbLayout[i]->addWidget(label_1[i] = new QLabel); 
	//	lbLayout[i]->addStretch(1);
	lbLayout[i]->addWidget(label_2[i] = new QLabel);
  }

  //  set style  row 0,3
  for(int i=0;i<10;i++){
    label_0[i]->setFrameStyle(6);
	label_3[i]->setFrameStyle(6);
  }
  //set size row 0,3
  for(int i=0;i<10;i++){
    label_0[i]->setMaximumSize(WIDTH, HEIGHT);
	label_3[i]->setMaximumSize(WIDTH, HEIGHT);
  }
  //set style row 1,2
  for(int i=0;i<8;i++){
	label_1[i]->setFrameStyle(6);
	label_2[i]->setFrameStyle(6);
  }

  label_1[8]->setFrameStyle(6);
  label_1[9]->setFrameStyle(6);
  //set size row 1,2
  for(int i=0;i<8;i++){
	label_1[i]->setMaximumSize(WIDTH,HEIGHT);
	label_2[i]->setMaximumSize(WIDTH,HEIGHT);
}
  label_1[8]->setMaximumSize(2*WIDTH,HEIGHT);
  label_1[9]->setMaximumSize(2*WIDTH,HEIGHT);
  

  

  {
    str[0][0] = QString(" Tвх = %2 %1C").arg(QChar(0x00b0));
	str[1][0] = QString(" H10 = %1 cm");
    str[2][0] = QString(" H9 = %1 cm");
    str[3][0] = QString(" H8 = %1 cm");   
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
	str[5][1] = QString(" Ftx2 = %1 Гц");
	str[6][1] = QString(" T1 = %2 %1С 1").arg(QChar(0x00b0));
	str[7][1] = QString(" T2 = %2 %1С 0").arg(QChar(0x00b0));
    str[8][1] = QString(" Kz = %1");

	str[0][2] = QString(" %1t = %2").arg(QChar(0x03B1));
	str[1][2] = QString(" %1h = %2").arg(QChar(0x03B1));
    str[2][2] = QString(" %1w = %2").arg(QChar(0x03B1));
	str[3][2] = QString(" %1%2 = %3").arg(QChar(0x03B1)).arg(QChar(0x0033));
    str[4][2] = QString(" Nh1 = %1");
	str[5][2] = QString(" Nh1_2 = %1");
	str[6][2] = QString(" Nh1_3 = %1");
	str[7][2] = QString(" Nh1_1 = %1");

    str[0][3] = QString(" Q2 = %1");
	str[1][3] = QString(" Q3 = %1");
	str[2][3] = QString(" %1d = %2").arg(QChar(0x03B1));
	str[3][3] = QString(" %1%2 = %3").arg(QChar(0x03B1)).arg(QChar(0x0033));
	str[4][3] = QString(" Nh = %1");
	str[5][3] = QString(" Tkf = %1 дня");
	str[6][3] = QString(" Tэфф = %1 дней");
	str[7][3] = QString(" %1kf0 = %2").arg(QChar(0x03B1));
	str[8][3] = QString(" Fнкор = %1");
	str[9][3] = QString(" Fккор = %1");
  }

  QString style = QString("border-width: 2px; border-radius: 10px; padding: 6 px; border-style: outset; background-color:rgb(80,80,80);border-color:grey;text-align:center;color:rgb(255,255,255)");
 
 for(int i=0;i<10;i++){

	label_0[i]->setText(str[i][0]);
    label_0[i]->setStyleSheet(style);
    
    label_3[i]->setText(str[i][3]);
    label_3[i]->setStyleSheet(style);
}
  
 for(int i=0;i<8;i++){
    label_1[i]->setText(str[i][1]);
    label_1[i]->setStyleSheet(style);
    
    label_2[i]->setText(str[i][2]);
    label_2[i]->setStyleSheet(style);
}

 label_1[8]->setText(str[8][1]);
 label_1[8]->setStyleSheet(style);
 label_1[9]->setStyleSheet(style);
  

  this->setStyleSheet("background-color:qlineargradient(x1: 0,y1: 0,x2: 0,y2: 1,stop: 0#aaaaaa, stop: 0.5 #434343, stop: 0.31 #000000, stop: 1 #585c5f)");

  this->setLayout(layout);
}

Widget::~Widget()
{
     
}
  
