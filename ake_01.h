#ifndef AKE_01_H
#define AKE_01_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>



class ake_01 : public QWidget
{
Q_OBJECT
public:
explicit ake_01(QWidget *parent = 0);
    
private:

QLabel *label[10][2];
QString str[9][2];

    
};

#endif // AKE_01_H
