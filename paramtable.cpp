#include "paramtable.h"
#include "ui_paramtable.h"
#include <QDebug>

ParamTable::ParamTable(QWidget *parent) :
    QToolBox(parent),
    ui(new Ui::ParamTable)
{
    ui->setupUi(this);
    this->setCurrentIndex(0);  //set start page
   // enable = false;
    this->setEnabled(false);
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
    case 0x400:
        enable =(bool)data.at(1);
        this->setVisible(enable);

        break;

    case 0x411:
        ui->lineEdit_01->setText(str_l);
        ui->lineEdit_02->setText(str_h);
        break;
    case 0x412:
        ui->lineEdit_03->setText(str_l);
        ui->lineEdit_04->setText(str_h);
        break;
    case 0x413:
        ui->lineEdit_05->setText(str_l);
        ui->lineEdit_06->setText(str_h);
        break;
    case 0x414:
        ui->lineEdit_07->setText(str_l);
        ui->lineEdit_08->setText(str_h);
        break;
    case 0x415:
        ui->lineEdit_09->setText(str_l);
        ui->lineEdit_10->setText(str_h);
        break;
    case 0x416:
        ui->lineEdit_11->setText(str_l);
        ui->lineEdit_12->setText(str_h);
        break;
    case 0x417:
        ui->lineEdit_13->setText(str_l);
        ui->lineEdit_14->setText(str_h);
        break;
    case 0x418:
        ui->lineEdit_15->setText(str_l);
        ui->lineEdit_16->setText(str_h);
        break;
    case 0x419:
        ui->lineEdit_17->setText(str_l);
        ui->lineEdit_18->setText(str_h);
        break;
    case 0x41A:
        ui->lineEdit_19->setText(str_l);
        ui->lineEdit_20->setText(str_h);
        break;
    case 0x41B:
        ui->lineEdit_21->setText(str_l);
        ui->lineEdit_22->setText(str_h);
        break;
    case 0x41C:
        ui->lineEdit_23->setText(str_l);
        ui->lineEdit_24->setText(str_h);
        break;
    case 0x41D:
        ui->lineEdit_25->setText(str_l);
        ui->lineEdit_26->setText(str_h);
        break;
    case 0x41E:
        ui->lineEdit_27->setText(str_l);
        ui->lineEdit_28->setText(str_h);
        break;
    case 0x41F:
        ui->lineEdit_29->setText(str_l);
        ui->lineEdit_30->setText(str_h);
        break;
    case 0x420:
        ui->lineEdit_31->setText(str_l);
        ui->lineEdit_32->setText(str_h);
        break;
    case 0x421:
        ui->lineEdit_33->setText(str_l);
        ui->lineEdit_34->setText(str_h);
        break;
    case 0x422:
        ui->lineEdit_35->setText(str_l);
        ui->lineEdit_36->setText(str_h);
        break;
    case 0x423:
        ui->lineEdit_37->setText(str_l);
        ui->lineEdit_38->setText(str_h);
        break;
    case 0x424:
        ui->lineEdit_39->setText(str_l);
        ui->lineEdit_40->setText(str_h);
        break;
    case 0x425:
        ui->lineEdit_41->setText(str_l);
        ui->lineEdit_42->setText(str_h);
        break;
    case 0x426:
        ui->lineEdit_43->setText(str_l);
        ui->lineEdit_44->setText(str_h);
        break;
    case 0x427:
        ui->lineEdit_45->setText(str_l);
        ui->lineEdit_46->setText(str_h);
        break;
    case 0x428:
        ui->lineEdit_47->setText(str_l);
        ui->lineEdit_48->setText(str_h);
        break;
    case 0x429:
        ui->lineEdit_49->setText(str_l);
        ui->lineEdit_50->setText(str_h);
        break;
    case 0x42A:
        ui->lineEdit_51->setText(str_l);
        ui->lineEdit_52->setText(str_h);
        break;
    case 0x42B:
        ui->lineEdit_53->setText(str_l);
        ui->lineEdit_54->setText(str_h);
        break;
    case 0x42C:
        ui->lineEdit_55->setText(str_l);
        ui->lineEdit_56->setText(str_h);
        break;
    case 0x42D:
        ui->lineEdit_57->setText(str_l);
        ui->lineEdit_58->setText(str_h);
        break;
    case 0x42E:
        ui->lineEdit_59->setText(str_l);
        ui->lineEdit_60->setText(str_h);
        break;
    case 0x42F:
        ui->lineEdit_61->setText(str_l);
        ui->lineEdit_62->setText(str_h);
        break;
    case 0x430:
        ui->lineEdit_63->setText(str_l);
        ui->lineEdit_64->setText(str_h);
        break;
    case 0x431:
        ui->lineEdit_65->setText(str_l);
        ui->lineEdit_66->setText(str_h);
        break;
    case 0x432:
        ui->lineEdit_67->setText(str_l);
        ui->lineEdit_68->setText(str_h);
        break;
    case 0x433:
        ui->lineEdit_69->setText(str_l);
        ui->lineEdit_70->setText(str_h);
        break;
    case 0x434:
        ui->lineEdit_71->setText(str_l);
        ui->lineEdit_72->setText(str_h);
        break;
    case 0x435:
        ui->lineEdit_73->setText(str_l);
        ui->lineEdit_74->setText(str_h);
        break;
    case 0x436:
        ui->lineEdit_75->setText(str_l);
        ui->lineEdit_76->setText(str_h);
        break;
    case 0x437:
        ui->lineEdit_77->setText(str_l);
        ui->lineEdit_78->setText(str_h);
        break;
    case 0x438:
        ui->lineEdit_79->setText(str_l);
        ui->lineEdit_80->setText(str_h);
        break;
    default:
        break;

    }
}

void ParamTable::saveParam(){

    int id;
    QString str_h,str_l;

    id = 0x681;
    str_l = ui->lineEdit_01->text();
    str_h = ui->lineEdit_02->text();
    sendCAN(id,str_l,str_h);

    id = 0x682;
    str_l = ui->lineEdit_03->text();
    str_h = ui->lineEdit_04->text();
    sendCAN(id,str_l,str_h);

    id = 0x683;
    str_l = ui->lineEdit_05->text();
    str_h = ui->lineEdit_06->text();
    sendCAN(id,str_l,str_h);

    id = 0x684;
    str_l = ui->lineEdit_07->text();
    str_h = ui->lineEdit_08->text();
    sendCAN(id,str_l,str_h);

    id = 0x685;
    str_l = ui->lineEdit_09->text();
    str_h = ui->lineEdit_10->text();
    sendCAN(id,str_l,str_h);

    id = 0x686;
    str_l = ui->lineEdit_11->text();
    str_h = ui->lineEdit_12->text();
    sendCAN(id,str_l,str_h);

    id = 0x687;
    str_l = ui->lineEdit_13->text();
    str_h = ui->lineEdit_14->text();
    sendCAN(id,str_l,str_h);

    id = 0x688;
    str_l = ui->lineEdit_15->text();
    str_h = ui->lineEdit_16->text();
    sendCAN(id,str_l,str_h);

    id = 0x689;
    str_l = ui->lineEdit_17->text();
    str_h = ui->lineEdit_18->text();
    sendCAN(id,str_l,str_h);
    id = 0x68A;
    str_l = ui->lineEdit_19->text();
    str_h = ui->lineEdit_20->text();
    sendCAN(id,str_l,str_h);

    id = 0x68B;
    str_l = ui->lineEdit_21->text();
    str_h = ui->lineEdit_22->text();
    sendCAN(id,str_l,str_h);

    id = 0x68C;
    str_l = ui->lineEdit_23->text();
    str_h = ui->lineEdit_24->text();
    sendCAN(id,str_l,str_h);

    id = 0x68D;
    str_l = ui->lineEdit_25->text();
    str_h = ui->lineEdit_26->text();
    sendCAN(id,str_l,str_h);

    id = 0x68E;
    str_l = ui->lineEdit_27->text();
    str_h = ui->lineEdit_28->text();
    sendCAN(id,str_l,str_h);

    id = 0x68F;
    str_l = ui->lineEdit_29->text();
    str_h = ui->lineEdit_30->text();
    sendCAN(id,str_l,str_h);

    id = 0x690;
    str_l = ui->lineEdit_31->text();
    str_h = ui->lineEdit_32->text();
    sendCAN(id,str_l,str_h);

    id = 0x691;
    str_l = ui->lineEdit_33->text();
    str_h = ui->lineEdit_34->text();
    sendCAN(id,str_l,str_h);

    id = 0x692;
    str_l = ui->lineEdit_35->text();
    str_h = ui->lineEdit_36->text();
    sendCAN(id,str_l,str_h);

    id = 0x693;
    str_l = ui->lineEdit_37->text();
    str_h = ui->lineEdit_38->text();
    sendCAN(id,str_l,str_h);

    id = 0x694;
    str_l = ui->lineEdit_39->text();
    str_h = ui->lineEdit_40->text();
    sendCAN(id,str_l,str_h);

    id = 0x695;
    str_l = ui->lineEdit_41->text();
    str_h = ui->lineEdit_42->text();
    sendCAN(id,str_l,str_h);

    id = 0x696;
    str_l = ui->lineEdit_43->text();
    str_h = ui->lineEdit_44->text();
    sendCAN(id,str_l,str_h);

    id = 0x697;
    str_l = ui->lineEdit_45->text();
    str_h = ui->lineEdit_46->text();
    sendCAN(id,str_l,str_h);

    id = 0x698;
    str_l = ui->lineEdit_47->text();
    str_h = ui->lineEdit_48->text();
    sendCAN(id,str_l,str_h);

    id = 0x699;
    str_l = ui->lineEdit_49->text();
    str_h = ui->lineEdit_50->text();
    sendCAN(id,str_l,str_h);

    id = 0x69A;
    str_l = ui->lineEdit_51->text();
    str_h = ui->lineEdit_52->text();
    sendCAN(id,str_l,str_h);

    id = 0x69B;
    str_l = ui->lineEdit_53->text();
    str_h = ui->lineEdit_54->text();
    sendCAN(id,str_l,str_h);

    id = 0x69C;
    str_l = ui->lineEdit_55->text();
    str_h = ui->lineEdit_56->text();
    sendCAN(id,str_l,str_h);

    id = 0x69D;
    str_l = ui->lineEdit_57->text();
    str_h = ui->lineEdit_58->text();
    sendCAN(id,str_l,str_h);

    id = 0x69E;
    str_l = ui->lineEdit_59->text();
    str_h = ui->lineEdit_60->text();
    sendCAN(id,str_l,str_h);

    id = 0x69F;
    str_l = ui->lineEdit_61->text();
    str_h = ui->lineEdit_62->text();
    sendCAN(id,str_l,str_h);

    id = 0x6A0;
    str_l = ui->lineEdit_63->text();
    str_h = ui->lineEdit_64->text();
    sendCAN(id,str_l,str_h);

    id = 0x6A1;
    str_l = ui->lineEdit_65->text();
    str_h = ui->lineEdit_66->text();
    sendCAN(id,str_l,str_h);

    id = 0x6A2;
    str_l = ui->lineEdit_67->text();
    str_h = ui->lineEdit_68->text();
    sendCAN(id,str_l,str_h);

    id = 0x6A3;
    str_l = ui->lineEdit_69->text();
    str_h = ui->lineEdit_70->text();
    sendCAN(id,str_l,str_h);

    id = 0x6A4;
    str_l = ui->lineEdit_71->text();
    str_h = ui->lineEdit_72->text();
    sendCAN(id,str_l,str_h);

    id = 0x6A5;
    str_l = ui->lineEdit_73->text();
    str_h = ui->lineEdit_74->text();
    sendCAN(id,str_l,str_h);

    id = 0x6A6;
    str_l = ui->lineEdit_75->text();
    str_h = ui->lineEdit_76->text();
    sendCAN(id,str_l,str_h);

    id = 0x6A7;
    str_l = ui->lineEdit_77->text();
    str_h = ui->lineEdit_78->text();
    sendCAN(id,str_l,str_h);

    id = 0x6A8;
    str_l = ui->lineEdit_79->text();
    str_h = ui->lineEdit_80->text();
    sendCAN(id,str_l,str_h);
}

void ParamTable::sendCAN(int id , const QString &l, const QString &h){

    bool ok;
    float fl,fh;

    QVector<int> data_l(4,0);
    QVector<int> data_h(4,0);
    QVector<int> can_frame;

    fl = l.toFloat(&ok);
    if(!ok)
        qWarning() << "Error L: QString->float" << "id:" <<id   << l;
    else
        data_l = toVector(fl);

    fh = h.toFloat(&ok);
    if(!ok)
        qWarning() << "Error H: QString->float" << "id:" << id << h;
    else
        data_h = toVector(fh);

    can_frame.append(id);
    can_frame << data_l;
    can_frame << data_h;

    emit send(can_frame);
    ::usleep(1000);
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

const QVector<int> ParamTable::toVector(float val){

    QVector <int> tmp;

    quint8 *N = (quint8*)&val;

    for(int i =0;i<4;i++)
        tmp.append(N[i]);

    return tmp;
}


ParamTable::~ParamTable()
{
    delete ui;
}
