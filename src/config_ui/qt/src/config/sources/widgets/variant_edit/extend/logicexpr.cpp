#include <QStandardItemModel>

#include <QDebug>

#include "headers/widgets/variant_edit/extend/logicexpr.h"

Logicexpr::Logicexpr(QWidget*): QDialog(nullptr) {
    ui_ = std::make_unique<Ui::VEEDLogicexpr>();
    ui_->setupUi(this);

    {
        left_list_view_model_ = std::make_unique<QStandardItemModel>();
        left_list_view_model_->setHorizontalHeaderLabels({"单位类型"});
        {
            auto item = new QStandardItem();
            item->setCheckable(true);
            item->setCheckState(Qt::Unchecked);
            item->setText("气浓度");
            left_list_view_model_->appendRow(item);
        }
        {
            auto item = new QStandardItem();
            item->setCheckable(true);
            item->setCheckState(Qt::Unchecked);
            item->setText("水浓度");
            left_list_view_model_->setItem(1, 0, item);
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
