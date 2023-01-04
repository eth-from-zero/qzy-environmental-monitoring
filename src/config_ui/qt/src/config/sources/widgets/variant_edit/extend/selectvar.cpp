#include <QDebug>

#include "headers/widgets/variant_edit/extend/selectvar.h"

Selectvar::Selectvar(QWidget*): QDialog(nullptr) {
    ui_ = std::make_unique<Ui::VEEDSelectvar>();
    ui_->setupUi(this);

    {
        left_table_view_model_ = std::make_unique<QStandardItemModel>();

        right_table_view_model_ = std::make_unique<QStandardItemModel>();
        {
            auto item = new QStandardItem();
            item->setCheckable(true);
            item->setCheckState(Qt::Unchecked);
            item->setText("IF");
            right_table_view_model_->appendRow(item);
        }
        {
            auto item = new QStandardItem();
            item->setCheckable(true);
            item->setCheckState(Qt::Unchecked);
            item->setText("CASE");
            right_table_view_model_->appendRow(item);
        }
        ui_->lv_function->setModel(right_table_view_model_.get());
    }

    connect(ui_->btn_ok, &QPushButton::clicked, this, [this]() {
        this->reject();
    });
    connect(ui_->btn_cancel, &QPushButton::clicked, this, [this]() {
        this->reject();
    });
}
