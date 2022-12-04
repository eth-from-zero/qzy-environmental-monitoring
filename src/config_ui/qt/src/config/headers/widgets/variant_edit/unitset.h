#ifndef UNITSET_H
#define UNITSET_H

#include <QWidget>
#include <QStandardItemModel>

#include "ui_ve_unitset.h"

class Unitset : public QWidget {
public:
    Unitset(QWidget* parent = nullptr);
    ~Unitset() = default;

private:
    std::unique_ptr<Ui::VEUnitset> ui_;
    std::unique_ptr<QStandardItemModel> table_view_model_;
};

#endif // UNITSET_H
