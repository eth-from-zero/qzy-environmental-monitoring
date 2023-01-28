#ifndef MILEAGESET_H
#define MILEAGESET_H

#include <QWidget>
#include <QStandardItemModel>

#include "ui_ve_measuringset.h"

#include "headers/widgets/variant_edit/measuringset/measuringedit.h"

class Measuringset : public QWidget {
public:
    Measuringset(QWidget* page);
    ~Measuringset() = default;

private:
    std::unique_ptr<Ui::VEMeasuringset> ui_;
    std::unique_ptr<QStandardItemModel> table_view_model_;
    std::unique_ptr<Measuringedit> measuring_add_dialog_;
    std::unique_ptr<Measuringedit> measuring_update_dialog_;
    std::unique_ptr<Measuringedit> measuring_delete_dialog_;
};

#endif // MILEAGESET_H
