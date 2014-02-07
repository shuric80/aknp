    #ifndef CANSOCKETDRIVER_H
#define CANSOCKETDRIVER_H

#include <sys/socket.h>
#include <sys/types.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <netinet/in.h>


#include <QObject>
#include <QVector>
#include <QtCore>
#include <QDebug>
#include <QMutex>

#include <QtNetwork/QLocalSocket>

using namespace std;

class CanSocketDriver : public QObject
{
  Q_OBJECT
public:
  explicit CanSocketDriver(QObject *parent = 0);
  ~CanSocketDriver();

signals:
  void finished();
  void read_ok(const QVector<int>&);

public slots:
  void slot_thread_read();
  void slot_save(QVector<int>);
  void stop();

private:
  QVector <int> buffer;
  volatile bool stopped;
  int rx_s;
  struct sockaddr_can addr;
  struct ifreq ifr;
  struct can_frame frame;
 // QMutex mutex;

 // QAbstractSocket *sock;

};

#endif // CANSOCKETDRIVER_H
