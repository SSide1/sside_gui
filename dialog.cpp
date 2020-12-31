


#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <dialog.h>
#include <QDebug>

Dialog::Dialog(QWidget *w, bool mode, int per_0, int sq_0, int per_1, int sq_1):QDialog(w, Qt::WindowTitleHint | Qt::WindowSystemMenuHint), dir(1), mult(0),mode(mode)
{
    a = new QLineEdit;
    b = new QLineEdit;
    c = new QLineEdit;
    d = new QLineEdit;
    e = new QLineEdit;
    f = new QLineEdit;
    angle_ = new QLineEdit;

    QLabel* aL = new QLabel("&Point A");
    QLabel* bL = new QLabel("&Point B");
    QLabel* cL = new QLabel("&Point C");
    QLabel* dL = new QLabel("&Point D");
    QLabel* eL = new QLabel("&Point E");
    QLabel* fL = new QLabel("&Point F");
    QLabel* angle = new QLabel("&Angle");

    aL->setBuddy(a);
    bL->setBuddy(b);
    cL->setBuddy(c);
    dL->setBuddy(d);
    eL->setBuddy(e);
    fL->setBuddy(f);
    angle->setBuddy(angle_);


     per_0_ = per_0;
     sq_0_ = sq_0;
     per_1_ = per_1;
     sq_1_ = sq_1;


    QPushButton* minus = new QPushButton("&Minus Size");
    QPushButton* per_sq = new QPushButton("&Perimetr and Square");
    connect(per_sq, SIGNAL(clicked()), SLOT(per_and_sq()));
    QPushButton* plus = new QPushButton("&Plus Size");

    QPushButton* change_direction = new QPushButton("&Change Direction");
    connect(minus, SIGNAL(clicked()), SLOT(minus_()));
    connect(plus, SIGNAL(clicked()), SLOT(plus_()));

    connect(change_direction, SIGNAL(clicked()), SLOT(change_direction_()));


    QPushButton* ok = new QPushButton("&OK");
    QPushButton* cancel = new QPushButton("&Cancel");

    connect(ok, SIGNAL(clicked()), SLOT(accept()));
    connect(cancel, SIGNAL(clicked()), SLOT(reject()));
    if(mode == 0){
    QGridLayout* layout = new QGridLayout;
    layout->addWidget(aL, 0, 0);
    layout->addWidget(a, 0, 1);

    layout->addWidget(bL, 1, 0);
    layout->addWidget(b, 1, 1);

    layout->addWidget(dL, 2, 0);
    layout->addWidget(d, 2, 1);

    layout->addWidget(fL, 3, 0);
    layout->addWidget(f, 3, 1);

    layout->addWidget(angle, 4, 0);
    layout->addWidget(angle_, 4, 1);

    layout->addWidget(minus, 5, 0);

    layout->addWidget(plus, 5, 1);

    layout->addWidget(change_direction, 6, 0);
    layout->addWidget(per_sq, 6, 1);

    layout->addWidget(ok, 7, 0);

    layout->addWidget(cancel, 7, 1);

    setLayout(layout);
    }
    if(mode == 1){
        QGridLayout* layout = new QGridLayout;
        layout->addWidget(aL, 0, 0);
        layout->addWidget(a, 0, 1);

        layout->addWidget(bL, 1, 0);
        layout->addWidget(b, 1, 1);

        layout->addWidget(cL, 2, 0);
        layout->addWidget(c, 2, 1);

        layout->addWidget(dL, 3, 0);
        layout->addWidget(d, 3, 1);

        layout->addWidget(eL, 4, 0);
        layout->addWidget(e, 4, 1);

        layout->addWidget(angle, 5, 0);
        layout->addWidget(angle_, 5, 1);

        layout->addWidget(minus, 6, 0);

        layout->addWidget(plus, 6, 1);

        layout->addWidget(change_direction, 7, 0);
        layout->addWidget(per_sq, 7, 1);

        layout->addWidget(ok, 8, 0);

        layout->addWidget(cancel, 8, 1);

        setLayout(layout);
    }

}
QString Dialog::pA() const{
    return a->text();
}
QString Dialog::pB() const{
    return b->text();
}
QString Dialog::pC() const{
    return c->text();
}
QString Dialog::pD() const{
    return d->text();
}
QString Dialog::pE() const{
    return e->text();
}
QString Dialog::pF() const{
    return f->text();
}

QString Dialog::pAngle() const{
    return angle_->text();

}

void Dialog::minus_(){
    mult += 1;
}

void Dialog::plus_(){
    mult -= 1;
}

//void Dialog::change_angle_(){
//    rotate += 30*dir;
//}

void Dialog::change_direction_(){
    dir *= (-1);
}
void Dialog::per_and_sq(){
    QDialog* q = new QDialog(this);
    q->setModal(true);
    q->resize(200,200);
    q->show();

    if(mode == 0){
    QLabel *l = new QLabel(QString::fromStdString("Perimetr: " + std::to_string(per_0_)),q);
    l->move(10,10);
    l->show();

    QLabel *l_1 = new QLabel(QString::fromStdString("Square: " + std::to_string(sq_0_)),q);
    l_1->move(10,30);
    l_1->show();
    }
    if (mode == 1){
    QLabel *l_ = new QLabel(QString::fromStdString("Perimetr: " + std::to_string(per_1_)),q);
    l_->move(10,10);
    l_->show();

    QLabel *l_2 = new QLabel(QString::fromStdString("Square: " + std::to_string(sq_1_)),q);
    l_2->move(10,30);
    l_2->show();
    }

}



