#ifndef AKE_02_H
#define AKE_02_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

class ake_02 : public QWidget
{
    Q_OBJECT
public:
    explicit ake_02(QWidget *parent = 0);
    
    QLabel *label[10][2];
    QString str[10][2];
 private:
    int toInt(const QVector<int>&);
    float toFloat(const QVector<int>&);

public slots:
    void selectId(const QVector<int>&);
};

#endif // AKE_02_H
