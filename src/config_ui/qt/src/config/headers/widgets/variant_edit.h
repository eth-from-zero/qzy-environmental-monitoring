#ifndef VARIANT_EDIT_H
#define VARIANT_EDIT_H

#include <memory>
#include "ui_variant_edit.h"
#include "ui_basic.h"
#include "ui_extend.h"

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
};


#endif // VARIANT_EDIT_H
