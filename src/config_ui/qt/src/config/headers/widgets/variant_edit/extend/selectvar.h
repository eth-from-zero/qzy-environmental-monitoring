#ifndef SELECTVAR_H
#define SELECTVAR_H

#include <QDialog>
#include <QStandardItemModel>

#include "ui_ve_ed_selectvar.h"

class Selectvar : public QDialog {
public:
    Selectvar(QWidget* parent = nullptr);
    ~Selectvar() = default;

private:
    std::unique_ptr<Ui::VEEDSelectvar> ui_;
    std::unique_ptr<QStandardItemModel> left_table_view_model_;
    std::unique_ptr<QStandardItemModel> right_table_view_model_;
};

#endif // SELECTVAR_H
