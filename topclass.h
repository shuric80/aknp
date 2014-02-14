#ifndef TOPCLASS_H
#define TOPCLASS_H

#include <QWidget>
#include "mainwidget.h"
#include "canthread.h"

class TopClass : public QWidget
{
    Q_OBJECT
public:
    explicit TopClass(QWidget *parent = 0);
    
private:
    CanThread *thread;
    MainWidget *widget;
signals:
    void sendInCan(QVector<int>);
    void select(const QVector<int>&);
};

#endif // TOPCLASS_H
