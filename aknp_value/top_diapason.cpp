#include "top_diapason.h"

top_diaposon::top_diaposon(QWidget *parent)
{
    led[0]->setText("АЗ N");
    led[1]->setText("ПЗ N");
    led[2]->setVisible(false);
    led[3]->setText("ГЦН 1");
    led[4]->setText("ГЦН 2");
    led[5]->setVisible(false);
    led[6]->setText("ГЦН 3");
    led[7]->setText("ГЦН 4");//setText("ПС N/G");
    led[8]->setVisible(false);
    led[9]->setVisible(false);//("ПЗАФСЗ");
    led[10]->setVisible(false);
    led[11]->setVisible(false);
    led[12]->setText("АКНП");
    led[13]->setText("Н АКЭ");
    led[14]->setVisible(false);
   // discret_layout->setColumnMinimumWidth(1,10);
    //
    analog_lab[0]->setText("Nтек,%");
    analog_lab[1]->setText("Tтек,c");
    analog_lab[2]->setVisible(false);
    analog_lab[4]->setVisible(false);
    analog_lab[3]->setVisible(false);
    analog_lab[5]->setVisible(false);
    //analog[1]->setVisible(false);
    analog[2]->setVisible(false);
    analog[5]->setVisible(false);
    analog[4]->setVisible(false);
    analog[3]->setVisible(false);
  //  analog_layout->setColumnMinimumWidth(1,110);
    //example
  // discret_layout->setColumnMinimumWidth(3,45);

    //analog[0]->setText("12345678");
    led[0]->setColor("red");
    led[1]->setColor("yellow");
    led[3]->setColor("red");
    led[4]->setColor("red");
    led[6]->setColor("red");
    led[7]->setColor("red");
    led[12]->setColor("green");
    led[13]->setColor("red");



    //discret_layout->setRowMinimumHeight(2,30);
}


