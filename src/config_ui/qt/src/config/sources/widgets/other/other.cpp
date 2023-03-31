#include "headers/widgets/other/other.h"

OtherPage::OtherPage(QWidget* parent)
    : QWidget(parent) {
    ui_ = std::make_unique<Ui::Other>();
    ui_->setupUi(this);
}
