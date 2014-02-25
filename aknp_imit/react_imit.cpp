#include "react_imit.h"
#include <QtCore>

react_imit::react_imit(bool mode, QWidget *parent) :
    QWidget(parent)
{
    this->mode = mode;

    qRegisterMetaType <QVector<float> > ("QVector<float>");
    step=1;
    usec=0;

    timer =new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(input_time()));

    QString style = QString("background-color:lightgrey;\
            color:dark; padding:0px;\
            border:0px");

    QHBoxLayout *layout[7];
    QLabel *label[7];
    for (int i=0;i<7;i++){
        layout[i] = new QHBoxLayout;
        label[i] = new QLabel;
      //  label[i]->setStyleSheet(style);
        layout[i]->addWidget(label[i]);
        layout[i]->addStretch(1);
        layout[i]->setMargin(0);
    }
    
    label[0]->setText(QString("Реактивность, %1").arg(QChar(0x03B2)));
    label[1]->setText("Время изменения, с");
    label[2]->setText("Начальная мощность, %");
    label[3]->setText("Конечная мощность, %");
    label[4]->setText(QString("Текущая реактивность, %1").arg(QChar(0x03B2)));
    label[5]->setText("Текущее время, с");
    label[6]->setText("Текущая мощность, %");

    btn_start = new QPushButton("Ввод");
    btn_start ->setEnabled(false);
    btn_start->setShortcut(QKeySequence(Qt::Key_Return));

    QHBoxLayout *btn_layout =new QHBoxLayout;
    btn_layout->addStretch(1);
    btn_layout->addWidget(btn_start);

    react = new ULineEdit;
    time = new ULineEdit;
    power_S = new ULineEdit;
    power_F = new ULineEdit;
    
    out_time =new QLineEdit;
    out_power = new QLineEdit;
    out_react = new QLineEdit;

    react->max =1.0;
    react->min=-25.0;
    time->min = 0;
    time->max = 1000;
    power_S->min = 1e-09;
    power_S->max = 1.5e2;
    power_F->min = 1e-09;
    power_F->max = 1.5e2;


    react->setMaximumWidth(QFontMetrics(react->font()).width("_+00000000_")+10);
    time->setMaximumWidth(QFontMetrics(time->font()).width("_+00000_")+10);
    power_S->setMaximumWidth(QFontMetrics(power_S->font()).width("_+0.00E-00_")+10);
    power_F->setMaximumWidth(QFontMetrics(power_F->font()).width("_+0.00E-00_")+10);

    react->setMaxLength(6);
    time->setMaxLength(5);
    power_S->setMaxLength(9);
    power_F->setMaxLength(9);

    out_time->setReadOnly(true);
    out_power->setReadOnly(true);
    out_react->setReadOnly(true);
    out_time->setFocusPolicy(Qt::NoFocus);
    out_power->setFocusPolicy(Qt::NoFocus);
    out_react->setFocusPolicy(Qt::NoFocus);
    // QFont font_out;
    //font_out.setPixelSize(12);
    //out_time->setFont(font_out);
    //out_power->setFont(font_out);
    //out_react->setFont(font_out);


    layout[0]->addWidget(react);
    layout[1]->addWidget(time);
    layout[2] ->addWidget(power_S);
    layout[3] ->addWidget(power_F);
    layout[4]->addWidget(out_react);
    layout[5]->addWidget(out_time);
    layout[6]->addWidget(out_power);

    layout[3]->addSpacerItem(new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Minimum));
    layout[4]->addSpacerItem(new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Minimum));
    layout[5]->addSpacerItem(new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Minimum));
    layout[6]->addSpacerItem(new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Minimum));

    connect(power_S,SIGNAL(textChanged(QString)),this,SLOT(slotEnabledStart(QString)));
    connect(power_F,SIGNAL(textChanged(QString)),this,SLOT(slotEnabledStart(QString)));
    connect(time,SIGNAL(textChanged(QString)),this,SLOT(slotEnabledStart(QString)));
    connect(btn_start,SIGNAL(clicked(bool)),this,SLOT(start()));

    QVBoxLayout *top_layout = new QVBoxLayout;
    top_layout->addLayout(layout[0]);
    top_layout->addLayout(layout[1]);
    top_layout->addSpacing(20);
    top_layout->addLayout(layout[2]);

    if(mode)
        top_layout->addLayout(layout[3]);

    top_layout->addSpacing(40);
    if(mode)
        top_layout->addLayout(layout[4]);
    top_layout->addLayout(layout[5]);
    top_layout->addLayout(layout[6]);
    top_layout->addSpacing(50);
    top_layout->setMargin(0);
    top_layout->addLayout(btn_layout);
    top_layout->addSpacerItem(new QSpacerItem(0,0,QSizePolicy::Minimum,QSizePolicy::Expanding));
    setLayout(top_layout);

    react->setText("0.1");
    time->setText("100");
    power_S->setInputMask("0.00e#0");
    power_S->setText("1.00e-8");
    power_F->setInputMask("0.00e#0");
    power_F->setText("1.50e+2");

btn_start->setFixedHeight(35);
}

void react_imit::slotEnabledStart(QString){
    float r = react->value();
    bool enabled = (power_S->valid )&( power_F->valid) & (time->valid);
    bool df;
    float N_St = power_S->value();
    float N_En;
    if(mode)
        N_En = power_F->value();
    else
    { if(r<0)
            N_En =1e-8;
        else
            N_En =150;
    }

    //float r = react->value();
    
    if((r> 0) && (N_St<N_En))
        df =true;
    else if((r<0) && (N_St>N_En))
        df =true;
    else if(r==0)
        df=true;
    else
        df =false;

    btn_start->setEnabled(enabled & df);
}

void react_imit::start(){

    
    if(step ==3)
        step=0;

    if(step==0){

        time->setEnabled(true);
        power_S->setEnabled(true);
        power_F->setEnabled(true);
        react->setEnabled(true);

        btn_start->setText("Ввод");
        emit mode_imit(0);
        timer->stop();
    }
    else if(step ==1){
        
        out_react->setText("0");
        out_power->setText("0");
        out_time->setText("0");

        time->setEnabled(false);
        power_S->setEnabled(false);
        power_F->setEnabled(false);
        react->setEnabled(false);

        btn_start->setText("Старт");
        usec=0;

        emit mode_imit(mode ?0b100:0b1000);

        float r = react->value();
        float N_St = power_S->value();
        float N_En;
        if(mode)
            N_En = power_F->value();
        else {
            if (r < 0)
                N_En = 1e-8;
            else
                N_En=150;
        }

        float T = time->value();

        QVector <float> data;

        data.append(N_St);
        data.append(N_En);
        data.append(T);
        data.append(r);
        data.append( mode ? 1:0);
        emit send(data);
    }

    else if(step==2) {

        timer->start(1000);
        btn_start->setText("Стоп");

        emit mode_imit(mode ? 0b101:0b1001);
    }


    else
        step=0;
    step++;
    btn_start->setShortcut(QKeySequence(Qt::Key_Return));
}

void react_imit::input_power(float val){

    out_power->setText(QString::number(val,'e',2));
}

void react_imit::input_react(float val){

    out_react->setText(QString::number(val,'g',3));
}
void react_imit::input_time(){
    usec++;
    out_time->setText(QString::number(usec));

}
void react_imit::reset(){

    step=0;
    start();
    out_react->setText("0");
    out_power->setText("0");
    out_time->setText("0");
}
