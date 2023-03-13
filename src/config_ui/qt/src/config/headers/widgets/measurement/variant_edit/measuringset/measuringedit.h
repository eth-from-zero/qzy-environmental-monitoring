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
};

#endif // MEASURINGEDIT_H
