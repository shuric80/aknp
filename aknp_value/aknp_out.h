#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtGui/QVBoxLayout>
#include "pd_diaposon.h"
#include "rd1_diaposon.h"
#include "rd2_diaposon.h"
#include "top_diapason.h"
#include "QLed/qled.h"
#include <QtGui/QLineEdit>
//#include "akeslideimitator.h"

//#include "ake_01.h"
//#include "ake_02.h"

class aknp_out : public QWidget
{
    Q_OBJECT

public:
    explicit aknp_out(QWidget *parent = 0);
    //~MainWindow();

private:
    top_diaposon *TWidget;
    pd_diaposon  *PDWidget ;
    rd1_diaposon *RD1Widget;
    rd2_diaposon *RD2Widget;

    QString style_0;
    QString style_1;

    bool discret(int,int);
    QLabel *label[3];
    QLabel *ind[4];
    int count[2];
    QTimer *timer[2];
     float toFloat(QVector<int>);


public slots:
    void select(const QVector<int>&);
  };

#endif // MAINWINDOW_H
