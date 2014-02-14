#ifndef CANTHREAD_H
#define CANTHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <cansocketdriver.h>

class CanThread : public QObject{

  Q_OBJECT
 public:
  explicit CanThread(QObject *parent = 0);
  ~CanThread();

  void addThread();

signals:
  void stopAll();
  void send(const QString);
  void emitRxBuf(const QVector<int>&);
  void emitTxBuf(QVector<int>);

public slots:
   void rx_buffer(const QVector<int>&);
   void tx_buffer(QVector<int>);
   

 private:
  QThread *thread;
  CanSocketDriver *cansocket;
};

#endif // CANTHREAD_H
