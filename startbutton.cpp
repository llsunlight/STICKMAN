#include "startbutton.h"

startbutton::startbutton(QString normalImg,QString pressImg)
{
    this->normalImgPath=normalImg;//保存图片路径
    this->pressImgPath=pressImg;

    QPixmap pix;
    bool ret=pix.load(this->normalImgPath);
    if(!ret)
    {
        QString str=QString("%加载失败").arg(this->normalImgPath);
        qDebug()<<str;
        return;
    }
    //大小
    this->setFixedSize(pix.width(),pix.height());

    //不规则样式
    this->setStyleSheet("QPushButton{border:0px}");

    //设置图片
    this->setIcon(pix);

    //图片大小
    this->setIconSize(QSize(pix.width()*2,pix.height()*2));
};
