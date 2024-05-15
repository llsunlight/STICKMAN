#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>
#include <QKeyEvent>
#include <ctime>
#include <QFontDatabase>
#include <QString>
#include "config.h"
#include "role.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
   ui->setupUi(this);
    connect(ui->back,&QPushButton::clicked,[=](){
       //发信号
       emit this->back2();
   });

    initWindow();    //初始化窗口
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initWindow(){


    //窗口
    setWindowTitle(GAME_TITLE);            //标题
    background.load(BACKGROUND_PATH);    //加载背景
    setFixedSize(GAME_WIDTH ,GAME_HEIGHT);  //大小
    update();

    //排版
    int fontId=QFontDatabase::addApplicationFont(QStringLiteral(":/res01/hk4e_zh-cn.ttf"));   //导入字体文件
    QStringList fontFamilies=QFontDatabase::applicationFontFamilies(fontId);
    QFont font;
    font.setFamily(fontFamilies[0]);
    ui->restart->setFont(font);
    //标签颜色
    QPalette palette;
    palette.setColor(QPalette::WindowText, Qt::red);
    ui->over_score->setPalette(palette);
    ui->over_distance->setPalette(palette);
    ui->restart->setPalette(palette);
    ui->game_over->setPalette(palette);
    ui->score->setPalette(palette);
    ui->distance->setPalette(palette);

    ui->score->setFont(font);
    ui->distance->setFont(font);
    ui->over_score->setFont(font);         //结算
    ui->over_distance->setFont(font);
    ui->game_over->setFont(font);
    ui->back->setFont(font);

    score=0;
    grounds.distance=0;
    ui->score->setText("Score: "+QString::number(score));
    ui->distance->setText("Distance: "+QString::number(grounds.distance)+" m");
    sprint_once=false;
    sprint_twice=false;

    m_Timer.setInterval(GAME_RATE);                    //主定时器设置  控制游戏难度
    sprint_Timer.setInterval(SPRINT_DURATION);         //冲刺定时器设置
    sprint_Timer.setSingleShot(true);
    sprint_interval_Timer.setInterval(SPRINT_INTERVAL);
    sprint_interval_Timer.setSingleShot(true);
    add_Barrier_interval_Timer.setInterval(ADD_BARRIER_INTERVAL); //障碍物计时器设置
    add_melody_interval_Timer.setInterval(ADD_MELODY_INTERVAL);     //旋律计时器设置
    add_melody_interval_Timer.setSingleShot(true);
    protected_Timer.setInterval(PROTECTED_DURATION);
    protected_Timer.setSingleShot(true);

    difficult_add_Timer.setInterval(10000);   //难度增加计时器
    role.y=ROLE_ON_GROUNG_POS_Y;     //角色设置


    //开始游戏
    playgame();
    ui->restart->setFocusPolicy(Qt::NoFocus);
    ui->groupBox->hide();

    connect(&difficult_add_Timer,&QTimer::timeout,this,[=](){
        if(ground.ground_scroll_speed<=21){
            ground.ground_scroll_speed+=3;
            update();
            qDebug()<<"add";
        }
    });

    connect(&m_Timer,&QTimer::timeout,[=](){                                        //随着时间增加地面移动速度
        updatePosition();
        collisionDetection();
        ui->score->setText("Score: "+QString::number(score));   //更新分数
        ui->distance->setText("Distance: "+QString::number(grounds.distance)+" m");
        update();
    });
    connect(&add_Barrier_interval_Timer,&QTimer::timeout,[=](){
        addBarrier();
    });


}


void MainWindow::playgame(){
    score=0;
    grounds.distance=0;
    role.current_run_img=0;
    ui->score->show();
    ui->distance->show();
    m_Timer.start();            //计时器，启动！
    role.run_Timer.start();
    add_Barrier_interval_Timer.start();
    difficult_add_Timer.start();
}

void MainWindow::gameover(){
    m_Timer.stop();
    sprint_Timer.stop();
    sprint_interval_Timer.stop();
    add_Barrier_interval_Timer.stop();
    add_melody_interval_Timer.stop();
    role.run_Timer.stop();
    protected_Timer.stop();
    ui->groupBox->setGeometry(330,0,ui->groupBox->width(),ui->groupBox->height());
    ui->over_score->setText("Score: "+QString::number(score));
    ui->over_distance->setText("Distance: "+QString::number(grounds.distance)+" m");
    ui->groupBox->show();      //结算界面出现
}

void MainWindow::updatePosition(){           //更新对象坐标
    grounds.calculatePositions();
    for(it=barriers.begin();it!=barriers.end();){
        if((*it)->isOut()){
            it=barriers.erase(it);
        }
        else{
            (*it)->updatePosition(ground);
            (*it)->updatebarrierPosY();     //对象是c艹更新Y坐标否则执行空函数
            it++;
        }
    }
    role.updatePositionY();
    if(this->sprint_Timer.isActive()){
        grounds.calculatePositions();
        grounds.calculatePositions();
        for(auto& barr:barriers)
        {
            barr->updatePosition(ground);
            barr->updatePosition(ground);
        }
    }
}

void MainWindow::collisionDetection(){
    int i=0;
    for(it=barriers.begin();it!=barriers.end();){
        i=(*it)->collisionDetection(role.role_Rect);
        switch (i) {
        case 0:                       //无碰撞
            it++;
            break;
        case 1:{                      //障碍物
            it++;
            if(!protected_Timer.isActive()&&!sprint_Timer.isActive()){
                gameover();
            }
            break;
        }
        case 2:{                      //旋律
            protected_Timer.start();
            it=barriers.erase(it);
            score+=20;
            break;
        }
        case 3:{                      //爱心
            it=barriers.erase(it);
            score+=5;
            break;
        }
        default:
            break;
        }
    }
}
//是否冲刺两次
void MainWindow::sprint(){
    if(!sprint_interval_Timer.isActive()){
        sprint_once=false;
        sprint_twice=false;
    }
    if(sprint_twice||(sprint_Timer.remainingTime()>90&&sprint_Timer.isActive())){
        return;
    }
    if(!sprint_once){
        sprint_once=true;
        sprint_Timer.start();
        sprint_interval_Timer.start();
    }
    else if(!sprint_twice){
        sprint_twice=true;
        sprint_Timer.start();
    }
}

//生成障碍物
void MainWindow::addBarrier(){
    srand((unsigned int)time(NULL));
    i=rand()%4;
    switch (i) {
    case 0:
        barriers.emplace_back(new Box);
        barriers.emplace_back(new Wudi(1));
        break;
    case 1:
        barriers.emplace_back(new Zidan);
        break;
    case 2:
        barriers.emplace_back(new Stop);
        barriers.emplace_back(new Wudi(2));
        break;
    case 3:
        if(add_melody_interval_Timer.isActive()){
            barriers.emplace_back(new Wudi(2));
            return;
        }
        add_melody_interval_Timer.start();
        barriers.emplace_back(new Melody);
        break;
    default:
        break;
    }
}


void MainWindow::on_restart_clicked()
{
    ui->groupBox->hide();
    barriers.clear();
    role.y=ROLE_ON_GROUNG_POS_Y;
    playgame();
}


void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    //绘制背景
    painter.drawPixmap(0,0,background);
    //绘制地面
    for(int i=0;i<9;i++){
        painter.drawPixmap(grounds.grounds[i].ground_posX,500,grounds.grounds[i].ground);
    }
    //绘制角色
    painter.drawPixmap(role.x,role.y,role.getImg());
    //绘制障碍物
    for(auto& barr:barriers)
    {
        if(protected_Timer.isActive()){
            painter.drawPixmap(barr->x,barr->y,barr->getImg(1));
        }
        else{
            painter.drawPixmap(barr->x,barr->y,barr->getImg(0));
        }
    }
}
//键盘关联
void MainWindow::keyPressEvent(QKeyEvent *event){
    QKeyEvent *key=(QKeyEvent*) event;
    if(key->key()==Qt::Key_Space){                     //空格键跳跃
        role.jump();
    }
    if(key->key()==Qt::Key_D){                     //D键冲刺
        sprint();
    }
}
void MainWindow::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::RightButton){
        sprint();
    }
}

