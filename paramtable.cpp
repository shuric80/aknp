#include "paramtable.h"
#include "ui_paramtable.h"

ParamTable::ParamTable(QWidget *parent) :
    QToolBox(parent),
    ui(new Ui::ParamTable)
{
    ui->setupUi(this);
    this->setCurrentIndex(0);  //set start page


}

void ParamTable::selectId(const QVector<int> &data){

   int id = data.at(0);
   QVector<int> data_h;
   QVector<int> data_l;

   data_l << data.mid(1,4);
   data_h << data.mid(5,4);

   QString str_l = toFloat(data_l);
   QString str_h = toFloat(data_h);

   switch(id){

   case 0x681:
       ui->lineEdit_01->setText(str_l);
       ui->lineEdit_02->setText(str_h);
       break;
   case 0x682:
       ui->lineEdit_03->setText(str_l);
       ui->lineEdit_04->setText(str_h);
       break;
   case 0x683:
       ui->lineEdit_05->setText(str_l);
       ui->lineEdit_06->setText(str_h);
       break;
   case 0x684:
       ui->lineEdit_07->setText(str_l);
       ui->lineEdit_08->setText(str_h);
       break;
   case 0x685:
       ui->lineEdit_09->setText(str_l);
       ui->lineEdit_10->setText(str_h);
       break;
   case 0x686:
       ui->lineEdit_11->setText(str_l);
       ui->lineEdit_12->setText(str_h);
       break;
   case 0x687:
       ui->lineEdit_13->setText(str_l);
       ui->lineEdit_14->setText(str_h);
       break;
   case 0x688:
       ui->lineEdit_15->setText(str_l);
       ui->lineEdit_16->setText(str_h);
       break;
   case 0x689:
       ui->lineEdit_17->setText(str_l);
       ui->lineEdit_18->setText(str_h);
       break;
   case 0x68A:
       ui->lineEdit_19->setText(str_l);
       ui->lineEdit_20->setText(str_h);
       break;
   case 0x68B:
       ui->lineEdit_21->setText(str_l);
       ui->lineEdit_22->setText(str_h);
       break;
   case 0x68C:
       ui->lineEdit_23->setText(str_l);
       ui->lineEdit_24->setText(str_h);
       break;
   case 0x68D:
       ui->lineEdit_25->setText(str_l);
       ui->lineEdit_26->setText(str_h);
       break;
   case 0x68E:
       ui->lineEdit_27->setText(str_l);
       ui->lineEdit_28->setText(str_h);
       break;
   case 0x68F:
       ui->lineEdit_29->setText(str_l);
       ui->lineEdit_30->setText(str_h);
       break;
   case 0x690:
       ui->lineEdit_31->setText(str_l);
       ui->lineEdit_32->setText(str_h);
       break;
   case 0x691:
       ui->lineEdit_33->setText(str_l);
       ui->lineEdit_34->setText(str_h);
       break;
   case 0x692:
       ui->lineEdit_35->setText(str_l);
       ui->lineEdit_36->setText(str_h);
       break;
   case 0x693:
       ui->lineEdit_37->setText(str_l);
       ui->lineEdit_38->setText(str_h);
       break;
   case 0x694:
       ui->lineEdit_39->setText(str_l);
       ui->lineEdit_40->setText(str_h);
       break;
   case 0x695:
       ui->lineEdit_41->setText(str_l);
       ui->lineEdit_42->setText(str_h);
       break;
   case 0x696:
       ui->lineEdit_43->setText(str_l);
       ui->lineEdit_44->setText(str_h);
       break;
   case 0x697:
       ui->lineEdit_45->setText(str_l);
       ui->lineEdit_46->setText(str_h);
       break;
   case 0x698:
       ui->lineEdit_47->setText(str_l);
       ui->lineEdit_48->setText(str_h);
       break;
   case 0x699:
       ui->lineEdit_49->setText(str_l);
       ui->lineEdit_50->setText(str_h);
       break;
   case 0x69A:
       ui->lineEdit_51->setText(str_l);
       ui->lineEdit_52->setText(str_h);
       break;
   case 0x69B:
       ui->lineEdit_53->setText(str_l);
       ui->lineEdit_54->setText(str_h);
       break;
   case 0x69C:
       ui->lineEdit_55->setText(str_l);
       ui->lineEdit_56->setText(str_h);
       break;
   case 0x69D:
       ui->lineEdit_57->setText(str_l);
       ui->lineEdit_58->setText(str_h);
       break;
   case 0x69E:
       ui->lineEdit_59->setText(str_l);
       ui->lineEdit_60->setText(str_h);
       break;
   case 0x69F:
       ui->lineEdit_61->setText(str_l);
       ui->lineEdit_62->setText(str_h);
       break;
   case 0x6A0:
       ui->lineEdit_63->setText(str_l);
       ui->lineEdit_64->setText(str_h);
       break;
   case 0x6A1:
       ui->lineEdit_65->setText(str_l);
       ui->lineEdit_66->setText(str_h);
       break;
   case 0x6A2:
       ui->lineEdit_67->setText(str_l);
       ui->lineEdit_68->setText(str_h);
       break;
   case 0x6A3:
       ui->lineEdit_69->setText(str_l);
       ui->lineEdit_70->setText(str_h);
       break;
   case 0x6A4:
       ui->lineEdit_71->setText(str_l);
       ui->lineEdit_72->setText(str_h);
       break;
   case 0x6A5:
       ui->lineEdit_73->setText(str_l);
       ui->lineEdit_74->setText(str_h);
       break;
   case 0x6A6:
       ui->lineEdit_75->setText(str_l);
       ui->lineEdit_76->setText(str_h);
       break;
   case 0x6A7:
       ui->lineEdit_77->setText(str_l);
       ui->lineEdit_78->setText(str_h);
       break;
   case 0x6A8:
       ui->lineEdit_79->setText(str_l);
       ui->lineEdit_80->setText(str_h);
       break;
 default:
       break;


   }
}

void ParamTable::save(){

      }


const QString ParamTable::toFloat(const QVector<int> &value){

       float f;
       quint8 *str = (quint8*) &f;
       str[0] = value.at(0);
       str[1] = value.at(1);
       str[2] = value.at(2);
       str[3] = value.at(3);


       return QString::number(f);
}




ParamTable::~ParamTable()
{
    delete ui;
}
