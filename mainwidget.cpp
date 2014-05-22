#include "mainwidget.h"

extern QMap <int,QVector<int> > GlBuffer;

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent)


{

    this->modeImit = false;

    QHBoxLayout *top_layout = new QHBoxLayout;
    QVBoxLayout *main_layout = new QVBoxLayout;

    QVBoxLayout *right_layout = new QVBoxLayout;

    rightCombo = new QComboBox(this);
    rightCombo->setFixedWidth(200);

    QHBoxLayout  *comboLayout= new QHBoxLayout;

    {   rightCombo->addItem("АКНП");
        rightCombo->addItem("АКЭ(Слайд 1)");
        rightCombo->addItem("АКЭ(Слайд 2)");
        rightCombo->addItem("АКР");
        rightCombo->addItem("ПУМ-514Р");

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
        leftCombo->addItem("Откл  имитатор");
    }

    QVBoxLayout *leftLayout =new QVBoxLayout;
    {
        //    leftLayout->addWidget(leftCombo);
        leftLayout->addWidget(Slide_imitator = new aknp_imit(this));
        leftLayout->addStretch(1);

    }
    rightStack = new QStackedWidget(this);
    {
        rightStack ->addWidget(SlideValueDiap = new aknp_out(rightStack));
        rightStack->addWidget(Slide_AKE0 = new ake_01(rightStack));
        rightStack->addWidget(Slide_AKE1 = new ake_02(rightStack));
        rightStack->addWidget(Slide_akr = new akr_widget(rightStack));
        rightStack->addWidget(listParametrer = new ParamTable(rightStack));
    }
    //    Slide_akr ->setFixedWidth(520);
    connect(rightCombo,SIGNAL(activated(int)),rightStack,SLOT(setCurrentIndex(int)));
    connect(leftCombo,SIGNAL(activated(int)),this,SLOT(enableImit(int)));

    comboLayout->addWidget(leftCombo);
    comboLayout ->addWidget(rightCombo);
    // right_layout->addLayout(comboLayout);
    right_layout->addWidget(rightStack);
    //rightStack->setFixedWidth(600);


    top_layout->addLayout(leftLayout);
    //Slide_imitator = new aknp_imit(this);

    top_layout->addLayout(right_layout);
    top_layout->addStretch(1);

    //this->setLayout(top_layout);

    connect(Slide_imitator,SIGNAL(send(QVector<int>)),this,SIGNAL(sendCan(QVector<int>)));
    //connect(this,SIGNAL(select(const QVector<int>&)),this,SLOT(sel(const QVector<int>&)));
    connect(Slide_akr,SIGNAL(send(QVector<int>)),this,SIGNAL(sendCan(QVector<int>)));
    connect(listParametrer,SIGNAL(send(QVector<int>)),this,SIGNAL(sendCan(QVector<int>)));
    //  this->setStyleSheet("background-color:rgb(120,120,120);color:black");

    connect(leftCombo,SIGNAL(activated(int)),Slide_imitator->stack,SLOT(setCurrentIndex(int)));
    connect(leftCombo,SIGNAL(activated(int)),Slide_imitator,SLOT(stopFreq(int)));

    label = new QLabel();
    comboLayout->addWidget(label);

    main_layout->addLayout(comboLayout);
    main_layout->addLayout(top_layout);
    //main_layout->addWidget(label);

    this->setLayout(main_layout);

    //  connect(SlideValueDiap,SIGNAL(sendCodErr()),this,SLOT(setStatusBar()));

    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(slotUpdateGui()));
    timer->start(300);

}

void MainWidget::slotUpdateGui(){

    QMapIterator <int,QVector<int> > it(GlBuffer);

    while (it.hasNext()) {
          it.next();
        SlideValueDiap->select(it.key(),it.value());
        Slide_AKE0->selectId(it.key(),it.value());
        Slide_AKE1->selectId(it.key(),it.value());
        Slide_akr->select(it.key(),it.value());
        Slide_imitator->select(it.key(),it.value());
        listParametrer->selectId(it.key(),it.value());

    }
    setStatusBar();
}

    void MainWidget::setStatusBar(){

        int cod_aknp = SlideValueDiap->getCodErr();
        int cod_akr = Slide_akr->err;
        int err = cod_akr << 3 | cod_aknp;
        QString str = "Нет связи с ";
       // qDebug() << "er cod" << cod_aknp;

        switch(err){
        case 0:
            label->clear();
            break;
        case 0b001:
            str = str + " ПУМ-514Р1";
            break;
        case 0b010:
            str = str + " ПУМ-514Р";
            break;
        case 0b011:
            str = str + " ПУМ-514Р, ПУМ-514Р1";
            break;
        case 0b100:
            str = str + "ПУМ-509Р";
            break;
        case 0b110:
            str = str + "ПУМ-509Р ПУМ-514Р";
            break;
        case 0b101:
            str = str+" ПУМ-509Р ПУМ-514Р1";
            break;
        case 0b111:
            str = str+" ПУМ-509Р ПУМ-514Р ПУМ-514Р1";
            break;
        default:
            break;
        };

        if(err==0)
            label->clear();
        else
            label->setText(str);
    }

    void MainWidget::enableImit(int n){

        if(n==6)
            Slide_imitator->setVisible(false);
        else
            Slide_imitator->setVisible(true);
    }

    MainWidget::~MainWidget(){

        delete SlideValueDiap;
        delete Slide_AKE0;
        delete Slide_AKE1;
        delete Slide_akr;
        delete Slide_imitator;

        qDebug() <<"delete ";
    }
