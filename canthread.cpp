    #include "canthread.h"
#include <QtCore>

CanThread::CanThread(QObject *parent) :
  QObject(parent)
{
 qRegisterMetaType <QVector<int> > ("QVector<int>");

}

void CanThread::addThread(){
//  qDebug()<<"add";  
 
  cansocket = new CanSocketDriver; 
  thread = new QThread;
  cansocket ->moveToThread(thread);

  connect(thread,SIGNAL(started()),cansocket,SLOT(slot_thread_read()));
  connect(cansocket,SIGNAL(finished()),thread,SLOT(quit()));
  connect(this,SIGNAL(stopAll()),cansocket,SLOT(stop()));
  connect(cansocket,SIGNAL(finished()),cansocket,SLOT(deleteLater()));
  connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));

  connect(this,SIGNAL(emitTxBuf(QVector<int>)),cansocket,SLOT(slot_save(QVector<int>)));

  thread->start();
}

void CanThread::rx_buffer(const QVector<int> &value){

}

void CanThread::tx_buffer(QVector<int> data){

  cansocket->slot_save(data);
}

CanThread::~CanThread(){

  emit stopAll();
  delete thread;
}
