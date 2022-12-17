#include <QStandardItemModel>

#include <QDebug>

#include "headers/widgets/variant_edit/alarmlimitset.h"

Alarmlimitset::Alarmlimitset(QWidget* page): QWidget(nullptr) {
    ui_ = std::make_unique<Ui::VEAlarmlimitset>();
    ui_->setupUi(page);

    table_view_model_ = std::make_unique<QStandardItemModel>();
    table_view_model_->setHorizontalHeaderLabels({"编号", "名称", "报警下限值", "报警上限值"});
    {
        auto item = new QStandardItem();
        item->setCheckable(true);
        item->setCheckState(Qt::Unchecked);
        item->setText("312");
        table_view_model_->setItem(0, 0, item);
    }
    {
        auto item = new QStandardItem();
        item->setCheckable(false);
        item->setText("TP报警限值");
        table_view_model_->setItem(0, 1, item);
    }
    {
        auto item = new QStandardItem();
        item->setCheckable(false);
        item->setText("0");
        table_view_model_->setItem(0, 2, item);
    }
    {
        auto item = new QStandardItem();
        item->setCheckable(false);
        item->setText("1");
        table_view_model_->setItem(0, 3, item);
    }
    ui_->tv->setModel(table_view_model_.get());

    ui_->tv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(ui_->btn_add, &QPushButton::clicked, this, [this]() {
        qDebug() << "select be clicked";
    });
}
