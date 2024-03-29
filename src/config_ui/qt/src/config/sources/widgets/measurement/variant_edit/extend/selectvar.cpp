#include <QDebug>

#include "headers/widgets/measurement/variant_edit/extend/selectvar.h"

Selectvar::Selectvar(QWidget*): QDialog(nullptr) {
    ui_ = std::make_unique<Ui::VEEDSelectvar>();
    ui_->setupUi(this);

    {
        left_table_view_model_ = std::make_unique<QStandardItemModel>();
        left_table_view_model_->setHorizontalHeaderLabels({"名称", "单位"});
        {
            auto item = new QStandardItem();
            item->setCheckable(false);
            item->setText("总磷");
            left_table_view_model_->setItem(0, 0, item);
        }
        {
            auto item = new QStandardItem();
            item->setCheckable(false);
            item->setText("mg/l");
            left_table_view_model_->setItem(0, 1, item);
        }
        {
            auto item = new QStandardItem();
            item->setCheckable(false);
            item->setText("压力");
            left_table_view_model_->setItem(1, 0, item);
        }
        {
            auto item = new QStandardItem();
            item->setCheckable(false);
            item->setText("kpa");
            left_table_view_model_->setItem(1, 1, item);
        }
        ui_->tv_left->setModel(left_table_view_model_.get());
        ui_->tv_left->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        right_table_view_model_ = std::make_unique<QStandardItemModel>();
        {
            auto item = new QStandardItem();
            item->setCheckable(false);
            item->setText("湿度");
            right_table_view_model_->setItem(0, 0, item);
        }
        {
            auto item = new QStandardItem();
            item->setCheckable(false);
            item->setText("%");
            right_table_view_model_->setItem(0, 1, item);
        }
        right_table_view_model_->setHorizontalHeaderLabels({"名称", "单位"});
        ui_->tv_right->setModel(right_table_view_model_.get());
        ui_->tv_left->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }

    connect(ui_->btn_toleft, &QPushButton::clicked, this, [this]() {
    });
    connect(ui_->btn_toright, &QPushButton::clicked, this, [this]() {
    });

    connect(ui_->btn_ok, &QPushButton::clicked, this, [this]() {
        this->reject();
    });
    connect(ui_->btn_cancel, &QPushButton::clicked, this, [this]() {
        this->reject();
    });
}
