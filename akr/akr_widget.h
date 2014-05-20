#ifndef AKR_WIDGET_H
#define AKR_WIDGET_H

#include <QComboBox>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QVector>
#include <QPushButton>
#include <QInputDialog>
#include <QTimer>
#include <unistd.h>

class akr_widget : public QWidget
{
    Q_OBJECT
public:
    explicit akr_widget(QWidget *parent = 0);

    volatile int  err;

private:
    bool toggled;
    QLineEdit *analog_line[10];
    QLabel *label[18];
    QLineEdit *diaposon_line;
    QComboBox *discret_box[5];
    QComboBox *box;

    QPushButton *btn;
    QLabel *diap_label;
    QLabel *cannel_label;
    QPushButton *save_btn;
    QPushButton *reset_btn;

    QStringList list_diap;
    QStringList list_puu;
    QStringList list_f;
    QStringList list_sr;
    QStringList list_select_diap;
    QVector <QString> buf_discret;

    quint8 prev_cnt;
    volatile  bool enabled;

   inline  float toFloat(const QVector<int> &);
   inline QVector<int> toVector(const QString &);

signals:
    void send(QVector<int>);
    void reset_akr();

public slots:
    void select(int, const QVector<int>&);
    void input_password();
    void slot_save();
    void slot_reset();
	void clear();
    void init();
};

#endif // AKR_WIDGET_H
