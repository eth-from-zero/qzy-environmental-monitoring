#ifndef VARIANT_EDIT_H
#define VARIANT_EDIT_H

#include <memory>
#include "ui_variant_edit.h"

#include <QWidget>

class VariantEditDialog : public QWidget
{
    Q_OBJECT

public:
    VariantEditDialog(QWidget *parent= nullptr);
    ~VariantEditDialog() = default;

private:
};


#endif // VARIANT_EDIT_H
