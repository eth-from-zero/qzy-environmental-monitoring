#include "headers/widgets/variant_edit/alarmlimitset/alarmlimitedit.h"

#include <QPushButton>

AlarmlimitEdit::AlarmlimitEdit(QWidget*): QDialog(nullptr) {
    ui_ = std::make_unique<Ui::VEALAlarmlimitedit>();
    ui_->setupUi(this);

    connect(ui_->btn_ok, &QPushButton::clicked, this, [this]() {
        this->reject();
    });
    connect(ui_->btn_cancel, &QPushButton::clicked, this, [this]() {
        this->reject();
    });
}
