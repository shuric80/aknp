#include "periodimit.h"
#include <QSize>
#include <QtCore>

PeriodImit::PeriodImit(QWidget *parent):QWidget(parent){

    step = 1;
    qRegisterMetaType <QVector<float> > ("QVector<float>");

    timer =new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(input_time()));

    usec=0;

    QHBoxLayout *layout[5];
    QLabel *label[5];
    for (int i=0;i<5;i++){
        layout[i] = new QHBoxLayout;
        label[i] = new QLabel;
        layout[i]->addWidget(label[i]);
        layout[i]->addStretch(1);
        layout[i]->setMargin(0);
    }
    {
        label[0]->setText("Время удвоения, c");
        label[1]->setText("Начальная мощность, %");
        label[2]->setText("Конечная мощность, %");
        label[3]->setText("Текущее время, c");
        label[4]->setText("Текущая мощность, %");
    }

    btn_start = new QPushButton("Ввод");
    btn_start->setShortcut(QKeySequence(Qt::Key_Return));
    btn_start ->setEnabled(false);

    QHBoxLayout *btn_layout =new QHBoxLayout;
    btn_layout->addStretch(1);
    btn_layout->addWidget(btn_start);

    time = new ULineEdit(this);
    power_S = new ULineEdit(this);
    power_F = new ULineEdit(this);
    out_time =new QLineEdit(this);
    out_power = new QLineEdit(this);

    time->min = -900;
    time->max = 900;
    power_S->min = 1e-08;
    power_S->max = 1.5e2;
    power_F->min = 1e-08;
    power_F->max = 1.5e2;
    time->setMaximumWidth(QFontMetrics(time->font()).width("_+00000_")+10);
    power_S->setMaximumWidth(QFontMetrics(power_S->font()).width("_+0.00E-00_")+10);
    power_F->setMaximumWidth(QFontMetrics(power_F->font()).width("_+0.00E-00_")+10);

    time->setMaxLength(5);
    power_S->setMaxLength(9);
    power_F->setMaxLength(9);

    out_time->setReadOnly(true);
    out_power->setReadOnly(true);
    out_power->setMaximumWidth(QFontMetrics(out_power->font()).width("_+0.00E-00_")+10);
    out_time->setFocusPolicy(Qt::NoFocus);
    out_time->setMaximumWidth(QFontMetrics(out_time->font()).width("_+0.00E-00_")+10);
    out_power->setFocusPolicy(Qt::NoFocus);

    layout[0]->addWidget(time);
    layout[1] ->addWidget(power_S);
    layout[2] ->addWidget(power_F);
    layout[3]->addWidget(out_time);
    layout[4]->addWidget(out_power);

    layout[3]->addSpacerItem(new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Minimum));
    layout[4]->addSpacerItem(new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Minimum));

    connect(power_S,SIGNAL(textChanged(QString)),this,SLOT(slotEnabledStart(QString)));
    connect(power_F,SIGNAL(textChanged(QString)),this,SLOT(slotEnabledStart(QString)));
    connect(time,SIGNAL(textChanged(QString)),this,SLOT(slotEnabledStart(QString)));
    connect(btn_start,SIGNAL(clicked()),this,SLOT(start()));

    QVBoxLayout *top_layout = new QVBoxLayout;

    for(int i=0;i<3;i++)
        top_layout->addLayout(layout[i]);

    top_layout->addSpacing(20);
    top_layout->addLayout(layout[3]);
    top_layout->addLayout(layout[4]);

    top_layout->addSpacing(50);
    top_layout->setMargin(0);
    top_layout->addLayout(btn_layout);
    top_layout->addSpacerItem(new QSpacerItem(0,0,QSizePolicy::Minimum,QSizePolicy::Expanding));

    this->setLayout(top_layout);

    power_S->setInputMask("0.00e#0");
    power_S->setText("1.00e-8");

    power_F->setInputMask("0.00e#0");
    power_F->setText("1.50e+2");

    time->setText("20");
}

void PeriodImit::slotEnabledStart(QString){

    bool enabled = power_S->valid & power_F->valid & time->valid;
    bool df;
    float N_St = power_S->value();
    float N_En = power_F->value();
    float T = time->value();

    if ((-1<=T )&&(T<=5)){
        df =false;
    }
    else if((T>0) && (N_St<N_En))
        df =true;
    else if((T<0) && (N_St>N_En))
        df =true;
    else
        df =false;

    btn_start->setEnabled(enabled & df);
}

void PeriodImit::start(){

    if(step==3)
        step=0;

    if(step==0){
        time->setEnabled(true);
        power_S->setEnabled(true);
        power_F->setEnabled(true);

        btn_start->setText("Ввод");
        emit mode_imit(0);
        timer->stop();
    }
    else if(step ==1){

        out_time->setText("0");
        out_power->setText("0");

        time->setEnabled(false);
        power_S->setEnabled(false);
        power_F->setEnabled(false);

        emit mode_imit(2);

        btn_start->setText("Старт");
        usec=0;
        float N_St = power_S->value();
        float N_En = power_F->value();
        float T = time->value();

        QVector <float> data;
        data.append(N_St);
        data.append(N_En);
        data.append(T);

        emit send(data);
    }
    else  {


        timer->start(100);
        btn_start->setText("Стоп");
        emit mode_imit(3);}

    step++;
    btn_start->setShortcut(QKeySequence(Qt::Key_Return));
}


void PeriodImit::input_power(float val){

    out_power->setText(QString::number(val,'e',2));
}

void PeriodImit::input_time(){

    usec =usec+1;
    out_time->setText(QString::number(usec));
}

void PeriodImit::reset(){

    step=0;
    start();
    out_time->setText("0");
    out_power->setText("0");

}
