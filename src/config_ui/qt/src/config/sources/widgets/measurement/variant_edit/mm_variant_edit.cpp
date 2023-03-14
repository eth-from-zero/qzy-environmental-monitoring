#include "headers/widgets/measurement/variant_edit/mm_variant_edit.h"

namespace measuringset {

VariantEdit::VariantEdit(QWidget *parent)
    : QDialog(parent) {
    ui_ = std::make_unique<Ui::VariantEditDialog>();
    ui_->setupUi(this);

    basic_widget_ = std::make_unique<Ui::VEBasic>();
    basic_widget_->setupUi(ui_->tab_basic);

    extend_widget_ = std::make_unique<Ui::VEExtend>();
    extend_widget_->setupUi(ui_->tab_extend);

    extend_logicexpr_ = std::make_unique<Logicexpr>();

    connect(extend_widget_->btn_calcformula, &QPushButton::clicked, this, [this]() {
        extend_logicexpr_->exec();
    });

    unitset_widget_ = std::make_unique<Unitset>(ui_->tab_unit_set);
    measuringset_widget_ = std::make_unique<Measuringset>(ui_->tab_miles_set);
    alarmlimitset_widget_ = std::make_unique<Alarmlimitset>(ui_->tab_alarm_limits_set);
}

}
