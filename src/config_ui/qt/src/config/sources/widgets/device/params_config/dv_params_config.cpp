#include <QDebug>

#include "headers/widgets/device/params_config/dv_params_config.h"

namespace device {

ParamsConfig::ParamsConfig(QWidget*): QDialog(nullptr) {
    ui_ = std::make_unique<Ui::DVParamsConfig>();
    ui_->setupUi(this);

    connect(ui_->btn_ok, &QPushButton::clicked, this, [this]() {
        this->reject();
    });
    connect(ui_->btn_cancel, &QPushButton::clicked, this, [this]() {
        this->reject();
    });
}

}
