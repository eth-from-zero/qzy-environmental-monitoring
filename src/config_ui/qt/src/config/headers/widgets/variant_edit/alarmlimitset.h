#ifndef ALARMLIMITSET_H
#define ALARMLIMITSET_H

#include <QWidget>
#include <QStandardItemModel>

#include "ui_ve_alarmlimitset.h"

class Alarmlimitset : public QWidget {
public:
    Alarmlimitset(QWidget* page);
    ~Alarmlimitset() = default;

private:
    std::unique_ptr<Ui::VEAlarmlimitset> ui_;
    std::unique_ptr<QStandardItemModel> table_view_model_;
};

#endif // ALARMLIMITSET_H
