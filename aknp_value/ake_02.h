#ifndef AKE_02_H
#define AKE_02_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QLineEdit>


class ake_02 : public QWidget
{
    Q_OBJECT
public:
    explicit ake_02(QWidget *parent = 0);
    

    QLabel *label[10][2];
    QLineEdit *lineEdit[10][2];
    QString str[10][2];
 private:
   inline  int toInt(const QVector<int>&);
   inline float toFloat(const QVector<int>&);

public slots:
    void selectId(int,      const QVector<int>&);
};

#endif // AKE_02_H
