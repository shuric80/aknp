
#ifndef OUTWIDGET_H
#define OUTWIDGET_H

#include <QtGui/QWidget>
#include"QLed/qled.h"
#include <QtGui/QLineEdit>

class outWidget : public QWidget
{
    Q_OBJECT
    //
public:
    explicit outWidget( QWidget *parent = 0);
    ~outWidget();
  
    QLed *led[15];
    QLabel *analog_lab[8];
    QLineEdit *analog[6];
    volatile int err;
    void set_analog(unsigned int,float,int mode = 0);
    void set_discret(unsigned int,bool);
public slots:
	void clean();
       
};

#endif // OUTWIDGET_H
