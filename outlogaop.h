#ifndef AOP_FILE
#define AOP_FILE

#include <QFile>
#include <QDataStream>
#include <QVector>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <QTimer>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <QTime>


#pragma pack(push,1)

typedef struct packet_t{

    float power_current;           //1
    float power_rd2;               //2
    float power_rd1;               //3
    float power_pd;                //4
    float power_id;                //5
    float set_power_rd2;           //6
    float set_power_rd1;           //7
    float set_power_pd;            //8
    float set_power_id;            //9

    short time_current;            //10
    short time_rd1;                //11
    short time_pd;                 //12
    short time_id;                 //13
    short set_time_rd1;            //14
    short set_time_pd;             //15
    short set_time_id;             //16

    float nocorrect_power;         //17
    float Kkor;                    //18
    float AO;                      //19

    float Kz1;                      //20
    float Kz2;
    float Kz3;
    float Kz4;
    float Kz5;
    float Kz6;
    float Kz7;
    float Kz8;
    float Kz9;
    float Kz10;

    float Tcold;                   //21
    float T1;                      //22
    float T2;                      //23

    short   Fn;
    short   Fsr;
    short   Fv;
    short   Fkor;
    short   H1;
    short   H2;
    short   H3;
    float   Tef;
    float   Tkf;
    float   _a3;
    float   a0kf;
    float   a2;
    float   a3;
    float   a4;
    float   Q2;
    float   Q3;
    float   ah;
    float   ad;
    float   at;
    float   aw;
    float   beff;
    float   power_for_react;

    quint16 discret_0;      //24
    quint16 discret_1;      //25
    quint16 discret_2;      //26
    quint16 discret_3;      //27
    quint16 discret_4;      //28

    
   
}   packet;

#pragma pack(pop)

typedef int socket_t;

class  outLogAop:public QObject{

    Q_OBJECT

public:
    explicit  outLogAop(const char port[20]= "/dev/ttyS0",QObject *parent =0);
    ~outLogAop();

public slots:

    void select(const QVector<int>&);
    void send();
    void watchDogTimerSlot();
private:
    char port[20];
    unsigned int dd_0;
    unsigned int dd_1;
    unsigned int dd_2;
    unsigned int dd_3;
    unsigned int dd_4;
    int pd;

    QTime time;
   // QFile file;
   // QDataStream out;
    packet pack;
    QTimer  *timer;
    QTimer *watchDogTimer;
    float swapIntFloat(const QVector<int>&);
    float swapIntFloat(int);

    float toFloat(const QVector<int>&);
    int  toInt(const QVector<int>&);
    int  IntToInt_10(const QVector<int> &,float n=1);
    int CoderCommand10hRTU_List(unsigned char, unsigned char*,int, unsigned char*);
    unsigned short crc_sum(unsigned char*, int);
   unsigned int toBool(int,int,int);
    
   // socket_t sock;
   // sockaddr_in local_addr;		// local address and port to bind
   // sockaddr_in remote_addr;	// remote address and port to send buffers

};

#endif
