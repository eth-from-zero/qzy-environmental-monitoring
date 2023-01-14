#ifndef MILEAGESET_H
#define MILEAGESET_H

#include <QWidget>
#include <QStandardItemModel>

#include "ui_ve_measuringset.h"

class Measuringset : public QWidget {
public:
    Measuringset(QWidget* page);
    ~Measuringset() = default;

private:
    std::unique_ptr<Ui::VEMeasuringset> ui_;
    std::unique_ptr<QStandardItemModel> table_view_model_;
};

#endif // MILEAGESET_H
