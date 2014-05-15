#ifndef AKE_01_H
#define AKE_01_H

#include <QWidget>

#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QHBoxLayout>

#include <QTimer>
//#include <akeslideimitator.h>


class ake_01 : public QWidget
{
Q_OBJECT
public:
    explicit ake_01(QWidget *parent = 0);

    
private:

QLabel *label[10][2];
QLineEdit *lineEdit[10][2];

QString str[10][2];
//AkeSlideImitator *ake_imit[4];

public slots:
  void selectId(const QVector<int>&);
private:
    int toInt(const QVector<int>&);
    float toFloat(const QVector<int>&);
    QString Kz;
signals:
    void enabledAKE(bool);
};

#endif // AKE_01_H
