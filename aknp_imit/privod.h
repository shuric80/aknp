#ifndef PRIVOD_H
#define PRIVOD_H

#include <QtGui/QWidget>
#include <QDebug>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QVBoxLayout>

#define MAX_FREQ 125000
#define MAX_STEP 10.0


class PrivodImit : public QWidget
{
    Q_OBJECT
    
public:
    explicit PrivodImit(int ,QWidget *parent = 0);
 signals:

    void setFreq(int,float);
private slots:
    void plusFreq();
    void minusFreq();
    void start();
private:
    QDoubleSpinBox *freqBox;
    QDoubleSpinBox *stepBox;
    QPushButton *plusButton;
	QPushButton *minusButton;

    int init;

    float value_step;
    float start_freq;
    float freq;
    int canal;
	float step;
};

#endif // FREQGENERATOR_H
