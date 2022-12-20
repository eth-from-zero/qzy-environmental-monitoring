#include <QStandardItemModel>

#include <QDebug>

#include "headers/widgets/variant_edit/unitset/selectunit.h"

Selectunit::Selectunit(QWidget* page): QWidget(nullptr) {
    ui_ = std::make_unique<Ui::VEUSSelectunit>();
    ui_->setupUi(page);

    {
        table_view_model_ = std::make_unique<QStandardItemModel>();
        table_view_model_->setHorizontalHeaderLabels({"名称"});
        {
        auto item = new QStandardItem();
        item->setCheckable(true);
        item->setCheckState(Qt::Unchecked);
        item->setText("mg/l");
        table_view_model_->setItem(0, 0, item);
        }
        {
        auto item = new QStandardItem();
        item->setCheckable(true);
        item->setCheckState(Qt::Unchecked);
        item->setText("ug/l");
        table_view_model_->setItem(1, 0, item);
        }
        ui_->tv_left->setModel(table_view_model_.get());

        ui_->tv_left->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }

    {
        table_view_model_ = std::make_unique<QStandardItemModel>();
        table_view_model_->setHorizontalHeaderLabels({"名称"});
        {
            auto item = new QStandardItem();
            item->setCheckable(true);
            item->setCheckState(Qt::Unchecked);
            item->setText("mg/l");
            table_view_model_->setItem(0, 0, item);
        }
        {
            auto item = new QStandardItem();
            item->setCheckable(true);
            item->setCheckState(Qt::Unchecked);
            item->setText("ug/l");
            table_view_model_->setItem(1, 0, item);
        }
        ui_->tv_right->setModel(table_view_model_.get());

        ui_->tv_right->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
}
