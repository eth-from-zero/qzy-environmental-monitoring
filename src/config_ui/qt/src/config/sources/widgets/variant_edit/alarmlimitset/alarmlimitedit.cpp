#include "headers/widgets/variant_edit/alarmlimitset/alarmlimitedit.h"

Measuringedit::Measuringedit(QWidget*): QDialog(nullptr) {
    ui_ = std::make_unique<Ui::VEMEMeasuringedit>();
    ui_->setupUi(this);

    connect(ui_->btn_ok, &QPushButton::clicked, this, [this]() {
        this->reject();
    });
    connect(ui_->btn_cancel, &QPushButton::clicked, this, [this]() {
        this->reject();
    });
}
