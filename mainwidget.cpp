#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent)
{

  //  QFont font("Arial cyr",12);
   // this->setFont(font);



    QHBoxLayout *top_layout = new QHBoxLayout;

    QVBoxLayout *right_layout = new QVBoxLayout;
    {
        rightCombo = new QComboBox(this);
        rightCombo->setFixedWidth(200);
        {   rightCombo->addItem("АКНП");
            rightCombo->addItem("Слайд 1");
            rightCombo->addItem("Слайд 2");
            rightCombo->addItem("АКР");
        }

        rightStack = new QStackedWidget(this);
        rightStack ->addWidget(SlideValueDiap = new aknp_out(rightStack));
        rightStack->addWidget(Slide_AKE0 = new ake_01(rightStack));
        rightStack->addWidget(Slide_AKE1 = new ake_02(rightStack));
        rightStack->addWidget(Slide_akr = new akr_widget(rightStack));

        connect(rightCombo,SIGNAL(activated(int)),rightStack,SLOT(setCurrentIndex(int)));

        right_layout->addWidget(rightCombo);
        right_layout->addWidget(rightStack);
    }

    top_layout->addWidget(Slide_imitator = new aknp_imit(this));
    top_layout->addStretch(1);
    top_layout->addLayout(right_layout);

    this->setLayout(top_layout);

    connect(Slide_imitator,SIGNAL(send(QVector<int>)),this,SIGNAL(sendCan(QVector<int>)));
    connect(this,SIGNAL(select(const QVector<int>&)),this,SLOT(sel(const QVector<int>&)));
    connect(Slide_akr,SIGNAL(send(QVector<int>)),this,SIGNAL(sendCan(QVector<int>)));

}

void MainWidget::sel(const QVector<int>&data){
   SlideValueDiap->select(data);
   Slide_AKE0->selectId(data);
   Slide_AKE1->selectId(data);
   Slide_akr->select(data);
   Slide_imitator->select(data);
}
