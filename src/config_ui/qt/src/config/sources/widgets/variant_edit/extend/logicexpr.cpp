#include <QStandardItemModel>

#include <QDebug>

#include "headers/widgets/variant_edit/extend/logicexpr.h"

Selectunit::Selectunit(QWidget*): QDialog(nullptr) {
    ui_ = std::make_unique<Ui::VEUSSelectunit>();
    ui_->setupUi(this);

    {
        left_table_view_model_ = std::make_unique<QStandardItemModel>();
        left_table_view_model_->setHorizontalHeaderLabels({"单位类型"});
        {
            auto item = new QStandardItem();
            item->setCheckable(true);
            item->setCheckState(Qt::Unchecked);
            item->setText("气浓度");
            left_table_view_model_->setItem(0, 0, item);
        }
        {
            auto item = new QStandardItem();
            item->setCheckable(true);
            item->setCheckState(Qt::Unchecked);
            item->setText("水浓度");
            left_table_view_model_->setItem(1, 0, item);
        }
        ui_->tv_left->setModel(left_table_view_model_.get());

        ui_->tv_left->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }

    {
        right_table_view_model_ = std::make_unique<QStandardItemModel>();
        right_table_view_model_->setHorizontalHeaderLabels({"名称", "转换公式", "反转公式"});
        ui_->tv_right->setModel(right_table_view_model_.get());

        ui_->tv_right->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }

    connect(ui_->btn_ok, &QPushButton::clicked, this, [this]() {
        this->reject();
    });
    connect(ui_->btn_cancel, &QPushButton::clicked, this, [this]() {
        this->reject();
    });
}
