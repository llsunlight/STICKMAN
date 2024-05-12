#include "barriers.h"
#include "config.h"
#include <QtMath>

#include <ctime>

Barriers::Barriers()
{

}

Box::Box()
{
    img.load(BOX_PATH);
    img2.load(BOX_PATH2);
    //设置障碍物出现坐标
    x=GAME_WIDTH;
    y=465;
    rect.setWidth(img.width()-10);
    rect.setHeight(img.height()-10);
    // rect.moveTo(x+5,y+3);
}
void Box::updatePosition(){
    x-=SCENE_SCROLL_SPEED;
    rect.moveTo(x+5,y+3);
}
bool Box::isOut(){
    return x<-img.width();
}
//判断是否碰撞
int Box::collisionDetection(QRect r){
    if(rect.intersects(r)){
        return 1;
    }
    else
        return 0;
}
QPixmap Box::getImg(int i){
    if(i==0){
        return img;
    }
    else
        return img2;
}
Zidan::Zidan()
{
    img.load(ZHADAN_PATH);
    img2.load(ZHADAN_PATH2);
    x=GAME_WIDTH;
    srand((unsigned int)time(NULL));
    u=rand()%(10000);
    // y=600+500*qCos(t/50+u);
    //设置物体
    rect.setWidth(img.width()-23);
    rect.setHeight(img.height()-11);
    rect.moveTo(x+10,y+6);
}
void Zidan::updatePosition(){
    x-=SCENE_SCROLL_SPEED;
    rect.moveTo(x+10,y+6);
}
void Zidan::updatebarrierPosY(){
    t+=1;
    y=600+500*qCos(t/50+u);
}
bool Zidan::isOut(){
    return x<-img.width();
}
int Zidan::collisionDetection(QRect r){
    if(rect.intersects(r)){
        return 1;
    }
    else
        return 0;
}
QPixmap Zidan::getImg(int i){
    if(i==0){
        return img;
    }
    else
        return img2;

}

Stop::Stop()
{
    img.load(STOP_PATH);
    img2.load(STOP_PATH2);
    x=GAME_WIDTH;
    y=300;
    rect.setWidth(9);
    rect.setHeight(img.height());
    rect.moveTo(x+21,y);
}
void Stop::updatePosition(){
    x-=SCENE_SCROLL_SPEED;
    rect.moveTo(x+21,y);
}
bool Stop::isOut(){
    return x<-img.width();
}
int Stop::collisionDetection(QRect r){
    if (rect.intersects(r)) {
        return 1; // 碰撞
    } else {
        return 0; // 无碰撞
    }
}
QPixmap Stop::getImg(int i){
    if(i==0){
        return img;
    }
    else
        return img2;
}

Melody::Melody(){
    img.load(MELODY_PATH);
    x=GAME_WIDTH;
    y=rand()%(260)+40;
    rect.setWidth(img.width());
    rect.setHeight(img.height());
    rect.moveTo(x,y);
}
void Melody::updatePosition(){
    x-=SCENE_SCROLL_SPEED;
    rect.moveTo(x,y);
}
bool Melody::isOut(){
    return x<-img.width();
}
int Melody::collisionDetection(QRect r){
    if(rect.intersects(r)){
        return 2;
    }
    else
        return 0;
}
QPixmap Melody::getImg(int i){
    return img;
}

Wudi::Wudi(int i){
    img.load(WUDI_PATH);
    x=GAME_WIDTH;
    if(i==1){
        x+=22;
        y=180;
    }
    if(i==2){
        y=rand()%240+50;
    }
    rect.setWidth(img.width());
    rect.setHeight(img.height());
    rect.moveTo(x,y);
}
void Wudi::updatePosition(){
    x-=SCENE_SCROLL_SPEED;
    rect.moveTo(x,y);
}
bool Wudi::isOut(){
    return x<-img.width();
}
int Wudi::collisionDetection(QRect r){
    if(rect.intersects(r)){
        return 3;
    }
    else
        return 0;
}
QPixmap Wudi::getImg(int i){
    return img;
}
