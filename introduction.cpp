#include "introduction.h"
#include "ui_introduction.h"
#include "config.h"

#include <QFontDatabase>

Introduction::Introduction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Introduction)
{
    ui->setupUi(this);

    setWindowTitle("GAMEIRODUCTION");

    // 更改文本颜色
    QPalette palette;
    palette.setColor(QPalette::WindowText, Qt::blue); // 设置文本颜色为红色
    ui->label->setPalette(palette);
    ui->label_2->setPalette(palette);
    ui->label_3->setPalette(palette);
    ui->label_5->setPalette(palette);
    ui->label_6->setPalette(palette);
    ui->label_7->setPalette(palette);

    QLabel *label_4 = new QLabel(this);				//创建标签
    label_4->setPixmap(QPixmap(":/res01/melofy.png"));
    label_4->move(width()*0.3,height()*0.2);

    QLabel *label_5 = new QLabel(this);
    label_5->setPixmap(QPixmap(":/res01/wudi.png"));
    label_5->move(width()*0.4,height()*0.2);

    QLabel *piclabel = new QLabel(this);
    piclabel->setPixmap(QPixmap(":/res01/zhadan.png"));
    piclabel->move(width()*0.3,height()*0.4);

    QLabel *piclabel2 = new QLabel(this);
    piclabel2->setPixmap(QPixmap(":/res01/boxdisappear.png"));
    piclabel2->move(width()*0.4,height()*0.4);

    //设置字体
    int fontId=QFontDatabase::addApplicationFont(QStringLiteral(":/res/hk4e_zh-cn.ttf"));   //导入字体文件
    QStringList fontFamilies=QFontDatabase::applicationFontFamilies(fontId);
    QFont font;
    font.setFamily(fontFamilies[0]);
    ui->label->setFont(font);
    ui->label_2->setFont(font);
    ui->label_3->setFont(font);
    ui->label_5->setFont(font);
    ui->label_6->setFont(font);
    ui->label_7->setFont(font);

}

Introduction::~Introduction()
{
    delete ui;
}
