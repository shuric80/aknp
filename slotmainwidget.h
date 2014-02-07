#ifndef SLOTMAINWIDGET_H
#define SLOTMAINWIDGET_H
#include "mainwidget.h"

class SlotMainWidget : public MainWidget
{
public:
    SlotMainWidget();

 public slots:

    void selectId(const QVector<int>&);

};

#endif // SLOTMAINWIDGET_H
