#ifndef AKNP_WIDGET_H
#define AKNP_WIDGET_H

#include <QtGui/QWidget>
#include <QDebug>
#include <QtGui/QStackedWidget>
#include <QtGui/QComboBox>
#include "freqgenerator.h"
#include <QVector>
#include "react_imit.h"
#include "periodimit.h"
#include "verify.h"

class aknp_imit : public QWidget
{
    Q_OBJECT
    
public:
    explicit aknp_imit(QWidget *parent = 0);
    ~aknp_imit();

public slots:
     void stopFreq(int);

private:
    QStackedWidget *stack;
    QComboBox *combo;
    PeriodImit *periodimit ;
    react_imit *reactimit ;
    react_imit *test_react_imit;
    verify *verify_widget;

    QVector <int> toVector(float);
    float toFloat(QVector<int>);

public slots:
    void select(const QVector<int>&);

private slots:

    void slot_freqgenerator(int,float);
    void slot_periodImit(QVector <float>);
    void slot_reactImit(QVector<float>);
    void mode_imit(int);

signals:
    void send(QVector<int>);
};

#endif // AKNP_WIDGET_H
