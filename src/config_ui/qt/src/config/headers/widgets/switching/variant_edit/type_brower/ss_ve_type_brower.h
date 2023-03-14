#ifndef SS_VE_TYPE_BROWER_H
#define SS_VE_TYPE_BROWER_H

#include <QDialog>
#include <QStandardItemModel>

#include "ui_si_ve_type_brower.h"

namespace si_ve {

class TypeBrower : public QDialog {
public:
    TypeBrower(QWidget* parent = nullptr);
    ~TypeBrower() = default;

private:
    std::unique_ptr<Ui::SIVETypeBrower> ui_;
    std::unique_ptr<QStandardItemModel> table_view_model_;
};

}

#endif // SS_VE_TYPE_BROWER_H
