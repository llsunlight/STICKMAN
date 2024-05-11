#ifndef CONFIG_H
#define CONFIG_H


#define GAME_WIDTH 1080//宽度
#define GAME_HEIGHT 690//高度
#define GAME_TITLE "STICKMAN-RUN"

#define GAME_RES_PATH "./img.rcc"            //rcc文件
#define BACKGROUND_PATH ":/res01/background.jpg"   //背景
#define GROUND_PATH ":/res01/ground.png"           //地面
#define JUMP_PATH ":/res01/jump.png"                //跳跃
#define BOX_PATH ":/res01/boxdisappear.png"         //箱子
#define BOX_PATH2 ":/res01/boxd.png"
#define ZHADAN_PATH ":/res01/zhadan.png"     //炸弹c艹图片
#define ZHADAN_PATH2 ":/res01/boxdisappear.png"
#define STOP_PATH ":/res01/stop.png"               //箭头
#define STOP_PATH2 ":/res01/stop2.png"
#define MELODY_PATH ":/res01/melofy.png"             //旋律
#define WUDI_PATH ":/res01/wudi.png"               //捡到就无敌

#define SCENE_SCROLL_SPEED 3     //场景移动速度
#define GAME_RATE 8              //屏幕刷新间隔
#define RUN_INTERVAL 60          //奔跑图片刷新间隔
#define INIT_FALL_SPEED 3        //初始下落速度
#define ROLE_ON_GROUNG_POS_Y 450   //角色位于地面上的Y轴坐标

#define JUMP_DURATION 380           //跳跃持续时间
#define SPRINT_DURATION 250         //冲刺持续时间
#define SPRINT_INTERVAL 1600        //冲刺间隔时间
#define ADD_BARRIER_INTERVAL 1500   //生成障碍物间隔时间
#define ADD_MELODY_INTERVAL 16000    //生成旋律间隔时间
#define PROTECTED_DURATION 6000     //无敌时间

#endif // CONFIG_H
