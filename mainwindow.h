#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include <QMouseEvent>
#include <vector>
#include "ground.h"
#include "role.h"
#include "barriers.h"
#include "QWidget"
#include "QPushButton"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initWindow();//初始化窗口
    void paintEvent(QPaintEvent *event);  //绘图事件
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void playgame();   //开始游戏
    void gameover();   //游戏结束
    void updatePosition();   //更新坐标
    void collisionDetection(); //碰撞检测
    void sprint();          //冲刺
    void addBarrier();      //添加障碍物

    std::vector<Barriers*>barriers;     //管理屏幕中的障碍物
    std::vector<Barriers*>::iterator it;

    QPixmap background;
    QTimer m_Timer;        //刷新屏幕计时器
    QTimer sprint_Timer;           //冲刺持续时间计时器
    QTimer sprint_interval_Timer;  //冲刺间隔时间计时器
    QTimer add_Barrier_interval_Timer; //生成障碍物计时器
    QTimer add_melody_interval_Timer;   //生成旋律间隔时间计时器
    QTimer protected_Timer;            //无敌时间

    QTimer difficult_add_Timer;     //难度增加计时器

    bool sprint_once;         //是否已经冲刺一次
    bool sprint_twice;        //是否已经冲刺两次
    int i;                    //障碍物类型
    int score;           //分数

    Grounds grounds;  //地面对象
    Ground ground;
    Role role;

    Ui::MainWindow *ui;




private slots:
    void on_restart_clicked();


signals:
    void back2();//定义退回信号


};
#endif // MAINWINDOW_H
