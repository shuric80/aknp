
#include <QtGui/QApplication>
#include "topclass.h"
#include <QDebug>
#include <QTextCodec>
#include "outlog.cpp"
#include <QMap>
#include <QVector>

using namespace std;
QMap<int, QVector<int> > GlBuffer;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   // qInstallMsgHandler(myMessageOutput);

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8")); //изменения
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8")); //изменения
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8")); //изменения

    TopClass w;

    
    return a.exec();
}
