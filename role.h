#ifndef ROLE_H
#define ROLE_H

#include <QPixmap>
#include <QTimer>

#include "config.h"


class Role
{
public:
    Role();
    QPixmap getImg();
    void jump();               //跳跃
    void updatePositionY();    //更新Y轴坐标
public:
    QRect role_Rect;    //角色边框  用于碰撞检测
    int x=100;                  //角色坐标
    int y=ROLE_ON_GROUNG_POS_Y;
    int current_run_img;        //奔跑图片下标
    double fall_speed;     //下落速度
    bool jump_once;        //已经跳跃一次
    bool jump_twice;       //已经跳跃两次
    QPixmap run_img[5];  //奔跑图片
    QPixmap jump_img;     //跳跃图片
    QTimer run_Timer;       //奔跑图片切换计时器
    QTimer jump_Timer;      //跳跃时间计时器  
};

#endif // ROLE_H
