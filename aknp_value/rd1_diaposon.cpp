#include "rd1_diaposon.h"

rd1_diaposon::rd1_diaposon(QWidget *parent )
{
    led[0]->setText("АЗ N");
    led[3]->setText("АЗ Т");
    led[2]->setVisible(false);
    led[1]->setText("ПЗ N");;
    led[4]->setText("ПЗ T");
    led[5]->setVisible(false);
    led[6]->setText("PM T");
    led[7]->setVisible(false);
    led[8]->setVisible(false);
	led[9]->setVisible(false);
	led[10]->setVisible(false);
	led[11]->setVisible(false);
    led[12]->setText("НД РД1");
    led[13]->setText("Исп РД1");
    led[14]->setText("Исп БХ");

    led[0]->setColor("red");
    led[1]->setColor("yellow");
    led[3]->setColor("red");
    led[4]->setColor("yellow");
    led[6]->setColor("yellow");
	led[12]->setColor("green");
    led[13]->setColor("green");
    led[14]->setColor("green");
  //  discret_layout->setColumnMinimumWidth(2,60);
  //  discret_layout->setColumnMinimumWidth(3,60);
	//discret_layout->setRowMinimumHeight(2,30);
    //
    analog_lab[0]->setText("N,%");
    analog_lab[1]->setText("Т,с ");
    analog_lab[2]->setVisible(false);
    analog_lab[3]->setText("Nуст,%");
    analog_lab[4]->setText("Туст,с");
    analog_lab[5]->setVisible(false);
    analog[2]->setVisible(false);
    analog[5]->setVisible(false); 

	
}

