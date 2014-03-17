#ifndef FREQGENERATOR_H
#define FREQGENERATOR_H

#include <QtGui/QWidget>
#include <QDebug>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QVBoxLayout>
#include <QRadioButton>

#define MAX_FREQ 125000
#define MAX_STEP 10.0
#define MAX_STEP_POWER 1000

class FreqGenerator : public QWidget
{
    Q_OBJECT
    
public:
    explicit FreqGenerator(int , QWidget *parent = 0);
 signals:

	void setFreq(int,float);   
private slots:
    void plusFreq();
    void minusFreq();
    void start();
    void setMode(bool);

private:
    QDoubleSpinBox *freqBox;
    QDoubleSpinBox *stepBox;
    QDoubleSpinBox *stepPowerBox;
    QPushButton *plusButton;
	QPushButton *minusButton;
    QRadioButton *selMode_0;
    QRadioButton *selMode_1;

    QLabel *stepLabel;
    QLabel *powLabel;

    bool mode;

    float value_step;
    float start_freq;
    float freq;
    int canal;
	float step;
};

#endif // FREQGENERATOR_H
