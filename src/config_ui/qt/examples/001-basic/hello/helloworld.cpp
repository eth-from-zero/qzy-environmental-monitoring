#include "helloworld.h"
#include "./ui_helloworld.h"

HelloWorld::HelloWorld(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HelloWorld)
{
    ui->setupUi(this);

    ui->pushButton->setText("open");
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(PushButtonOnClicked()));
}

void HelloWorld::PushButtonOnClicked() {
    ui->label->setText("hello");
}

HelloWorld::~HelloWorld()
{
    delete ui;
}

