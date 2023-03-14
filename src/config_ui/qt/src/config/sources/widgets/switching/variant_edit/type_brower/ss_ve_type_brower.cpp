#include <QDebug>

#include "headers/widgets/switching/variant_edit/type_brower/ss_ve_type_brower.h"

namespace si_ve {

TypeBrower::TypeBrower(QWidget*): QDialog(nullptr) {
    ui_ = std::make_unique<Ui::SIVETypeBrower>();
    ui_->setupUi(this);

    {
        table_view_model_ = std::make_unique<QStandardItemModel>();
        table_view_model_->setHorizontalHeaderLabels({"程序集", "类型"});
        {
            auto item = new QStandardItem();
            item->setCheckable(false);
            item->setText("type1.so");
            table_view_model_->setItem(0, 0, item);
        }
        {
            auto item = new QStandardItem();
            item->setCheckable(false);
            item->setText("type2.so");
            table_view_model_->setItem(0, 1, item);
        }
        {
            auto item = new QStandardItem();
            item->setCheckable(false);
            item->setText("type3.so");
            table_view_model_->setItem(1, 0, item);
        }
        {
            auto item = new QStandardItem();
            item->setCheckable(false);
            item->setText("type4.so");
            table_view_model_->setItem(1, 1, item);
        }
        ui_->tv->setModel(table_view_model_.get());
        ui_->tv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }

    connect(ui_->btn_ok, &QPushButton::clicked, this, [this]() {
        this->reject();
    });
    connect(ui_->btn_cancel, &QPushButton::clicked, this, [this]() {
        this->reject();
    });
}

}
