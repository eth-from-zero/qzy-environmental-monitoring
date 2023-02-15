#ifndef ALARMLIMITSET_H
#define ALARMLIMITSET_H

#include <QDialog>
#include <QStandardItemModel>

#include "ui_ve_al_alarmlimitedit.h"

class AlarmlimitEdit : public QDialog {
public:
    AlarmlimitEdit(QWidget* parent = nullptr);
    ~AlarmlimitEdit() = default;

private:
    std::unique_ptr<Ui::VEALAlarmlimitedit> ui_;
};

#endif // ALARMLIMITSET_H
