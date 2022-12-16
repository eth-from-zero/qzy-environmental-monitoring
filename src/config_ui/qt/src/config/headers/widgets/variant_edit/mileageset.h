#ifndef MILEAGESET_H
#define MILEAGESET_H

#include <QWidget>
#include <QStandardItemModel>

#include "ui_ve_mileageset.h"

class Mileageset : public QWidget {
public:
    Mileageset(QWidget* page);
    ~Mileageset() = default;

private:
    std::unique_ptr<Ui::VEMileageset> ui_;
    std::unique_ptr<QStandardItemModel> table_view_model_;
};

#endif // MILEAGESET_H
