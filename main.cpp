// #include "mainwindow.h"

#include <QApplication>
#include "startscene.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    startscene q;
    q.show();//实例化q让其成为显示的第一个窗口
    MainWindow w;

    return a.exec();
}
