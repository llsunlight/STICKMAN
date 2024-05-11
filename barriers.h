#ifndef BARRIERS_H
#define BARRIERS_H

#include <QPixmap>

//基类
class Barriers
{
public:
    Barriers();
    virtual void updatePosition()=0;
    virtual void updatebarrierPosY()=0;
    virtual bool isOut()=0;
    virtual int collisionDetection(QRect)=0;           //碰撞检测情况处理超过两种，定义返回值为int
    virtual QPixmap getImg(int)=0;
public:
    int x,y;
    QPixmap img;
    QRect rect;
};

//派生类
class Box:public Barriers
{
public:
    Box();
    void updatePosition();
    void updatebarrierPosY(){}
    bool isOut();
    int collisionDetection(QRect);
    QPixmap getImg(int);
public:
    QPixmap img2;
};

class Zidan:public Barriers
{
public:
    Zidan();
    void updatePosition();
    void updatebarrierPosY();
    bool isOut();
    int collisionDetection(QRect);
    QPixmap getImg(int);
public:
    QPixmap img2;
    double t=0;       //作为余弦函数的时间变量
    double u;            //作为余弦函数的初相
};

class Stop:public Barriers
{
public:
    Stop();
    void updatePosition();
    void updatebarrierPosY(){}
    bool isOut();
    int collisionDetection(QRect);
    QPixmap getImg(int);
public:
    QPixmap img2;
};

class Melody:public Barriers
{
public:
    Melody();
    void updatePosition();
    void updatebarrierPosY(){}
    bool isOut();
    int collisionDetection(QRect);
    QPixmap getImg(int);
};

class Wudi:public Barriers
{
public:
    Wudi(int);
    void updatePosition();
    void updatebarrierPosY(){}
    bool isOut();
    int collisionDetection(QRect);
    QPixmap getImg(int);
};

#endif // BARRIERS_H
