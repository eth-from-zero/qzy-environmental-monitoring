#include "headers/widgets/switching/variant_edit/variant_edit.h"

namespace switching {

VariantEdit::VariantEdit(QWidget *parent)
    : QDialog(parent) {
    ui_ = std::make_unique<Ui::SIVariantEditDialog>();
    ui_->setupUi(this);
}

}
