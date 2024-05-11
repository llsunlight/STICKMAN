#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include<QDebug>
#include<QPixmap>

class mypushbutton : public QPushButton
{
    Q_OBJECT
public:
    //explicit mypushbutton(QWidget *parent = nullptr);

    mypushbutton(QString normalImg,QString pressImg = "");//

    QString normalImgPath; //默认显示图片路径
    QString pressedImgPath; //按下按钮后显示图片的路径

    // //鼠标按下事件
    // void mousePressEvent (QMouseEvent*e);
    // //鼠标释放事件
    // void mouseReleaseEvent(QMouseEvent*e);


signals:
};



#endif // MYPUSHBUTTON_H
