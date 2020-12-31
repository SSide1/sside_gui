#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QString>

class Dialog:public QDialog
{
    Q_OBJECT

private:
    QLineEdit* a;
    QLineEdit* b;
    QLineEdit* c;
    QLineEdit* d;
    QLineEdit* e;
    QLineEdit* f;
    QLineEdit* angle_;

public:


    bool direction;
    int dir;
    int mult;
    bool mode;
    int per_0_;
    int sq_0_;
    int per_1_;
    int sq_1_;

    Dialog(QWidget* w = 0,bool mode = 0, int per_0 = 0, int sq_0 = 0, int per_1 = 0, int sq_1 = 0);
    QString pA() const;
    QString pB() const;
    QString pC() const;
    QString pD() const;
    QString pE() const;
    QString pF() const;
    QString pAngle() const;

public slots:
    void minus_();
    void plus_();
    void per_and_sq();
    void change_direction_();

};

#endif // DIALOG_H
