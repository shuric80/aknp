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

  connect(cansocket,SIGNAL(read_ok(const QVector<int>&)),this,SLOT(rx_buffer(const QVector<int>&)));
  connect(cansocket,SIGNAL(read_ok(const QVector<int>&)),this,SIGNAL(emitRxBuf(const QVector<int>&)));

   connect(this,SIGNAL(emitTxBuf(QVector<int>)),cansocket,SLOT(slot_save(QVector<int>)));

  thread->start();
}


void CanThread::rx_buffer(const QVector<int> &value){

 extern bool debug_dd;



 if(debug_dd && (value.at(0) == 0x107))

     dd_0 = value.mid(1,8);

 else if(debug_dd &&(value.at(0) == 0x404)){
     dd_1 = value.mid(5,4);
     qDebug()<< "dd:0x107 " << bin << dd_0 << "/t" << "0x404 " <<bin << dd_1;
}
     else{}

}


void CanThread::tx_buffer(QVector<int> data){

  cansocket->slot_save(data);
}


CanThread::~CanThread(){

  emit stopAll();
  delete thread;
}
