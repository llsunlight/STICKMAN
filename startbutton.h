#ifndef STARTBUTTON_H
#define STARTBUTTON_H

#include <QPushButton>
#include <QString>
#include <QDebug>
#include <QAction>

class startbutton : public QPushButton
{
    Q_OBJECT
public:
    // explicit startbutton(QWidget *parent = nullptr);
    startbutton(QString normalImg,QString pressImg=" ");
    QString normalImgPath; //默认图片路径
    QString pressImgPath; //按下后图片路径

signals:
};

#endif // STARTBUTTON_H
