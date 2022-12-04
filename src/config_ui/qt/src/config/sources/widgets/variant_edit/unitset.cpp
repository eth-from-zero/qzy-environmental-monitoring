#ifndef UNITSET_CPP
#define UNITSET_CPP

#include <QStandardItemModel>

#include "headers/widgets/variant_edit/unitset.h"

Unitset::Unitset(QWidget* parent)
    : QWidget(parent) {
    ui_ = std::make_unique<Ui::VEUnitset>();
    ui_->setupUi(this);

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
    ui_->lv->setModel(table_view_model_.get());
}

#endif // UNITSET_CPP
