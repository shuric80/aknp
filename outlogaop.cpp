#include "outlogaop.h"
#include <QDebug>
#define AOP_PORT "/dev/ttyS0"

outLogAop::outLogAop(QObject *parent):QObject(parent){

    timer = new QTimer(this);


    //   sock = socket(AF_INET,SOCK_DGRAM,0);
    //   if(sock == -1)
    //      qWarning()<< "Error open sock";

    //   local_addr.sin_family = AF_INET;
    //   local_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    //   local_addr.sin_port = htons(6014);

    memset(&pack,0,sizeof(pack));
    // setNG =120%

    // pack.set_NG = 120;

    connect(timer,SIGNAL(timeout()),this,SLOT(send()));   //connect timer
  //  timer->start(100);
}



void outLogAop::select(const QVector<int> &val){

    QVector <int> value;
    value << val;

    int id  = value.at(0);

    QVector<int> data_l;// << data.mid(1,4);
    QVector<int> data_h;// << data.mid(5,4);
    data_h << value.mid(5,4);
    data_l << value.mid(1,4);


    switch(id){

    case 0x401:
        pack.power_rd2 = toFloat(data_l);
        pack.set_power_rd2 = toFloat(data_h);
        break;
    case 0x403:
        pack.Fn = IntToInt_10(value.mid(1,2),1.1111);
        pack.Fv = IntToInt_10(value.mid(3,2),1.1111);//
        pack.Fsr =IntToInt_10(value.mid(5,2),1.1111);//
        // pack.Fkor =(value.at(7)<<8  | value.at(8);//toInt(value.mid(7,2));
        break;
    case 0x404:
        pack.Fkor = IntToInt_10(value.mid(1,2),1.1111);

        dd_0 = 0;
        dd_3 = 0;

        dd_0 |= toBool(value.at(5),0,0); //az rd2
        dd_0 |= toBool(value.at(5),1,1); //pz rd2
        dd_0 |= toBool(value.at(5),2,2); // pm n
        //        dd_0 |= toBool(value.at(5),3,4); // rd2

        dd_0 |= toBool(value.at(5),4,12); // n>5
        dd_0 |= toBool(value.at(5),5,15);  //n>75
        dd_0 |= toBool(value.at(5),6,3);  //error


        dd_3 |= toBool(value.at(6),4,12); //correct +
        dd_3 |= toBool(value.at(6),5,13); //correct -
        dd_3 |= toBool(value.at(6),6,0); // er
        dd_0 |= toBool(~value.at(6),7,7);//    proverka

        dd_0 |= toBool(~value.at(7),5,6);  // er aknp
        dd_0 |= toBool(value.at(7),6,8);  // az n
        dd_0 |= toBool(value.at(7),7,9);  // pz n

        dd_4 &= 0x1FF;    //  set flag read pum 514r1   if ok to dd4=0;


        //dd_0 |= toBool(value.at(8),6,2); //pz-2 n    rd2

        break;
    case 0x405:
        pack.AO = toFloat(data_l);
        pack.nocorrect_power = toFloat(data_h);
        break;
    case 0x406:
        pack.Kz1 = swapIntFloat(value.at(1));
        pack.Kz2 = swapIntFloat(value.at(2));
        pack.Kz3 = swapIntFloat(value.at(3));
        pack.Kz4 = swapIntFloat(value.at(4));
        pack.Kz5 = swapIntFloat(value.at(5));
        pack.Kz6 = swapIntFloat(value.at(6));
        pack.Kz7 = swapIntFloat(value.at(7));
        pack.Kz8 = swapIntFloat(value.at(8));
        break;
    case 0x407:
        pack.Kz9 = swapIntFloat(value.at(1));
        pack.Kz10 = swapIntFloat(value.at(2));
        // pack.H1 = value.at(3);
        // p ack.H2 = value.at(4);
        // pack.H3 = value.at(5);
        break;
    case 0x408:
        pack.Tef = swapIntFloat(value.mid(1,2));
        pack.Tkf = swapIntFloat(value.mid(3,2));
        pack.T1 =  swapIntFloat(value.mid(5,2));
        pack.T2 =  swapIntFloat(value.mid(7,2));
        break;
    case 0x409:
        pack.Tcold = swapIntFloat(value.mid(1,2));
        pack.H1 = IntToInt_10(value.mid(3,2),0.01);
        pack.H2 = IntToInt_10(value.mid(5,2),0.01);
        pack.H3 = IntToInt_10(value.mid(7,2),0.01);
        break;
    case 0x40A:
        pack.Kkor = toFloat(value.mid(1,4));
        pack.a0kf = toFloat(value.mid(5,4));
        break;
    case 0x40B:
        pack.ah = toFloat(value.mid(1,4));
        pack.at = toFloat(value.mid(5,4));
        break;
    case 0x40C:
        pack.ad = toFloat(value.mid(1,4));
        pack.aw = toFloat(value.mid(5,4));
        break;
    case 0x40D:
        pack.Q2 = toFloat(value.mid(1,4));
        pack.Q3 = toFloat(value.mid(5,4));
        break;
    case 0x40E:
        pack.a2 = toFloat(value.mid(1,4));
        pack.a3 = toFloat(value.mid(5,4));
        break;
    case 0x40F:
        pack.a4 = toFloat(value.mid(1,4));
        pack._a3 = toFloat(value.mid(5,4));
        break;
    case 0x102:
        pack.power_rd1 = toFloat(value.mid(1,4));
        pack.set_power_rd1 = toFloat(value.mid(5,4));
        break;
    case 0x103:
        pack.time_rd1 = toInt(value.mid(1,4));
        pack.set_time_rd1 = toInt(value.mid(5,4));
        break;
    case 0x104:
        pack.power_pd = toFloat(value.mid(1,4));
        pack.set_power_pd = toFloat(value.mid(5,4));
        break;
    case 0x105:
        pack.time_pd = toInt(value.mid(1,4));
        pack.set_time_pd = toInt(value.mid(1,4));
        break;
    case 0x106:
        pack.power_current = toFloat(value.mid(1,4));
        pack.time_current = toInt(value.mid(5,4));
        break;

    case 0x107:
        dd_1=0;
        dd_2=0;
        dd_0 = ~0xC10;

        dd_1 |= toBool(value.at(1),0,1); //az n rd1
        dd_1 |= toBool(value.at(1),1,0);  //pz n rd1
        dd_2 |= toBool(value.at(1),2,2);  //az t   rd1
        dd_2 |= toBool(value.at(1),3,1);  // pz t rd1
        dd_2 |= toBool(value.at(1),4,0);  // rm t
        dd_1 |= toBool(value.at(1),6,3);  //p


        //dd_l2 |= toBool(value.at(2),0,2); //az n pd
        dd_1 |= toBool(value.at(2),0,6); //pz n pd
        dd_1 |= toBool(value.at(2),1,5); //az t   pd
        dd_2 |= toBool(value.at(2),2,7);
        dd_2 |= toBool(value.at(2),3,6); //er pd
        dd_2 |= toBool(value.at(2),4,5);
        dd_1 |= toBool(~value.at(2),6,8);

        dd_0 |= toBool(value.at(3),0,4); // rd 2
        dd_1 |= toBool(value.at(3),1,4); // rd 1
        dd_1 |= toBool(value.at(3),2,9); //  pd

        dd_0 |= toBool(value.at(6),2,10);
        dd_0 |= toBool(value.at(6),3,11);

        dd_4 &= ~0x100;  // signal read data pum-514r  if ok to       dd_4 = 0;

        //dd_1 |= toBool(value.at(4),1,0); //az n pd
        //dd_2 |= toBool(value.at(4),3,1); //pzt-1
        //dd_2 |= toBool(value.at(4),7,0); //pzt-2

        //dd_2 |= toBool(value.at(5),3,6); //pct-1 pd
        //dd_1 |= toBool(value.at(5),7,0); //pct-2  pd

        break;

    case 0x203:
        dd_4 = 0x300;

        //dd_4 = (value.at(1) & 1);

        //test
        dd_4 |= toBool(value.at(1),0,0);
        dd_4 |= toBool(value.at(1),1,3);
        dd_4 |= toBool(value.at(1),2,4);
        dd_4 |= toBool(value.at(1),3,6);
        //dd_4 |= toBool(value.at(1),4,6);
        break;

    case 0x201:
        pack.power_for_react = toFloat(value.mid(5,4));
        pack.beff = toFloat(value.mid(1,4));
        break;

    default:
        break;

    }
}

float outLogAop::toFloat(const QVector<int> &value){

    QVector<int> tmp;
    float f;
    quint8* n = (quint8*)&f;
    n[0] = value.at(1);
    n[1] = value.at(0);
    n[2] = value.at(3);
    n[3] = value.at(2);

    return f;
}

int outLogAop::toInt(const QVector<int> &value)
{

    float f;
    quint8* pr = (quint8*)&f;
    pr[0] = value.at(0);
    pr[1] = value.at(1);
    pr[2] = value.at(2);
    pr[3] = value.at(3);
    int N = (int)f;
    
    quint8 *pt = (quint8*)&N;

    int int_swap = (pt[0] <<8) | pt[1];
    
    return int_swap;
}

unsigned int outLogAop::toBool(int value, int pos, int bit){



    return ((value >> pos) &0x1)  << bit;
}

float outLogAop::swapIntFloat(int value){

    float fpr;
    float f;

    f = 0.01*(float)(value);

    quint8 *pr = (quint8*)&f;
    quint8 *tr = (quint8*)&fpr;

    tr[0]=pr[1];
    tr[1]=pr[0];
    tr[2]=pr[3];
    tr[3]=pr[2];

    return  fpr;
}

int outLogAop::IntToInt_10(const QVector<int> &value, float n){


    int data = value.at(1) << 8 | value.at(0);

    int data_10 = (int) (data*n);

    return (data_10 << 8) | (data_10) >> 8;


}

float outLogAop::swapIntFloat(const QVector<int>&value){

    float fpr;
    float f;

    f = 0.01*(float)(value.at(1)<<8 | value.at(0));


    quint8 *pr = (quint8*)&f;
    quint8 *tr = (quint8*)&fpr;

    tr[0]=pr[1];
    tr[1]=pr[0];
    tr[2]=pr[3];
    tr[3]=pr[2];

    return  fpr;


}

void outLogAop::send(){
    //    qDebug() <<"send slot";
    int oldflags;//,pd ;
    //unsigned char temp;
    struct termios termios_struct;
    //Конфигурирование порта

    pd = open(AOP_PORT,O_RDWR|O_NOCTTY);


    if(pd !=-1){
        //qDebug() << "Error open port AOP";

        oldflags = fcntl (pd, F_GETFL, 0);
        oldflags&=~O_NONBLOCK;
        fcntl (pd, F_SETFL, oldflags);
        tcgetattr(pd,&termios_struct);
        termios_struct.c_cflag|=(CLOCAL|CREAD);
        cfsetispeed(&termios_struct,B115200);
        cfsetospeed(&termios_struct,B115200);
        termios_struct.c_cflag&=~PARENB;
        termios_struct.c_cflag&=~CSTOPB;
        termios_struct.c_cflag&=~CSIZE;
        termios_struct.c_cflag|=CS8;
        termios_struct.c_lflag&=~(ICANON | ECHO | ECHOE | ISIG );
        termios_struct.c_iflag|=(INPCK | ISTRIP);
        termios_struct.c_iflag&=~IXON&~IXOFF&~IXANY&~ICRNL;
        termios_struct.c_iflag|=BRKINT;
        termios_struct.c_oflag&=~OPOST;
        termios_struct.c_cc[VMIN]=0;
        termios_struct.c_cc[VTIME]=10;
        tcsetattr(pd,TCSANOW,&termios_struct);

        quint8 *in_buf = (quint8*)&pack;
        quint8 out_buf[1000];
        unsigned char adr = 0x1;

        pack.discret_0 = ((0xff & dd_0) <<8)| ((dd_0 & 0xff00)>>8);
        pack.discret_1 = ((0xff & dd_1) <<8)| ((dd_1 & 0xff00)>>8);
        pack.discret_2 = ((0xff & dd_2) <<8)| ((dd_2 & 0xff00)>>8) ;
        pack.discret_3 = ((0xff & dd_3) <<8)| ((dd_3 & 0xff00)>>8);
        pack.discret_4 = ((0xff & dd_4) <<8)| ((dd_4 & 0xff00)>>8) ;
        //   set 0
        //     dd_0=0;
        //        dd_1=0;

        //        dd_2=0;
        //        dd_3=0;
        dd_4 = 0x301;


        int size_out = CoderCommand10hRTU_List(adr,&in_buf[0],sizeof(pack),&out_buf[0]);

        int ret_p = write (pd,&out_buf[0],size_out);


        //        qDebug()<< "size:="<< ret_p;

        if(ret_p ==-1)
            qWarning() << "Error send AOP";
        close(pd);
    }
    else
        qWarning()<<"Error open port AOP";
  // timer->stop();
  //  timer->start();


}


int outLogAop:: CoderCommand10hRTU_List(unsigned char adr,  unsigned char* date_buf,
                                        int len_comm, unsigned char* comm)
{
    int	i;
    unsigned char func = 0x10;
    unsigned int beg_adr = 1;
    unsigned int len_comm_w;
    unsigned int crc;

    len_comm_w = len_comm/2;


    // €à¥á ãáâà®©áâ¢
    comm[0] = adr;

    //äã­ªæšï
    comm[1] = func;

    //­ ç «ì­ë©  €à¥á
    comm[2] = (beg_adr & 0xFF00)>>8; //áâ.¡ ©â
    comm[3] =  beg_adr & 0x00FF;     //¬«.¡ ©â

    //ª®«-¢® á«®¢
    comm[4] = (len_comm_w & 0xFF00)>>8;//áâ.¡ ©â
    comm[5] =  len_comm_w & 0x00FF;    //¬«.¡ ©â

    //ª®«-¢® ¡ ©â
    comm[6] = (unsigned char)(len_comm);

    //€ ­­ë¥
    for (i=0; i<len_comm; i++)
    {
        comm[i+7] = date_buf[i];
    }

    //ª®­âà®«ì­ ï áã¬¬
    crc = crc_sum(comm, len_comm+7);

    comm[len_comm+7] =  crc & 0x00FF;    //¬«.¡ ©â
    comm[len_comm+8] = (crc & 0xFF00)>>8;//áâ.¡ ©â

    return (len_comm+9);
}


unsigned short outLogAop::crc_sum(unsigned char* b, int cnt)
{										// void mdrvl_sum(uchar b)
    unsigned short sum;
    unsigned int f;
    unsigned int i, j;

    sum = 0xFFFF;
    for(j = 0; j < (unsigned int)cnt; j++)
    {
        sum = sum ^ b[j];
        for(i = 0; i < 8; i++)
        {
            f = sum & 0x01;
            sum = (sum >> 1) & 0x7FFF;
            if(f)
                sum = sum ^ 0xA001;
        }
    }
    return sum;
}


outLogAop::~outLogAop(){
    //  close(sock);
    //file.close();
    //  qDebug() << "close socket , port";
}
