#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QPixmap>
#include<mypushbutton.h>
#include<QAction>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //点击开始-退出，退出游戏
    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });

    //游戏窗格尺寸大小580*580
    this->setFixedSize(580,580);

    //设置窗口上方标题
    this->setWindowTitle("STICKMAN");

    //设置标题前面图片(mac未实现此操作)
    this ->setWindowIcon(QIcon(":/coin1.png"));

}

void MainWindow::paintEvent(QPaintEvent*){
    QPainter painter (this);
    //画初始页面背景图片
    QPixmap pix;
    pix.load(":/background.png");

    painter.drawPixmap(0,0,this->width(),this->height(),pix);//按照当前窗口制定的长宽高拉伸图片

    //画初始界面标题图片
    pix.load(":/title001.png");

    pix = pix.scaled(pix.width()*2,pix.height()*2);//缩放

    painter.drawPixmap(200,100,pix);

    //创建开始按钮
    mypushbutton* startBtn = new mypushbutton(":/startbutton.png");
    //放大标题：未实现startBtn = startBtn->scaled(startBtn->width()*2,startBtn->height()*2);
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5 - startBtn->width()*0.5,this->height()*0.5);
    startBtn->show();

    //创建出第二个选择关卡的场景
    choosescene = new chooselevelscene;

    //监听第二个选择关卡场景中的返回按钮信号
    connect(choosescene,&chooselevelscene::chooseSceneBack,[=](){
        //选择关卡场景隐藏
        choosescene->hide();
        //自身显示
        this->show();
    });


    connect(startBtn,&mypushbutton::clicked,[=](){

        //将自身隐藏调用
        this->hide();
        //进入到第二个选择关卡场景中
        choosescene ->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
