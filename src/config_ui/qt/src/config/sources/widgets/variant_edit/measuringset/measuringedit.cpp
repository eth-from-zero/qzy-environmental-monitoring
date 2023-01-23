#include <QStandardItemModel>

#include <QDebug>

#include "headers/widgets/variant_edit/measuringset/measuringedit.h"

Measuringedit::Measuringedit(QWidget*): QDialog(nullptr) {
    ui_ = std::make_unique<Ui::VEMEMeasuringedit>();
    ui_->setupUi(this);
}
