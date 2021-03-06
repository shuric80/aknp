
#include <QtGui/QApplication>
#include "topclass.h"
#include <QDebug>
#define DEBUG false
#include <QTextCodec>
#include "outlog.cpp"

bool debug_rd = false;
bool debug_wr = false;
bool debug_dd = false;

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(argv[1] == QString("-debug")){
        if(argv[2] == QString("rd"))
            debug_rd = true;
        if(argv[2] == QString("wr"))
            debug_wr = true;
        if(argv[2] == QString("dd"))
            debug_dd = true;

    }

    qInstallMsgHandler(myMessageOutput);
   
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8")); //изменения
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8")); //изменения
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8")); //изменения

    TopClass w;

    
    return a.exec();
}
