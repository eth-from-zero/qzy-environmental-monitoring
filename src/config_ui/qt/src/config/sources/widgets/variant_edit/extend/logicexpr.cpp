#include <QStandardItemModel>

#include <QDebug>

#include "headers/widgets/variant_edit/extend/logicexpr.h"

Logicexpr::Logicexpr(QWidget*): QDialog(nullptr) {
    ui_ = std::make_unique<Ui::VEEDLogicexpr>();
    ui_->setupUi(this);

    {
        left_list_view_model_ = std::make_unique<QStandardItemModel>();

        right_list_view_model_ = std::make_unique<QStandardItemModel>();
        {
            auto item = new QStandardItem();
            item->setCheckable(true);
            item->setCheckState(Qt::Unchecked);
            item->setText("IF");
            right_list_view_model_->appendRow(item);
        }
        {
            auto item = new QStandardItem();
            item->setCheckable(true);
            item->setCheckState(Qt::Unchecked);
            item->setText("CASE");
            right_list_view_model_->appendRow(item);
        }

        ui_->lv_expr->setModel(left_list_view_model_.get());
    }

    connect(ui_->btn_ok, &QPushButton::clicked, this, [this]() {
        this->reject();
    });
    connect(ui_->btn_cancel, &QPushButton::clicked, this, [this]() {
        this->reject();
    });
}
