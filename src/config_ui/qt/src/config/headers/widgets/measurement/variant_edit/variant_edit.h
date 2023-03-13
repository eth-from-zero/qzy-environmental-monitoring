#ifndef VARIANT_EDIT_H
#define VARIANT_EDIT_H

#include <memory>
#include "ui_mm_variant_edit.h"
#include "ui_ve_basic.h"
#include "ui_ve_extend.h"
#include "ui_ve_unitset.h"

#include "headers/widgets/measurement/variant_edit/unitset.h"
#include "headers/widgets/measurement/variant_edit/measuringset.h"
#include "headers/widgets/measurement/variant_edit/alarmlimitset.h"

#include "headers/widgets/measurement/variant_edit/extend/logicexpr.h"

#include <QDialog>

class VariantEdit : public QDialog
{
    Q_OBJECT

public:
    VariantEdit(QWidget *parent= nullptr);
    ~VariantEdit() = default;

private:
    std::unique_ptr<Ui::VariantEditDialog> ui_;
    std::unique_ptr<Ui::VEBasic> basic_widget_;
    std::unique_ptr<Ui::VEExtend> extend_widget_;
    std::unique_ptr<Unitset> unitset_widget_;
    std::unique_ptr<Measuringset> measuringset_widget_;
    std::unique_ptr<Alarmlimitset> alarmlimitset_widget_;

    std::unique_ptr<Logicexpr> extend_logicexpr_;
};


#endif // VARIANT_EDIT_H
