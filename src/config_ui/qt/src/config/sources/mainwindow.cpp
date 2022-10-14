#include "headers/mainwindow.h"
#include "ui_main.h"

#include "headers/welcome.h"

Main::Main(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    welcome_ = std::make_unique<welcome>(this);
    welcome_->setWindowFlag(Qt::Window);
}

Main::~Main()
{
    delete ui;
}

