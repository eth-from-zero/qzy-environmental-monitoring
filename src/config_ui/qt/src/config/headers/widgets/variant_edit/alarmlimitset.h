#ifndef ALARMLIMITSET_H
#define ALARMLIMITSET_H

#include <QWidget>
#include <QStandardItemModel>

#include "ui_ve_alarmlimitset.h"

#include "headers/widgets/variant_edit/alarmlimitset/alarmlimitedit.h"
#include "headers/widgets/common/confirmation_dialog.h"

class Alarmlimitset : public QWidget {
public:
    Alarmlimitset(QWidget* page);
    ~Alarmlimitset() = default;

private:
    std::unique_ptr<Ui::VEAlarmlimitset> ui_;
    std::unique_ptr<QStandardItemModel> table_view_model_;
    std::unique_ptr<AlarmlimitEdit> alarmlimit_add_dialog_;
    std::unique_ptr<AlarmlimitEdit> alarmlimit_update_dialog_;
    std::unique_ptr<ConfirmationDialog> alarmlimit_delete_dialog_;
};

#endif // ALARMLIMITSET_H
