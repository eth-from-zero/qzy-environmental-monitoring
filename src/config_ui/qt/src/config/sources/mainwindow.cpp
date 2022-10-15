#include "headers/mainwindow.h"
#include "ui_main.h"

#include "headers/welcome.h"

Main::Main(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Window|Qt::FramelessWindowHint |Qt::WindowSystemMenuHint|Qt::WindowMinimizeButtonHint|Qt::WindowMaximizeButtonHint);

    welcome_ = std::make_unique<welcome>(this);
//    welcome_->setWindowFlag(Qt::Window);

    setMenuWidget(welcome_.get());
}

Main::~Main()
{
    delete ui;
}

