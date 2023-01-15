#ifndef MEASURINGEDIT_H
#define MEASURINGEDIT_H

#include <QDialog>
#include <QStandardItemModel>

#include "ui_ve_me_measuringedit.h"

class Measuringedit : public QDialog {
public:
    Measuringedit(QWidget* parent = nullptr);
    ~Measuringedit() = default;

private:
    std::unique_ptr<Ui::VEMEMeasuringedit> ui_;
    std::unique_ptr<QStandardItemModel> left_table_view_model_;
    std::unique_ptr<QStandardItemModel> right_table_view_model_;
};

#endif // MEASURINGEDIT_H
