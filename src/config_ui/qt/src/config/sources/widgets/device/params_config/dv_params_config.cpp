#include <QDebug>

#include "headers/widgets/device/params_config/dv_params_config.h"

namespace device {

ParamsConfig::ParamsConfig(QWidget*): QDialog(nullptr) {
    ui_ = std::make_unique<Ui::DVParamsConfig>();
    ui_->setupUi(this);

    timer_dialog_ = std::make_unique<device::PCTimer>();

    connect(ui_->btn_timer_config, &QPushButton::clicked, this, [this]() {
        timer_dialog_->exec();
    });

    connect(ui_->btn_ok, &QPushButton::clicked, this, [this]() {
        this->reject();
    });
    connect(ui_->btn_cancel, &QPushButton::clicked, this, [this]() {
        this->reject();
    });
}

}
