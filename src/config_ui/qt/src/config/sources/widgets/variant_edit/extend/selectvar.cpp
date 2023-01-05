#include <QDebug>

#include "headers/widgets/variant_edit/extend/selectvar.h"

Selectvar::Selectvar(QWidget*): QDialog(nullptr) {
    ui_ = std::make_unique<Ui::VEEDSelectvar>();
    ui_->setupUi(this);

    {
        left_table_view_model_ = std::make_unique<QStandardItemModel>();
        left_table_view_model_->setHorizontalHeaderLabels({"名称", "单位"});
        {
            auto item = new QStandardItem();
            item->setCheckable(true);
            item->setCheckState(Qt::Unchecked);
            item->setText("总磷");
            left_table_view_model_->setItem(0, 0, item);
        }
        {
            auto item = new QStandardItem();
            item->setCheckable(true);
            item->setCheckState(Qt::Unchecked);
            item->setText("mg/l");
            left_table_view_model_->setItem(0, 1, item);
        }
        ui_->tv_left->setModel(right_table_view_model_.get());

        right_table_view_model_ = std::make_unique<QStandardItemModel>();
        right_table_view_model_->setHorizontalHeaderLabels({"名称", "单位"});
        ui_->tv_right->setModel(right_table_view_model_.get());
    }

    connect(ui_->btn_ok, &QPushButton::clicked, this, [this]() {
        this->reject();
    });
    connect(ui_->btn_cancel, &QPushButton::clicked, this, [this]() {
        this->reject();
    });
}
