#include "verify.h"
#include <QDebug>

verify::verify(QWidget *parent):QWidget(parent){

  set_verify =0;
  QLabel *label[3];
  QHBoxLayout *layout[3];
  QVBoxLayout *topLayout = new QVBoxLayout;
  for(int i=0;i<3;i++){
      topLayout->addLayout(layout[i] = new QHBoxLayout);
	layout[i]->addWidget(label[i]=new QLabel);
	layout[i]->addStretch(1);
	layout[i]->addWidget(button[i] =new QPushButton("Старт"));
    button[i]->setCheckable(true);
  }

 {
  label[0]->setText("Проверка РД1");
  label[1]->setText("Проверка ПД");
  label[2]->setText("Проверка ИД");
    }

  topLayout->addStretch(1);
  setLayout(topLayout);

  for(int i=0;i<3;i++)
     connect(button[i],SIGNAL(toggled(bool)),this,SLOT(start_np(bool)));

}

void verify::start_np(bool state){

    bool set_bit[3];
      
    for(int i=0;i<3;i++){
       set_bit[i] = button[i]->isChecked();
       button[i]->setText(set_bit[i] ? "Стоп":"Старт");
       button[i]->setEnabled(set_bit[i]);
    }
    if(!state){
        for(int i=0;i<3;i++)
		  button[i]->setEnabled(true);
        set_verify =0;
}
    else 
        set_verify = (set_bit[0] << 6) | (set_bit[1] <<5) | (set_bit[2] << 4);// | state;
    
    emit send_verify(set_verify);
	qDebug() << set_verify;

}
