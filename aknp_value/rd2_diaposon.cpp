#include "rd2_diaposon.h"

rd2_diaposon::rd2_diaposon()
{
    led[0]->setText("АЗ N");
    led[1]->setText("ПЗ N");
	led[2]->setVisible(false);
    led[3]->setVisible(false);
    led[4]->setVisible(false);
    led[5]->setVisible(false);
    led[6]->setText("N>5%");
    led[7]->setText("N>75%");
    led[8]->setVisible(false);
    led[9]->setVisible(false);
    led[10]->setVisible(false);
	led[11]->setVisible(false);
	led[12]->setText("НД РД2");
    led[13]->setText("Н РД2.");
    led[14]->setText("Н БХ");
    //discret_layout->setColumnMinimumWidth(1,30);
   // discret_layout->setColumnMinimumWidth(3,30);
   // discret_layout->setRowMinimumWidth(4,90);

    analog_lab[0]->setText("N,%");
  //  analog_lab[1]->setText("G,кг/с");
  //  analog_lab[2]->setText("N/G,% ");
    analog_lab[3]->setText("Nуст,%");
 //   analog_lab[4]->setText("F,Гц");
 //   analog_lab[5]->setText("N/Gуст,% ");
    analog[1]->setVisible(false);
    analog[2]->setVisible(false);
    analog[4]->setVisible(false);
    analog[5]->setVisible(false);

    led[0]->setColor("red");
    led[1]->setColor("yellow");
    led[6]->setColor("green");
    led[7]->setColor("green");
    led[12]->setColor("green");
    led[13]->setColor("red");
    led[14]->setColor("red");

    //discret_layout->setRowMinimumHeight(2,30);
}


