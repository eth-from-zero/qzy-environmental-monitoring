#include "headers/widgets/common/confirmation_dialog.h"

#include <QDebug>

ConfirmationDialog::ConfirmationDialog(QWidget*): QDialog(nullptr) {
    ui_ = std::make_unique<Ui::ConfirmationDialog>();
    ui_->setupUi(this);
}
