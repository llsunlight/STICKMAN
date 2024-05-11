#include "role.h"

Role::Role()
{
    for(int i=0;i<5;i++){
        run_img[i].load(QString(":/res01/run%1.png").arg(i+1));//人物跑动
    }
    jump_img.load(JUMP_PATH);
    current_run_img=0;
    run_Timer.setInterval(RUN_INTERVAL);
    QObject::connect(&run_Timer,&QTimer::timeout,[this]()
    {
        current_run_img=(++current_run_img)%5;//改动1
    });
    jump_Timer.setInterval(JUMP_DURATION);
    jump_Timer.setSingleShot(true);

    fall_speed=INIT_FALL_SPEED;
    jump_once=false;
    jump_twice=false;
    //设置角色边框
    role_Rect.setWidth(51);
    role_Rect.setHeight(102);
    //调整角色在矩形中的位置
    role_Rect.moveTo(x+17,y+8);
}

//根据位置获取角色状态图片
QPixmap Role::getImg(){
    if(y>=ROLE_ON_GROUNG_POS_Y){
        return run_img[current_run_img];
    }
    else return jump_img;
}

void Role::jump(){
    if(y==ROLE_ON_GROUNG_POS_Y){
        jump_once=false;
        jump_twice=false;
        fall_speed=INIT_FALL_SPEED;
    }
    if(jump_twice||(jump_Timer.remainingTime()>200&&jump_Timer.isActive())){
        return;
    }
    if(y==ROLE_ON_GROUNG_POS_Y){
        jump_Timer.start();
        jump_once=true;
    }
    if(y<ROLE_ON_GROUNG_POS_Y&&!jump_twice){
        jump_Timer.start();
        jump_twice=true;
    }
}

void Role::updatePositionY(){
    if(jump_Timer.isActive()){
        y-=jump_Timer.remainingTime()/45;
    }
    else{
        fall_speed+=0.03;              //下落加速度
        y+=fall_speed;
    }
    if(y>=ROLE_ON_GROUNG_POS_Y){
        y=ROLE_ON_GROUNG_POS_Y;
    }
    role_Rect.moveTo(x+17,y+8);
}
