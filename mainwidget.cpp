#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent)
{

    //  QFont font("Arial cyr",12);
    // this->setFont(font);



    QHBoxLayout *top_layout = new QHBoxLayout;

    QVBoxLayout *right_layout = new QVBoxLayout;

        rightCombo = new QComboBox(this);
        rightCombo->setFixedWidth(200);

        {   rightCombo->addItem("АКНП");
            rightCombo->addItem("Слайд 1");
            rightCombo->addItem("Слайд 2");
            rightCombo->addItem("АКР");
            rightCombo->addItem("Параметры");
        }

        leftCombo = new QComboBox(this);
        leftCombo->setFixedWidth(250);
        {

            leftCombo->addItem("Имитатор мощности");
            leftCombo->addItem("Имитатор периода");
            leftCombo->addItem("Имитатор реактивности");
            leftCombo->addItem("Проверка имитатора реактивности");
            leftCombo->addItem("Проверка НП");
            leftCombo->addItem("Имитатор АКЭ");
            leftCombo->addItem("откл");
        }

        QVBoxLayout *leftLayout =new QVBoxLayout;
        {
            leftLayout->addWidget(leftCombo);
            leftLayout->addWidget(Slide_imitator = new aknp_imit(this));

        }
        rightStack = new QStackedWidget(this);
        {
            rightStack ->addWidget(SlideValueDiap = new aknp_out(rightStack));
            rightStack->addWidget(Slide_AKE0 = new ake_01(rightStack));
            rightStack->addWidget(Slide_AKE1 = new ake_02(rightStack));
            rightStack->addWidget(Slide_akr = new akr_widget(rightStack));
           rightStack->addWidget(listParametrer = new ParamTable(rightStack));
        }
        Slide_akr ->setFixedWidth(520);
        connect(rightCombo,SIGNAL(activated(int)),rightStack,SLOT(setCurrentIndex(int)));

        right_layout->addWidget(rightCombo);
        right_layout->addWidget(rightStack);
        //rightStack->setFixedWidth(600);


    top_layout->addLayout(leftLayout);
    //Slide_imitator = new aknp_imit(this);

    top_layout->addLayout(right_layout);
    top_layout->addStretch(1);

    this->setLayout(top_layout);

    connect(Slide_imitator,SIGNAL(send(QVector<int>)),this,SIGNAL(sendCan(QVector<int>)));
    connect(this,SIGNAL(select(const QVector<int>&)),this,SLOT(sel(const QVector<int>&)));
    connect(Slide_akr,SIGNAL(send(QVector<int>)),this,SIGNAL(sendCan(QVector<int>)));
    //  this->setStyleSheet("background-color:rgb(120,120,120);color:black");

    connect(leftCombo,SIGNAL(activated(int)),Slide_imitator->stack,SLOT(setCurrentIndex(int)));
    connect(leftCombo,SIGNAL(activated(int)),Slide_imitator,SLOT(stopFreq(int)));

  
}

void MainWidget::sel(const QVector<int>&data){
    SlideValueDiap->select(data);
    Slide_AKE0->selectId(data);
    Slide_AKE1->selectId(data);
    Slide_akr->select(data);
    Slide_imitator->select(data);
    listParametrer->selectId(data);
}
