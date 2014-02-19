#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

#include "aknp_imit/aknp_imit.h"
#include "aknp_value/ake_01.h"
#include "aknp_value/ake_02.h"
#include "akr/akr_widget.h"
#include <QComboBox>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "aknp_value/aknp_out.h"


class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = 0);
    QStackedWidget *rightStack;

private:
   aknp_out *SlideValueDiap;
    aknp_imit *Slide_imitator;
    ake_01 *Slide_AKE0;
    ake_02 *Slide_AKE1;
    akr_widget *Slide_akr;
    QComboBox *leftCombo;
    QComboBox *rightCombo;
    //QStackedWidget *rightStack;
public slots:

   void  sel(const QVector<int>&);
signals:
    void sendCan(QVector<int>);
    void select(const QVector<int>&);
    

};

#endif // MAINWIDGET_H
