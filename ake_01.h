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
QString str[10][2];

private slots:
    void selectId(const QVector<int>&);
    int toInt(const QVector<int>&);
    float toFloat(const QVector<int>&);
    
};

#endif // AKE_01_H
