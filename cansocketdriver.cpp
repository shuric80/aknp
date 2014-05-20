#include "cansocketdriver.h"
#include <iostream>
#include <fcntl.h>

#define MXCAN_NAME  "mxcan1"

extern QMap<int, QVector<int> > GlBuffer;

CanSocketDriver::CanSocketDriver(QObject *parent) :
    QObject(parent)
{
    qRegisterMetaType <QVector<int> > ("QVector<int>");  // register signal  <QVector<int> >
    stopped = false;
    rx_s =0;
    cnt=0;


    rx_s =::socket(PF_CAN,SOCK_RAW,CAN_RAW);


    if(rx_s <0){
        qCritical()<<"Error open socket";
        this->stop();
    }

    addr.can_family = PF_CAN;
    ::strcpy(ifr.ifr_name,MXCAN_NAME);

    if(::ioctl(rx_s,SIOCGIFINDEX,&ifr)){
        qCritical() << "Error ioctl";
        this->stop();
    }

    addr.can_ifindex = ifr.ifr_ifindex;

    if(::bind(rx_s,(struct sockaddr *)&addr,sizeof(addr))<0){
        qCritical() << "Error bind";
        this->stop();
    }

    ::fcntl(rx_s,F_SETFL);//,O_NONBLOCK);
}


void CanSocketDriver::slot_thread_read(){

    QVector<int> buffer(9,0);

    while(!stopped){

        ssize_t ret = ::recv(rx_s, &frame, sizeof(struct can_frame),0);
    
        if(ret ==-1){
            qWarning() << "Error read";
        }
        else{

            int id = (int)frame.can_id;
            
            for(int i=0;i<frame.can_dlc;i++)
                buffer[i] =frame.data[i];

            buffer[8] = cnt++;

            GlBuffer[id] = buffer;
        }
        qApp->processEvents();
    }
    stopped = false;
}


void CanSocketDriver::slot_save(QVector<int> data){

    struct can_frame frame_tx;
    frame_tx.can_id = data.at(0);

    int len = data.size()-1;

    frame_tx.can_dlc = len;

    for(int i =0;i<len;i++)
        frame_tx.data[i] = data.at(i+1);

    ssize_t ret = ::send(rx_s,&frame_tx,sizeof(struct can_frame),0);



    if(ret==-1)
        qWarning()<<"Error send in CAN: 0x" <<hex <<  frame_tx.can_id;
}

void CanSocketDriver::stop(){

     qCritical()<<"Stop read";
     stopped = true;
}

CanSocketDriver::~CanSocketDriver(){

    emit finished();
    }


