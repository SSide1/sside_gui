#include "mainwindow.h"

#include "figure.h"

#include <QApplication>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QIcon>
#include <string>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), fig_19_a(false), fig_29_a(false)
{
    actionFigure1 = new QAction(tr("&Act"), this);
    connect(actionFigure1,SIGNAL(triggered()),
            QApplication::instance(),SLOT(quit()));

    addToolBar(Qt::TopToolBarArea,createToolBar());
    this->setFixedHeight(800);
    this->setFixedWidth(1000);
}

QToolBar* MainWindow::createToolBar(){
    QToolBar* bar = new QToolBar("Figure ToolBar" );
    QAction* figure19 = new QAction("figure 19",this);
    figure19->setCheckable(true);
    connect(figure19, SIGNAL(toggled(bool)), this, SLOT(figure19_add(bool)));

    QAction* figure29 = new QAction("figure 29",this);
    figure29->setCheckable(true);
    connect(figure29, SIGNAL(toggled(bool)), this, SLOT(figure29_add(bool)));

    bar->addAction(figure19);
    bar->addAction(figure29);
    bar->addAction("Add", this,SLOT(AddFigures()));
    bar->addAction("Delete", this,SLOT(DeleteFigures()));
    return bar;
}

MainWindow::~MainWindow()
{

}

void MainWindow::figure19_add(bool ch){
    fig_19_a = ch;
}

void MainWindow::figure29_add(bool ch){
    fig_29_a = ch;
}

void MainWindow::AddFigures(){
    if(fig_19_a && fig_29_a){
        qDebug() << fig_19_a << " " << fig_29_a;
        fig = new Figure(this,0);
        fig_19.push_back(fig);
        fig_19[fig_19.size() - 1]->show();

        fig = new Figure(this,1);
        fig_29.push_back(fig);
        fig_29[fig_29.size() - 1]->show();
    }

    if(fig_19_a && !fig_29_a){
        fig = new Figure(this,0);
        fig_19.push_back(fig);
        fig_19[fig_19.size() - 1]->show();
    }

    if(!fig_19_a && fig_29_a){
        fig = new Figure(this,1);
        fig_29.push_back(fig);
        fig_29[fig_29.size() - 1]->show();
    }


}

void MainWindow::DeleteFigures(){

        for(unsigned int i = 0; i < fig_19.size(); i++){
            if(fig_19[i]->pressed){
                fig_19[i]->close();
                fig_19.erase(fig_19.begin() + i);
                i--;
            }
        }

        for(unsigned int i = 0; i < fig_29.size(); i++){
            if(fig_29[i]->pressed){
                fig_29[i]->close();
                fig_29.erase(fig_29.begin() + i);
                i--;
            }
        }

}


