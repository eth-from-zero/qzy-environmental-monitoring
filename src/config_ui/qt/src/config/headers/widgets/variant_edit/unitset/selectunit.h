#ifndef SELECTUNIT_H
#define SELECTUNIT_H

#include <QDialog>
#include <QStandardItemModel>

#include "ui_ve_us_selectunit.h"

class Selectunit : public QDialog {
public:
    Selectunit(QWidget* parent = nullptr);
    ~Selectunit() = default;

private:
    std::unique_ptr<Ui::VEUSSelectunit> ui_;
    std::unique_ptr<QStandardItemModel> left_table_view_model_;
    std::unique_ptr<QStandardItemModel> right_table_view_model_;
};

#endif // SELECTUNIT_H
