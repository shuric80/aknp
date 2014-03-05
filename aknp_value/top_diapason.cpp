#include "top_diapason.h"

top_diaposon::top_diaposon(QWidget *parent)

{

    led[0]->setText("АЗ N");
    led[1]->setText("АЗ Т");
    led[2]->setText("ГЦН 1");
    led[3]->setText("ПЗ N");
    led[4]->setText("ПЗ T");
    led[5]->setText("ГЦН 2");
    led[6]->setText("PM N");
    led[7]->setText("РМ Т");//setText("ПС N/G");
    led[8]->setText("ГЦН 3");
    led[9]->setVisible(false);//("ПЗАФСЗ");
    led[10]->setVisible(false);
    led[11]->setText("ГЦН 4");
    led[12]->setText("АКНП");
    led[13]->setText("АКЭ");
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
    led[0]->setColor("R");
    led[1]->setColor("R");
    led[2]->setColor("Y");
    led[3]->setColor("Y");
    led[4]->setColor("Y");
    led[5]->setColor("Y");
    led[6]->setColor("Y");
    led[7]->setColor("Y");
    led[8]->setColor("Y");
    led[11]->setColor("Y");
    led[12]->setColor("RG");
    led[13]->setColor("RG");



    //discret_layout->setRowMinimumHeight(2,30);
}


