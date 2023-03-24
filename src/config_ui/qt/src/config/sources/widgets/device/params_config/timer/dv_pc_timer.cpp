#include "headers/widgets/device/params_config/timer/dv_pc_timer.h"

namespace device {

PCTimer::PCTimer(QWidget*): QDialog(nullptr) {
    ui_ = std::make_unique<Ui::DVPCTImer>();
    ui_->setupUi(this);

    connect(ui_->btn_ok, &QPushButton::clicked, this, [this]() {
        this->reject();
    });
    connect(ui_->btn_cancel, &QPushButton::clicked, this, [this]() {
        this->reject();
    });
}

}
