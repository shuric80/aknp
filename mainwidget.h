#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "aknp_imit/aknp_imit.h"
#include "ake_01.h"
#include "ake_02.h"
#include <QComboBox>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>


class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = 0);
private:

    aknp_imit *imitator;
    ake_01 *slide_0;
    ake_02 *slide_1;
    QComboBox *leftCombo;
    QComboBox *rightCombo;
    QStackedWidget *rightStack;

signals:
    
public slots:
    
};

#endif // MAINWIDGET_H
