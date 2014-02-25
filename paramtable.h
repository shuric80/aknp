#ifndef PARAMTABLE_H
#define PARAMTABLE_H

#include <QToolBox>

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
};

#endif // PARAMTABLE_H
