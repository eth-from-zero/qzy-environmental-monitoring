#ifndef SI_VARIANT_EDIT_H
#define SI_VARIANT_EDIT_H

#include <memory>
#include "ui_si_variant_edit.h"

#include <QDialog>

namespace switching {

class VariantEdit : public QDialog
{
    Q_OBJECT

public:
    VariantEdit(QWidget *parent= nullptr);
    ~VariantEdit() = default;

private:
    std::unique_ptr<Ui::SIVariantEditDialog> ui_;
};

}

#endif // SI_VARIANT_EDIT_H
