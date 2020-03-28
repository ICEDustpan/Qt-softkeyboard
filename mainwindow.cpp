#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "syszuxpinyin.h"
#include "syszuxim.h"
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //启动输入法
    QWSInputMethod* im = new SyszuxIM; QWSServer::setCurrentInputMethod(im);

    //弹出软键盘
    im->updateHandler(QWSInputMethod::FocusIn);

    //设置中文字符
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
