#include "mypushbutton.h"
#include<QDebug>
#include<QPixmap>
#include<mainwindow.h>

mypushbutton::mypushbutton(QString normalImg,QString pressImg)
{
    this->normalImgPath = normalImg;
    this->pressedImgPath = pressImg;//保存正常显示路径和选中后显示路径

    QPixmap pix;
    bool ret = pix.load(this->normalImgPath);
    if(!ret){
        QString str= QString("%1 图片加载失败").arg(this->normalImgPath);
        qDebug()<<str;
        return;
    }

    //设定图片的大小
    this->setFixedSize(pix.width(),pix.height());

    //设置不规则图片格式
    this ->setStyleSheet("QPushButton{border:0px;}");

    //设置图片
    this ->setIcon(pix);

    //设置图片大小
    this->setIconSize(QSize(pix.width(),pix.height()));

}
// //当按下返回键图标改变时候
// //鼠标按下事件
// void mypushbutton::mousePressEvent (QMouseEvent*e)
// {
//     if(this->pressedImgPath!=" ")//传入选中后到图片路径不为空，需要选中图片后才能切换
//     {
//         QPixmap pix;
//         bool ret = pix.load(this->pressedImgPath);
//         if(!ret){
//             qDebug()<<"图片加载失败";
//             return;
//         }
//         //设定图片的大小
//         this->setFixedSize(pix.width(),pix.height());

//         //设置不规则图片格式
//         this ->setStyleSheet("QPushButton{border:0px;}");

//         //设置图片
//         this ->setIcon(pix);

//         //设置图片大小
//         this->setIconSize(QSize(pix.width(),pix.height()));

//     }
//     //其他事情交给父类处理
//     QPushButton::mousePressEvent(e);
// }


// //鼠标释放事件
// void mypushbutton::mouseReleaseEvent(QMouseEvent*e)
// {
//     if(this->pressedImgPath!=" ")//传入选中后到图片路径不为空，需要选中图片后才能切换
//     {
//         QPixmap pix;
//         bool ret = pix.load(this->normalImgPath);
//         if(!ret){
//             qDebug()<<"图片加载失败";
//             return;
//         }
//         //设定图片的大小
//         this->setFixedSize(pix.width(),pix.height());

//         //设置不规则图片格式
//         this ->setStyleSheet("QPushButton{border:0px;}");

//         //设置图片
//         this ->setIcon(pix);

//         //设置图片大小
//         this->setIconSize(QSize(pix.width(),pix.height()));

//     }
//     //其他事情交给父类处理
//     QPushButton::mouseReleaseEvent(e);
// }
