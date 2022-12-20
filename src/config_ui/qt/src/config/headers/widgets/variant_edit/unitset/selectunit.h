#ifndef SELECTUNIT_H
#define SELECTUNIT_H

#include <QWidget>
#include <QStandardItemModel>

#include "ui_ve_us_selectunit.h"

class Selectunit : public QWidget {
public:
    Selectunit(QWidget* page);
    ~Selectunit() = default;

private:
    std::unique_ptr<Ui::VEUSSelectunit> ui_;
    std::unique_ptr<QStandardItemModel> table_view_model_;
};

#endif // SELECTUNIT_H
