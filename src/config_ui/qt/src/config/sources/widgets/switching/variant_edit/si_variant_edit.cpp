#include "headers/widgets/switching/variant_edit/si_variant_edit.h"

namespace switching {

VariantEdit::VariantEdit(QWidget *parent)
    : QDialog(parent) {
    ui_ = std::make_unique<Ui::SIVariantEditDialog>();
    ui_->setupUi(this);

    input_brower_dialog_ = std::make_unique<si_ve::TypeBrower>();
    output_brower_dialog_ = std::make_unique<si_ve::TypeBrower>();

    connect(ui_->btn_input_brower, &QPushButton::clicked, this, [this]() {
        input_brower_dialog_->exec();
    });
    connect(ui_->btn_output_brower, &QPushButton::clicked, this, [this]() {
        output_brower_dialog_->exec();
    });
}

}
