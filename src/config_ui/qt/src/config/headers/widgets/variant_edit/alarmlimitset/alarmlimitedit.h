#ifndef ALARMLIMITSET_H
#define ALARMLIMITSET_H

#include <QDialog>
#include <QStandardItemModel>

#include "ui_ve_me_measuringedit.h"

class AlarmlimitsetEdit : public QDialog {
public:
    AlarmlimitsetEdit(QWidget* parent = nullptr);
    ~AlarmlimitsetEdit() = default;

private:
    std::unique_ptr<Ui::VEAEEdit> ui_;
};

#endif // ALARMLIMITSET_H
