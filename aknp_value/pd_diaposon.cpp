#include "pd_diaposon.h"

pd_diaposon::pd_diaposon(QWidget *parent )
{
    led[0]->setText("АЗ N");
    led[1]->setText("АЗ T");
    led[2]->setVisible(false);
    led[3]->setText("ПЗ N");
    led[4]->setText("ПЗ Т");
    led[5]->setVisible(false);
    led[7]->setText("PM T");
    led[6]->setVisible(false);
    led[8]->setVisible(false);
    led[9]->setVisible(false);
	led[10]->setVisible(false);
	led[11]->setVisible(false);
    led[12]->setText("НД ПД");
    led[13]->setText("ПД");
	led[14]->setVisible(false);

    led[0]->setColor("R");
    led[1]->setColor("R");
    led[3]->setColor("Y");
    led[4]->setColor("Y");
    led[7]->setColor("Y");
    led[12]->setColor("G");
    led[13]->setColor("RG");
	
  //  discret_layout->setColumnMinimumWidth(3,65);
  //  discret_layout->setColumnMinimumWidth(4,65);
    //
    analog_lab[0]->setText("N,%");
    analog_lab[1]->setText("T,c");
    analog_lab[3]->setText("Nуст,%");
    analog_lab[4]->setText("Tуст,c");
	analog[2]->setVisible(false);
	analog[5]->setVisible(false);

}

