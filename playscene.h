#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <QObject>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    //explicit PlayScene(QWidget *parent = nullptr);

    PlayScene(int index);

    //记录当前关卡号
    int levelindex;

    //重写绘图事件
    void paintEvent(QPaintEvent*);

signals:
    void chooseSceneBack();
};

#endif // PLAYSCENE_H
