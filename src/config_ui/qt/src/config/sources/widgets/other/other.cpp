#include "headers/widgets/other/other.h"

OtherPage::OtherPage(QWidget* parent)
    : QWidget(parent) {
    ui_ = std::make_unique<Ui::Other>();
    ui_->setupUi(this);

    operator_config_ = std::make_unique<other::operator_config::OperatorConfig>();

    connect(ui_->btn_systask, &QPushButton::clicked, this, [this]() {
        operator_config_->exec();
    });
}
