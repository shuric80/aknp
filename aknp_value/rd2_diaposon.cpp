#include "rd2_diaposon.h"

rd2_diaposon::rd2_diaposon(QWidget *parent)
{
    led[0]->setText("АЗ N");
    led[3]->setText("ПЗ N");
	led[2]->setVisible(false);
    led[7]->setVisible(false);
    led[9]->setVisible(false);
    led[5]->setVisible(false);
    led[6]->setText("PM N");
    led[10]->setVisible(false);
    led[8]->setVisible(false);
    led[4]->setText("N>5%");
    led[1]->setText("N>75");
	led[11]->setVisible(false);
	led[12]->setText("НД РД2");
    led[13]->setText("Исп РД2");
    led[14]->setText("Исп БХ1");


    analog_lab[0]->setText("N,%");
    analog_lab[3]->setText("Nуст,%");

    analog[1]->setVisible(false);
    analog[2]->setVisible(false);
    analog[4]->setVisible(false);
    analog[5]->setVisible(false);

    led[0]->setColor("red");
    led[3]->setColor("yellow");
    led[6]->setColor("yellow");
    led[4]->setColor("green");
    led[1]->setColor("green");
    led[12]->setColor("green");
    led[13]->setColor("green");
    led[14]->setColor("green");

    //discret_layout->setRowMinimumHeight(2,30);
}


