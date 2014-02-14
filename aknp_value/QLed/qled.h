#ifndef QFLASHLED_H
#define QFLASHLED_H

#include <QtGui/QWidget>
#include <QtGui/QPainter>
#include <QTimer>
#include <iostream>
#include <QtGui/QFrame>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>

#define  H_SIZE 15
#define  V_SIZE 8
#define  Rd 9
class QLed : public QWidget
{
    Q_OBJECT
public:
    explicit QLed(QWidget *parent=0);

protected:
    void paintEvent(QPaintEvent *event);
public:
    void setLed(bool);
    void setText(QString);
    void setColor(QString);
private:
    int  on;
    int off;
    QString str;
    int on_color;
    int off_color;
    bool set;

};

#endif // QFLASHLED_H
