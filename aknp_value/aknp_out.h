#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QVBoxLayout>
#include "pd_diaposon.h"
#include "rd1_diaposon.h"
#include "rd2_diaposon.h"
#include "top_diapason.h"
#include "QLed/qled.h"
#include <QtGui/QLineEdit>


class aknp_out : public QWidget
{
    Q_OBJECT

public:
    explicit aknp_out(QWidget *parent = 0);
    volatile quint8 err;
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
    quint8 prev_cnt[2];

   inline float toFloat(const QVector<int>&);

public slots:
    void select(int id, const QVector<int>&);
    void setErr();

signals:
    void sendCodErr();
  };

#endif // MAINWINDOW_H
