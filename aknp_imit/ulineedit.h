#ifndef POWEREDIT_H
#define POWEREDIT_H

#include <QtGui/QLineEdit>

class ULineEdit:public QLineEdit
{
    Q_OBJECT
public:
    explicit ULineEdit(QWidget *parent =0);
    
    float min;
	float max;

    bool valid;
    float   value();
//public slots:
  //  void setText(const QString &);
private slots:
    void slotTextEdit(QString);

};

#endif // POWEREDIT_H
