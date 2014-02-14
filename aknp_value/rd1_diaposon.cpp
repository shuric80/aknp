#include "rd1_diaposon.h"

rd1_diaposon::rd1_diaposon()
{
    led[0]->setText("АЗ N");
    led[1]->setText("АЗ Т");
    led[2]->setVisible(false);
    led[3]->setText("ПС N");;
    led[4]->setText("ПС T");
    led[5]->setVisible(false);
    led[6]->setVisible(false);
    led[7]->setVisible(false);
    led[8]->setVisible(false);
	led[9]->setVisible(false);
	led[10]->setVisible(false);
	led[11]->setVisible(false);
    led[12]->setText("НД РД1");
    led[13]->setText("Н РД1.");
    led[14]->setText("Н Бх");

    led[0]->setColor("red");
	led[1]->setColor("red");
    led[3]->setColor("yellow");
    led[4]->setColor("yellow");
	led[12]->setColor("green");
	led[13]->setColor("red");
    led[14]->setColor("red");
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

