#include "topclass.h"


TopClass::TopClass(QObject *parent) :
    QObject(parent)
{
    thread = new CanThread;

    widget = new SlotMainWidget;
    widget->setWindowState(widget->windowState() ^ Qt::WindowFullScreen);
    widget->setFixedSize(800,600);
    widget->show();

}
