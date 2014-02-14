#include "akeslideimitator.h"

AkeSlideImitator::AkeSlideImitator(QWidget *parent) :
    QWidget(parent)
{
      QVBoxLayout *privodLayout = new QVBoxLayout;
	  
      QLabel *label;

	  privodLayout ->addWidget(label = new QLabel("F"));
	  privodLayout ->addWidget(valuePrivod = new QSpinBox);
      privodLayout->addWidget(btnPlus = new QPushButton("+"));
	  privodLayout->addWidget(btnMinus = new QPushButton("-"));
      
      valuePrivod->setRange(0,255);
      valuePrivod->setValue(181);
    
      this->setLayout(privodLayout);
  	
	  connect(valuePrivod,SIGNAL(valueChanged(int)),this,SLOT(slotPrivod()));
      connect(btnPlus,SIGNAL(clicked()),this,SLOT(slotPlusValue()));
	  connect(btnMinus,SIGNAL(clicked()),this,SLOT(slotMinusValue()));
  }
  
void AkeSlideImitator::slotPrivod(){

	int pv = valuePrivod->value();
    if(pv == 182)
	  valuePrivod->setValue(255);
	else if(pv == 254 )
	  valuePrivod->setValue(181);
	else if((182 < pv) & (pv <254)){
	  valuePrivod ->setStyleSheet("background-color:pink");
      btnMinus->setEnabled(false);
      btnPlus->setEnabled(false); 
	 }
    else{
	  valuePrivod->setStyleSheet("background-color:white");
      btnPlus->setEnabled(true);
      btnMinus->setEnabled(true);
     }
  
	//send
	int data = valuePrivod->value();
	emit sgnlSetValue(data);
}

void AkeSlideImitator::slotPlusValue(){
 
 int cur = valuePrivod->value();
 valuePrivod->setValue(cur+1);

 slotPrivod();

}

void AkeSlideImitator::slotMinusValue(){


  int cur = valuePrivod->value();
  valuePrivod->setValue(cur-1);

  slotPrivod();

}

