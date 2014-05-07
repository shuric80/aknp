#include <QFile>
#include <QDateTime>
#include <QDebug>
#include <QTextStream>

void myMessageOutput(QtMsgType type, const char *msg)
{
    QFile fMessFile("/home/sniip/log/AKNPLog.log");
    if(!fMessFile.open(QIODevice::Append | QIODevice::Text)){
        return;
    }
    QString sCurrDateTime = "[" + QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss.zzz") + "]";
    QTextStream tsTextStream(&fMessFile);
    switch(type){
    case QtDebugMsg:
        tsTextStream << QString("Debug%1: %2\n").arg(sCurrDateTime).arg(msg);
        break;
    case QtWarningMsg:
        tsTextStream << QString("Warning%1: %2\n").arg(sCurrDateTime).arg(msg);
        break;
    case QtCriticalMsg:
        tsTextStream << QString("Critical%1: %2\n").arg(sCurrDateTime).arg(msg);
        break;
    case QtFatalMsg:
        tsTextStream << QString("Fatal%1: %2\n").arg(sCurrDateTime).arg(msg);
        abort();
    }
    tsTextStream.flush();
    fMessFile.flush();
    fMessFile.close();
}
