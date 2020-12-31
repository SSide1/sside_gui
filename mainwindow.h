#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*
 * Toolbar:
 *
 * doc.qt.io/archives/qt-4.8/qt-demos-mainwindow-example.html
 *
 */
#include "figure.h"
#include <QMainWindow>
#include <QToolBar>
#include <vector>


class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QMenu    *menuFigure;
    QAction  *actionFigure1;
    QToolBar *createToolBar();
    bool fig_19_a;
    bool fig_29_a;
    std::vector<Figure*> fig_19;
    std::vector<Figure*> fig_29;
    Figure *fig;


public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void AddFigures();
    void DeleteFigures();
    void figure19_add(bool);
    void figure29_add(bool);

};



#endif // MAINWINDOW_H

