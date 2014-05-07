#include "rd1_diaposon.h"

rd1_diaposon::rd1_diaposon(QWidget *parent )
{
    led[0]->setText("АЗ N");
    led[1]->setText("АЗ Т");
    led[2]->setVisible(false);
    led[3]->setText("ПЗ-1 N");;
    led[4]->setText("ПЗ-1 T");
    led[5]->setVisible(false);
    led[7]->setText("ПЗ-2 T");
    led[6]->setVisible(false);
    led[8]->setVisible(false);
    led[10]->setVisible(false);
    led[9]->setVisible(false);
	led[11]->setVisible(false);
    led[12]->setText("НД РД1");
    led[13]->setText("РД1");
    led[14]->setText("БХ РД1");

    led[0]->setColor("R");
    led[1]->setColor("R");
    led[3]->setColor("Y");
    led[4]->setColor("Y");
    led[7]->setColor("Y");
    led[10]->setColor("Y");
    led[12]->setColor("G");
    led[13]->setColor("RG");
    led[14]->setColor("RG");
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

