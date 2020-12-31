#include "figure.h"
#include "dialog.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDialog>
#include <QLabel>
#include <QDebug>
#include <QInputDialog>
#include <QPushButton>
#include <cmath>
#include <QPainterPath>

Figure::Figure(QWidget *parent,bool fig) :
    QWidget(parent),
    flag_paint(false), flag_resize(false),pressed(false), mode(fig), rotate(0)
{
    pen.setColor(Qt::black);
    this->move(50,50);
    dir = -1;
    he_b = rand()%3+3;
    he_1_b = rand()%3+3;
    he_2_b = rand()%3+3;
    p_b = rand()%6+12;

    he1_b = rand()%3+3;
    he2_b = rand()%3+3;
    he3_b = rand()%3+3;
    he4_b = rand()%3+3;
    p1_b = rand()%6+12;

    mult = 6;
    scale = 5;
    per_0 = 1;
    per_1 = 1;
    sq_0 = 1;
    sq_1 = 1;

}

Figure::~Figure(){

}

void Figure::paintEvent(QPaintEvent *event)
{

    const int w = width()  -1;
    const int h = height() -1;

    //QPainterPath painter_(this);
    int he = h/he_b;
    int he_1 = h/he_1_b;
    int he_2 = h/he_2_b;
    int p = w/p_b;

    int he1 = h/he1_b;
    int he2 = h/he2_b;
    int he3 = h/he3_b;
    int he4 = h/he4_b;
    int p1 = w/p1_b;

   if( !flag_paint ) flag_paint = true;
   if( flag_paint && !flag_resize ) this->resize(mult*w+mult,mult*h+2*mult * mult);

   QPainter painter(this);

   painter.setPen(pen);


   painter.translate(250,120);


   painter.scale(1.0/scale,1.0/scale);
   painter.rotate(rotate);

   if(mode == 0){

   painter.drawLine(0 + he,0,w - he_1,0);	// top
   painter.drawLine(w,0 + he_1,w,h - he_2);	// rigth
   painter.drawLine(w - he_2,h,w/2+p,h); 	// botton
   painter.drawLine(w/2-p,h,0,h);
   painter.drawLine(0,h,0,0 + he);	// left
   per_0 = 2*w + 2*h - (he_2*2 - (6 * he_2 / 4) + 2*p);
   sq_0 = w*h - he*he - he_1*he_1 + 2*p*p - (he_2*he_2 - (3 * (he_2 * he_2))/4);
   //D
   painter.drawLine(0 + he,0,0 + he, he);
   painter.drawLine(0+he, he, 0, he);

   //A
   painter.drawLine(w - he_1,0, w - he_1, he_1);
   painter.drawLine( w - he_1, he_1, w, he_1);

   //B
   painter.drawArc(w-2*he_2, h-2*he_2, he_2*2,he_2*2,270*16, 90*16);

   //F
   painter.drawLine((w/2 - p), h, w/2-p, h+p);
   painter.drawLine(w/2-p, h+p, w/2+p, h+p);
   painter.drawLine(w/2+p, h+p, w/2+p, h);
}
   else if(mode == 1){
       painter.drawLine(0 + he1,0,w/2 - p1, 0);	// top
       painter.drawLine(w/2 + p1,0,w - he2,0);
       painter.drawLine(w,0 + he2,w,h - he3);	// rigth
       painter.drawLine(w - he3,h,0 + he4,h); 	// botton
       painter.drawLine(0,h - he4,0,0 + he1);	// left
       per_1 = 2*w + 2*h + p1*2 - (he2*2 - (6 * he2 / 4)) - (he4*2 - (6 * he4 / 4)) - (he3*2 - sqrt(he3*he3 + he3*he3)) - (he1*2 - sqrt(he1*he1 + he1*he1));
       sq_1 = w*h + p1*2 * p1 - (3*he2*he2/4) - (he3*he3/2) - (he1*he1/2) - (he4*he4 - (3*he4*he4/4));

       //A
       painter.drawArc(w - he2, 0 - he2, he2*2,he2*2,180*16, 90*16);

       //B
       painter.drawLine(w,h - he3,w - he3,h );

       //C
       painter.drawArc(0, h - 2*he4, he4*2, he4*2, 180*16,90*16);

       //D
       painter.drawLine(0,0 + he1,0 + he1,0);

       //E
       painter.drawLine((w/2 - p1), 0, w/2-p1, 0-p1);
       painter.drawLine(w/2-p1, 0-p1, w/2+p1, 0-p1);
       painter.drawLine(w/2+p1, 0-p1, w/2+p1, 0);

   }




}

void Figure::resizeEvent(QResizeEvent *event)
{
   if( flag_paint && !flag_resize ) flag_resize = true;
}

void Figure::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        q = event->pos();


        if(pen.color() == Qt::blue){
            pen.setColor(Qt::black);
            pressed = false;
        }
        else{
            pen.setColor(Qt::blue);
            pressed = true;
        }

        this->setCursor(QCursor(Qt::ClosedHandCursor));
        this->repaint();

    }

    if(event->button() == Qt::RightButton){

        Dialog* d = new Dialog(0,mode,per_0/scale,sq_0/scale,per_1/scale,sq_1/scale);
        pressed = true;

        if(d->exec() == QDialog::Accepted){
            if(mode == 0){

            this->dir *= d->dir;
            this->scale += d->mult;
                if(scale < 5)
                    scale = 5;

            if((d->pAngle().size() > 0)){
                this->rotate += this->dir * std::stoi(d->pAngle().toStdString());
                if(scale < 5){
                    scale = 5;
                }
            }

            if(d->pD().size() > 0 && std::stoi(d->pD().toStdString()) >= 3)
                this->he_b = std::stoi(d->pD().toStdString());

            if(d->pA().size() > 0 && std::stoi(d->pA().toStdString()) >= 3)
                this->he_1_b = std::stoi(d->pA().toStdString());

            if(d->pB().size() > 0 && std::stoi(d->pB().toStdString()) >= 3)
                this->he_2_b = std::stoi(d->pB().toStdString());

            if(d->pF().size() > 0 && std::stoi(d->pF().toStdString()) >= 4)
                this->p_b = std::stoi(d->pF().toStdString());


            }
            if(mode == 1){
                this->scale += d->mult;
               if(scale < 5)
                    scale = 5;
                this->dir *= d->dir;
                if(d->pAngle().size() > 0){
                    this->rotate += this->dir * std::stoi(d->pAngle().toStdString());
                    if(scale < 5){
                        scale = 5;
                    }
                }



                if(d->pA().size() > 0 && std::stoi(d->pA().toStdString()) >= 3)
                    this->he2_b = std::stoi(d->pA().toStdString());

                if(d->pB().size() > 0 && std::stoi(d->pB().toStdString()) >= 3)
                    this->he3_b = std::stoi(d->pB().toStdString());

                if(d->pC().size() > 0 && std::stoi(d->pC().toStdString()) >= 3)
                    this->he4_b = std::stoi(d->pC().toStdString());

                if(d->pD().size() > 0 && std::stoi(d->pD().toStdString()) >= 3)
                    this->he1_b = std::stoi(d->pD().toStdString());

                if(d->pE().size() > 0 && std::stoi(d->pE().toStdString()) >= 3)
                    this->p1_b = std::stoi(d->pE().toStdString());

            }


        }
        this->repaint();

        delete d;
    }


}

void Figure::mouseMoveEvent(QMouseEvent *event){

    if(mode == 1 && (event->buttons() & Qt::LeftButton) && mapToParent(event->pos() - q).x() > -250 && mapToParent(event->pos() - q).y() > -90
            && mapToParent(event->pos() - q).x() < (577+scale*12) && (mapToParent(event->pos() - q).y() < (578+scale*10)&&(mapToParent(event->pos() - q).y() < 662) )){
        this->move(mapToParent(event->pos() - q));
        pressed = true;
        pen.setColor(Qt::blue);
        this->repaint();

    }
    if(mode == 0 && (event->buttons() & Qt::LeftButton) && mapToParent(event->pos() - q).x() > -250 && mapToParent(event->pos() - q).y() > -100
            && mapToParent(event->pos() - q).x() < (580 + scale*12) && (mapToParent(event->pos() - q).y() < (574+scale*10) && mapToParent(event->pos() - q).y() < 658)){
        this->move(mapToParent(event->pos() - q));
        pressed = true;
        pen.setColor(Qt::blue);
        this->repaint();

    }
}

void Figure::mouseReleaseEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        this->setCursor(QCursor(Qt::ArrowCursor));

    }

}


