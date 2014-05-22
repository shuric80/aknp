    #include "topclass.h"


TopClass::TopClass(QWidget*parent) :
    QWidget(parent)
{
    thread = new CanThread;
    thread->addThread();
    widget = new MainWidget;
    aop = new outLogAop;

    QFile styleFile("main.qss");
    if( styleFile.open(QFile::ReadOnly) ) {
        QString styleSheet = QLatin1String(styleFile.readAll());
        widget->setStyleSheet(styleSheet);
    }
    else
        qWarning() << "Style can't be loaded.";


    connect(widget,SIGNAL(sendCan(QVector<int>)),thread,SLOT(tx_buffer(QVector<int>)));
    //connect(thread,SIGNAL(emitRxBuf(const QVector<int>&)),widget,SLOT(sel(const QVector<int>&)));
    connect(widget,SIGNAL(destroyed()),thread,SLOT(deleteLater()));
   // connect(thread,SIGNAL(emitRxBuf(QVector<int>)),aop,SLOT(select(const QVector<int>&)));
    //connect(thread,SIGNAL(emitRxBuf(const QVector<int>&)),widget,SIGNAL())
    widget->setWindowState(widget->windowState() ^ Qt::WindowFullScreen);
    widget->setFixedSize(810,610);
    widget->show();
}
