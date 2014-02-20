#include "pd_diaposon.h"

pd_diaposon::pd_diaposon(QWidget *parent )
{
    led[0]->setText("АЗ N");
    led[3]->setText("АЗ T");
    led[2]->setVisible(false);
    led[1]->setText("ПЗ N");
    led[4]->setText("ПЗ Т");
    led[5]->setVisible(false);
    led[6]->setText("PM T");
    led[7]->setVisible(false);
    led[8]->setVisible(false);
    led[9]->setVisible(false);
	led[10]->setVisible(false);
	led[11]->setVisible(false);
    led[12]->setText("ндПД");
    led[13]->setText("ИспПД.");
	led[14]->setVisible(false);

    led[0]->setColor("red");
	led[1]->setColor("red");	
    led[3]->setColor("yellow");
	led[4]->setColor("yellow");
    led[6]->setColor("yellow");
	led[12]->setColor("green");
    led[13]->setColor("green");
	
  //  discret_layout->setColumnMinimumWidth(3,65);
  //  discret_layout->setColumnMinimumWidth(4,65);
    //
    prefix[0] = "N";suffix[0] ="%";
    prefix[1] = "T";suffix[0] ="c";
    prefix[3] = "Nуст";suffix[3] ="%";
    prefix[4] = "Tуст";suffix[4] = "c";
	analog[2]->setVisible(false);
	analog[5]->setVisible(false);

}

