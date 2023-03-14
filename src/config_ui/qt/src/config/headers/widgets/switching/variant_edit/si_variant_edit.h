#ifndef SI_VARIANT_EDIT_H
#define SI_VARIANT_EDIT_H

#include <memory>
#include "ui_si_variant_edit.h"

#include <QDialog>

#include "headers/widgets/switching/variant_edit/type_brower/ss_ve_type_brower.h"


namespace switching {

class VariantEdit : public QDialog
{
    Q_OBJECT

public:
    VariantEdit(QWidget *parent= nullptr);
    ~VariantEdit() = default;

private:
    std::unique_ptr<Ui::SIVariantEditDialog> ui_;
    std::unique_ptr<si_ve::TypeBrower> input_brower_dialog_;
    std::unique_ptr<si_ve::TypeBrower> output_brower_dialog_;
};

}

#endif // SI_VARIANT_EDIT_H
