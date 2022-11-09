#include "headers/widgets/welcome.h"

//#include "ui_welcome.h"

WelcomePage::WelcomePage(QWidget* parent)
    : QWidget(parent) {
    ui_ = std::make_unique<Ui::Welcome>();
//    ui_->setupUi(parent);
}
