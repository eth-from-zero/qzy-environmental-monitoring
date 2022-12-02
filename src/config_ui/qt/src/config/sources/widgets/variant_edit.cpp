#include "headers/widgets/variant_edit.h"

VariantEdit::VariantEdit(QWidget *parent)
    : QDialog(parent) {
    ui_ = std::make_unique<Ui::VariantEditDialog>();
    ui_->setupUi(this);

    basic_widget_ = std::make_unique<Ui::VEBasic>();
    basic_widget_->setupUi(ui_->tab_basic);

    extend_widget_ = std::make_unique<Ui::VEExtend>();
    extend_widget_->setupUi(ui_->tab_extend);

    unitset_widget_ = std::make_unique<Ui::VEUnitset>();
    unitset_widget_->setupUi(ui_->tab_unit_set);

    list_view_model_ = std::make_unique<QStandardItemModel>();
//    auto item = std::make_unique<QStandardItem>();
    auto item = new QStandardItem();
    item->setCheckable(true);
    item->setCheckState(Qt::Unchecked);
    item->setText("水温");
    list_view_model_->appendRow(item);
    ui_->lv->setModel(list_view_model_.get());
}
