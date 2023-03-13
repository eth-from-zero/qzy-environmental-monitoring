#ifndef UNITSET_H
#define UNITSET_H

#include <QWidget>
#include <QStandardItemModel>

#include "ui_ve_unitset.h"

#include "headers/widgets/measurement/variant_edit/unitset/selectunit.h"

class Unitset : public QWidget {
public:
    Unitset(QWidget* page);
    ~Unitset() = default;

private:
    std::unique_ptr<Ui::VEUnitset> ui_;
    std::unique_ptr<QStandardItemModel> table_view_model_;
    std::unique_ptr<Selectunit> select_unit_dialog_;
};

#endif // UNITSET_H
