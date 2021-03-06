#include <qapplication.h>
#include <stdio.h>
#include <stdlib.h>
#include <QFile>

void myMessageOutput(QtMsgType type, const char *msg) {
    

    switch (type) {
         case QtDebugMsg:
             fprintf(stderr, "Debug: %s\n", msg);           
             break;
         case QtWarningMsg:
             fprintf(stderr, "Warning: %s\n", msg);
             break;
         case QtCriticalMsg:
             fprintf(stderr, "Critical: %s\n", msg);
             break;
         case QtFatalMsg:
             fprintf(stderr, "Fatal: %s\n", msg);
             abort();
         }

   }
