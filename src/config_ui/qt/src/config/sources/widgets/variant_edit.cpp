#include "headers/widgets/variant_edit.h"

VariantEdit::VariantEdit(QWidget *parent)
    : QDialog(parent) {
    ui_ = std::make_unique<Ui::VariantEditDialog>();
    ui_->setupUi(this);

    basic_widget_ = std::make_unique<Ui::VEBasic>();
    basic_widget_->setupUi(ui_->tab_basic);

    extend_widget_ = std::make_unique<Ui::VEExtend>();
    extend_widget_->setupUi(ui_->tab_extend);

    unitset_widget_ = std::make_unique<Unitset>(ui_->tab_unit_set);
    mileageset_widget_ = std::make_unique<Mileageset>(ui_->tab_miles_set);
}
