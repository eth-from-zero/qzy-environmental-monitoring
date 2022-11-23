#include "headers/widgets/variant_edit.h"

VariantEdit::VariantEdit(QWidget *parent)
    : QDialog(parent) {
    ui_ = std::make_unique<Ui::VariantEditDialog>();
    ui_->setupUi(this);
}
