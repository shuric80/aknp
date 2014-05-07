#ifndef VERIFY_H
#define VERIFY_H
#include <QtGui/QWidget>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QLabel>

class verify:public QWidget{

   Q_OBJECT

public:
  explicit verify(QWidget *parent =0);
private:
 
  QPushButton *button[3];
  //QPushButton *btn_start;
  int set_verify;
  bool start_process;

public slots:
  void start_np(bool);

 signals:
  void send_verify(int);

};

#endif
