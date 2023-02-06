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
    measuring_update_dialog_ = std::make_unique<Measuringedit>();
    measuring_delete_dialog_ = std::make_unique<ConfirmationDialog>();

    connect(measuring_delete_dialog_.get(), &ConfirmationDialog::signal_ok, this, []() {
    });
    connect(measuring_delete_dialog_.get(), &ConfirmationDialog::signal_cancel, this, []() {
    });

    connect(ui_->btn_add, &QPushButton::clicked, this, [this]() {
        measuring_add_dialog_->exec();
    });
    connect(ui_->btn_update, &QPushButton::clicked, this, [this]() {
        measuring_update_dialog_->exec();
    });
    connect(ui_->btn_del, &QPushButton::clicked, this, [this]() {
        measuring_delete_dialog_->set_tips("确认要删除吗");
        measuring_delete_dialog_->exec();
    });
}

