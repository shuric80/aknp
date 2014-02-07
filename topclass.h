#ifndef TOPCLASS_H
#define TOPCLASS_H

#include <QObject>
#include "slotmainwidget.h"
#include "canthread.h"

class TopClass : public QObject
{
    Q_OBJECT
public:
    explicit TopClass(QObject *parent = 0);
    
private:
    CanThread *thread;
    SlotMainWidget *widget;
};

#endif // TOPCLASS_H
