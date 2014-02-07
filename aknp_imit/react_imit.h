#ifndef REACT_IMIT_H
#define REACT_IMIT_H

#include <QtGui/QWidget>
#include "ulineedit.h"

#include <QDebug>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QLineEdit>
#include <QtGui/QHBoxLayout>
#include <QtGui/QVBoxLayout>
#include <QtGui/QPushButton>

class react_imit : public QWidget
{
    Q_OBJECT
public:
  explicit react_imit( bool, QWidget *parent = 0);
signals:
    void send(QVector<float>);
    void mode_imit(int);
private:
  bool mode;
  int step;
  quint64 usec;

  ULineEdit *react;
  ULineEdit *time;
  ULineEdit *power_S;
  ULineEdit *power_F;
  QLineEdit *out_power;
  QLineEdit *out_time;
  QLineEdit *out_react;
  QPushButton *btn_start;
  QTimer *timer;
 // QPushButton *btn_input;
public slots:
  void slotEnabledStart(QString);
  void start();
  
  void input_power(float);
  void input_react(float);
  void input_time();
  void reset();

    
signals:
    
public slots:
    
};

#endif // REACT_IMIT_H
