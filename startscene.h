#ifndef STARTSCENE_H
#define STARTSCENE_H

#include <QMainWindow>
#include <QPainter>
#include <startbutton.h>
#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include <QMouseEvent>
#include <mainwindow.h>
#include <introduction.h>
#include <ui_mainwindow.h>


QT_BEGIN_NAMESPACE
namespace Ui { class startscene; }
QT_END_NAMESPACE


class startscene : public QMainWindow
{
    Q_OBJECT
public:
    // explicit startscene(QWidget *parent = nullptr);
    startscene(QWidget *parent = nullptr);
    ~startscene();
    //绘图事件
    void paintEvent(QPaintEvent *);
    //连接主页面
    MainWindow*p=NULL;//用来保存页面2的实例化对象的地址
    Introduction *intro=new Introduction;   //游戏介绍窗口

private:
    Ui::startscene *ui;

signals:
};

#endif // STARTSCENE_H
