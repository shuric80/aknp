#include "canthread.h"
#include <QtCore>

CanThread::CanThread(QObject *parent) :
  QObject(parent)
{
 qRegisterMetaType <QVector<int> > ("QVector<int>");


}

void CanThread::addThread(){
  
 
  cansocket = new CanSocketDriver; 
  thread = new QThread;
  cansocket ->moveToThread(thread);

  connect(thread,SIGNAL(started()),cansocket,SLOT(slot_thread_read()));
  connect(cansocket,SIGNAL(finished()),thread,SLOT(quit()));
  connect(this,SIGNAL(stopAll()),cansocket,SLOT(stop()));
  connect(cansocket,SIGNAL(finished()),cansocket,SLOT(deleteLater()));
  connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));


 // connect(cansocket,SIGNAL(read_ok(QVector<int>&)),this,SLOT(rx_buffer(QVector<int>&)));
  connect(cansocket,SIGNAL(read_ok(const QVector<int>&)),this,SIGNAL(emitRxBuf(const QVector<int>&)));
  connect(this,SIGNAL(emitTxBuf(QVector<int>)),cansocket,SLOT(slot_save(QVector<int>)));
  thread->start();
}


void CanThread::rx_buffer(QVector<int> &value){

    qDebug() << "slot";
}


void CanThread::tx_buffer(QVector<int> data){

  //qDebug() << "slot save thread";
  emit emitTxBuf(data);

}


CanThread::~CanThread(){

  emit stopAll();
}
