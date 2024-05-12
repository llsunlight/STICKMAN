#include "startscene.h"
#include "ui_startscene.h"
#include<QPushButton>


startscene::startscene(QWidget *parent)
    : QMainWindow{parent}, ui(new Ui::startscene)
{
    ui->setupUi(this);

    //窗口大小
    this->setFixedSize(1080, 690);
    //设置窗口上方标题
    this->setWindowTitle("STICKMAN");

    this->p=new MainWindow;//实例化页面2

    //创建开始按钮
    startbutton*starb=new startbutton(":/res01/startbutton.png");
    starb->setParent(this);
    starb->move(this->width()*0.5-starb->width()*0.5,this->height()*0.6);
    connect(starb,&QPushButton::clicked,[=](){
        this->hide();
        this->p->show();
    });

    //创建介绍按钮
    startbutton*intro=new startbutton(":/res01/intro.png");
    intro->setParent(this);
    intro->move(this->width()*0.5-starb->width()*0.5,this->height()*0.7);
    connect(intro,&QPushButton::clicked,[=](){
        this->intro->show();
    });

    connect(this->p,&MainWindow::back2,[=]{
        this->p->hide();
        this->show();
    });
}

startscene::~startscene(){};

void startscene::paintEvent(QPaintEvent *)
{
    //绘制背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res01/background.jpg");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix); //按照当前窗口制定的长宽高拉伸图片
    //标题
    pix.load(":/res01/title.png");
    // pix = pix.scaled(pix.width(),pix.height());//缩放
    painter.drawPixmap(this->width()*0.5-pix.width()*0.5, this->height()*0.05, pix);
}
