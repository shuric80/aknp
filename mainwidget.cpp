#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent)
{

    QFont font("Arial cyr",12);
    this->setFont(font);



    QHBoxLayout *top_layout = new QHBoxLayout;

    QVBoxLayout *right_layout = new QVBoxLayout;
    {
        rightCombo = new QComboBox(this);
        {
            rightCombo->addItem("Слайд 1");
            rightCombo->addItem("Слайд 2");
        }

        rightStack = new QStackedWidget(this);
        rightStack->addWidget(slide_0 = new ake_01(rightStack));
        rightStack->addWidget(slide_1 = new ake_02(rightStack));

        connect(rightCombo,SIGNAL(activated(int)),rightStack,SLOT(setCurrentIndex(int)));

        right_layout->addWidget(rightCombo);
        right_layout->addWidget(rightStack);
    }

    top_layout->addWidget(imitator = new aknp_imit(this));
    top_layout->addStretch(1);
    top_layout->addLayout(right_layout);

   // this->setStyleSheet("background-color:qlineargradient(x1: 0,y1: 0,x2: 0,y2: 1,\
    //                    stop:0#aaaaaa,stop: 0.5 #434343,stop: 0.31 #000000, stop: 1 #585c5f)");

    this->setStyleSheet("background-color:rgb(100,100,100)");
    this->setLayout(top_layout);
}
