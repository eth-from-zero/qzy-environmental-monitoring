#include <QStandardItemModel>

#include <QDebug>

#include "headers/widgets/variant_edit/unitset.h"

Unitset::Unitset(QWidget* page): QWidget(nullptr) {
    ui_ = std::make_unique<Ui::VEUnitset>();
    ui_->setupUi(page);

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
    ui_->tv->setModel(table_view_model_.get());

    ui_->tv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(ui_->btn_select, &QPushButton::clicked, this, [this]() {
        qDebug() << "select be clicked";
    });
}
