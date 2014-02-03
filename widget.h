#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    QLabel *label_0[10];
	QLabel *label_1[10];
	QLabel *label_2[10];
	QLabel *label_3[10];
    QString str[10][4];
};

#endif // WIDGET_H
