 #ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<chooselevelscene.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //绘图事件(绘制开始界面的封面)
    void paintEvent(QPaintEvent*);

    chooselevelscene *choosescene;


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
