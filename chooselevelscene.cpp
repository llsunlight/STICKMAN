#include "chooselevelscene.h"
#include "QtWidgets/qmenu.h"
#include<QMenuBar>
#include<QAction>
#include<QPainter>
#include<mypushbutton.h>
#include<QDebug>
#include<QLabel>


chooselevelscene::chooselevelscene(QWidget *parent)
    : QMainWindow{parent}
{
    //游戏窗格尺寸大小580*580
    this->setFixedSize(580,580);
    //设置窗口上方标题
    this->setWindowTitle("STICKMAN");


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

    // // 关卡选择界面 // //
    //&&&&返回按钮创建----------未添加图片&&&&
    mypushbutton*backBtn = new mypushbutton(":/startbutton.png");
    backBtn -> setParent(this);
    backBtn ->move(this ->width()-backBtn->width(),this->height()-backBtn->height());

    connect(backBtn,&mypushbutton::clicked,[=](){
        //qDebug()<<"返回到主场景";
        //隐藏自身
        emit this->chooseSceneBack();

    });

    // // 创建游戏场景 // //
    playscene = NULL;





    // // 关卡选择界面 // //
    //&&&&选择关卡按钮-------------未替换图片&&&&
    for(int i=0;i<20;i++)
    {
        mypushbutton*menubtn = new mypushbutton(":/startbutton.png");
        menubtn->setParent(this);
        menubtn->move(50+(i%4)*70,130+(i/4)*70);//拉大横轴间距，拉大纵轴间距

        // menubtn->setText("1111");

        connect(menubtn,&mypushbutton::clicked,[=]{
            // QString str= QString("您选择的是%1关").arg(i+1);
            // qDebug()<<str;

            //隐藏自身
            this->hide();

            //进入具体游戏场景中
            playscene = new PlayScene(i+1);
            playscene ->show();


            //&&&&关卡返回目录&&&&
            connect(playscene,&PlayScene::chooseSceneBack,[=](){
                //具体场景 隐藏
                playscene->close();
                delete playscene;
                playscene = NULL;

                //选择关卡场景 显示
                this->show();


            });
        });

        //&&&&在按钮上加上字体&&&&
        QLabel*label = new QLabel(this);
        //设置文字标签大小
        label -> setFixedSize(menubtn->width(),menubtn->height());
        //设置显示内容
        label->setText(QString::number(i+1));
        //设置标签位置
        label->move(50+(i%4)*70,130+(i/4)*70);
        //水平垂直设置居中
        label->setAlignment(Qt::AlignHCenter| Qt::AlignVCenter);
        //设置鼠标穿透
        label->setAttribute(Qt::WA_TransparentForMouseEvents);


    }



}

//重写绘图事件(关卡选择)
void chooselevelscene::paintEvent(QPaintEvent*){
    QPainter painter (this);
    //加载背景
    QPixmap pix;
    pix.load(":/background.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);//按照当前窗口制定的长宽高拉伸图片

    //加载标题----------未添加图片
    pix.load(":/title001.png");
    painter.drawPixmap(200,100,pix);

}
