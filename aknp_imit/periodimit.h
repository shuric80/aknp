#ifndef PERIOD_H
#define PERIOD_H

#include <QtGui/QWidget>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QLineEdit>
#include <QtGui/QHBoxLayout>
#include <QtGui/QVBoxLayout>
#include <QtGui/QPushButton>
#include "ulineedit.h"
#include <QTimer>


class PeriodImit:public QWidget
{

 Q_OBJECT

public:
  explicit  PeriodImit(QWidget *parent =0);
signals:
    void send(QVector<float>);
    void mode_imit(int);

private:
  int step;
  ULineEdit *time;
  ULineEdit *power_S;
  ULineEdit *power_F;
  QLineEdit *out_power;
  QLineEdit *out_time;
  QPushButton *btn_start;
  QTimer *timer;
  quint64 usec;

public slots:
  void input_power(float);
  void reset();

private slots:
  void slotEnabledStart(QString);
  void start();
  void input_time();



};


#endif //
