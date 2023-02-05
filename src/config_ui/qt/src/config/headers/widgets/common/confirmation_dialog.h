#ifndef CONFIRMATION_DIALOG_H
#define CONFIRMATION_DIALOG_H

#include <QDialog>
#include <QString>
#include <QStandardItemModel>

#include "ui_confirmation_dialog.h"

class ConfirmationDialog : public QDialog {
    Q_OBJECT

public:
    ConfirmationDialog(QWidget* parent = nullptr);
    ~ConfirmationDialog() = default;

    void set_tips(const QString&);

Q_SIGNALS:
    void signal_ok();
    void signal_cancel();

private:
    std::unique_ptr<Ui::ConfirmationDialog> ui_;
};

#endif // CONFIRMATION_DIALOG_H
