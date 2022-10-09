#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./ui_welcome.h"

#include <memory>

#include "pages/welcome.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , welcome_(std::make_unique<Ui::Welcome>())
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

