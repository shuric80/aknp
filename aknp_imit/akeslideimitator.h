#ifndef AKESLIDEIMITATOR_H
#define AKESLIDEIMITATOR_H

#include <QWidget>
#include <QVector>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

class AkeSlideImitator : public QWidget
{
    Q_OBJECT
public:
    explicit AkeSlideImitator(QWidget *parent = 0);
 private:
    QSpinBox *valuePrivod;
    //QSpinBox *stepPrivod;
    QPushButton *btnMinus;
	QPushButton *btnPlus;
 public slots:
   void slotPrivod();
   void slotMinusValue();
   void slotPlusValue();
 signals:
   void sgnlSetValue(int);
    
};

#endif // AKESLIDEIMITATOR_H
