#include "playscene.h"
#include<QDebug>
#include<QMenuBar>
#include<QPainter>
#include<mypushbutton.h>
#include<QLabel>


PlayScene::PlayScene(int index){
    qDebug()<<"打开了"<<index<<"关";

    //保存本关关卡号
    this->levelindex = index;

    //游戏窗格尺寸大小580*580
    this->setFixedSize(580,580);
    //设置窗口上方标题
    this->setWindowTitle("火柴人生存挑战");


    //&&&&用代码创建菜单栏&&&&
    QMenuBar* bar = menuBar();
    this ->setMenuBar(bar);
    //创建开始菜单
    QMenu *startMenu = bar->addMenu("开始");
    //创建菜单项
    QAction *quitAction  = startMenu->addAction("退出");
    //点击退出按钮，实现退出游戏
    connect(quitAction,&QAction::triggered,[=](){
        this->close();
    });

    //&&&&返回按钮创建----------未添加图片&&&&
    mypushbutton*backBtn = new mypushbutton(":/startbutton.png");
    backBtn -> setParent(this);
    backBtn ->move(this ->width()-backBtn->width(),this->height()-backBtn->height());

    connect(backBtn,&mypushbutton::clicked,[=](){
        //隐藏自身
        //发送退出信号
        emit this->chooseSceneBack();

    });

    //&&&&显示具体关卡号&&&&
    QLabel*label = new QLabel;
    label->setParent(this);
    QString str = QString("Leave:%1").arg(this->levelindex);

    QFont font;
    font.setFamily("华文彩魏");
    font.setPointSize(20);

    //让label使用上面创建的字体
    label->setFont(font);

    //设置文本和大小位置(已调整好)
    label->setText(str);
    label->setGeometry(QRect(30,this->height()-50,120,50));

}


//重写绘图事件（第一关）
void PlayScene::paintEvent(QPaintEvent*){

    //绘制背景图片
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/background.png");

    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //绘制标题-----------未设置图片
    pix.load(":/title001.png");
    pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);
}
