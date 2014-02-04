#include <QtGui/QApplication>
//#include "widget.h"
#include "ake_01.h"
#include "ake_02.h"

#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8")); //изменения
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8")); //изменения
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8")); //изменения

    ake_02 w;
    w.setWindowState(w.windowState() ^ Qt::WindowFullScreen);
    w.setFixedSize(400,600);
    w.show();
    
    return a.exec();
}
