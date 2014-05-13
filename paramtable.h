#ifndef PARAMTABLE_H
#define PARAMTABLE_H

#include <QToolBox>
#include <unistd.h>

namespace Ui {
class ParamTable;
}

class ParamTable : public QToolBox
{
    Q_OBJECT
    
public:
    explicit ParamTable(QWidget *parent = 0);
    ~ParamTable();
    void selectId(const QVector<int> &);

private:
    Ui::ParamTable *ui;
    const QString toFloat(const QVector<int> &);
    void sendCAN(int,const QString&, const QString &);
    const QVector <int> toVector(float);

signals:
    void send(QVector<int>);

private slots:
    void saveParam();
};

#endif // PARAMTABLE_H
