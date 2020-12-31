#ifndef FIGURE_H
#define FIGURE_H

#include <QWidget>
#include <QPainter>
#include <QContextMenuEvent>
#include <QInputDialog>


class Figure : public QWidget
{
    Q_OBJECT

    bool flag_paint;
    bool flag_resize;

    QPoint q;
    QPainter painter;
    QPen pen;
    QInputDialog * dialog;

    int rotate;
    bool direction;
    int dir;

    int mult;
    int scale;
    int per_0;
    int per_1;
    int sq_0;
    int sq_1;

    int he_b;
    int he_1_b;
    int he_2_b;
    int p_b;

    int he1_b;
    int he2_b;
    int he3_b;
    int he4_b;
    int p1_b;

public:
    explicit Figure(QWidget *parent = 0, bool fig = 0);
    bool pressed;
    bool mode;
    ~Figure();

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);



signals:



};

#endif // FIGURE_H
