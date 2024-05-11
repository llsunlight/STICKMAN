#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include <playscene.h>
class chooselevelscene : public QMainWindow
{
    Q_OBJECT
public:
    explicit chooselevelscene(QWidget *parent = nullptr);

    //重写绘图事件
    void paintEvent(QPaintEvent*);

    //维护游戏场景指针
    PlayScene*playscene;

signals:
    //自定义信号 只需要声明不需要实现
    void chooseSceneBack();




public slots:
};

#endif // CHOOSELEVELSCENE_H
