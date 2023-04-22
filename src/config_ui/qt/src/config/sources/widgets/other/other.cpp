#include "headers/widgets/other/other.h"

OtherPage::OtherPage(QWidget* parent)
    : QWidget(parent) {
    ui_ = std::make_unique<Ui::Other>();
    ui_->setupUi(this);

    operator_config_ = std::make_unique<other::operator_config::OperatorConfig>();
    timer_config_ = std::make_unique<other::timer_config::TimerConfig>();

    connect(ui_->btn_systask, &QPushButton::clicked, this, [this]() {
        operator_config_->exec();
    });
    connect(ui_->btn_timer, &QPushButton::clicked, this, [this]() {
        timer_config_->exec();
    });
}
