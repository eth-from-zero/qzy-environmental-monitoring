#include "headers/welcome.h"
#include "ui_welcome.h"

welcome::welcome(QWidget *parent)
    : BaseWidget(parent)
    , ui(new Ui::welcome)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint|windowFlags());
}

welcome::~welcome()
{
    delete ui;
}

