#include "headers/welcome.h"
#include "ui_welcome.h"

welcome::welcome(QWidget *parent)
    : BaseWidget(parent)
    , ui_(new Ui::welcome())
{
}

welcome::~welcome() {
    delete ui_;
}
