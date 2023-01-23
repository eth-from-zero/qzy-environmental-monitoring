#include <QStandardItemModel>

#include <QDebug>

#include "headers/widgets/variant_edit/measuringset.h"

Measuringset::Measuringset(QWidget* page): QWidget(nullptr) {
    ui_ = std::make_unique<Ui::VEMeasuringset>();
    ui_->setupUi(page);

    table_view_model_ = std::make_unique<QStandardItemModel>();
    table_view_model_->setHorizontalHeaderLabels({"编号", "名称", "最小值", "最大值"});
    {
        auto item = new QStandardItem();
        item->setCheckable(true);
        item->setCheckState(Qt::Unchecked);
        item->setText("001");
        table_view_model_->setItem(0, 0, item);
    }
    {
        auto item = new QStandardItem();
        item->setCheckable(false);
        item->setText("Mike");
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
        item->setText("100");
        table_view_model_->setItem(0, 3, item);
    }
    ui_->tv->setModel(table_view_model_.get());

    ui_->tv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    measuring_add_dialog_ = std::make_unique<Measuringedit>();

    connect(ui_->btn_add, &QPushButton::clicked, this, [this]() {
        measuring_add_dialog_->exec();
    });
}

