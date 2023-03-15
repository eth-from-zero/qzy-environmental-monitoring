#include "headers/widgets/device/device.h"

#include <QDebug>

DevicePage::DevicePage(QWidget* parent)
    : QWidget(parent) {
    ui_ = std::make_unique<Ui::Device>();
    ui_->setupUi(this);

    auto append_fn = [&](const QString& text) {
        auto item = new QStandardItem();
        item->setCheckable(true);
        item->setCheckState(Qt::Unchecked);
        item->setText(text);
        list_view_model_->appendRow(item);
    };

    list_view_model_ = std::make_unique<QStandardItemModel>();
    append_fn("采水泵PU1");
    append_fn("采水泵PU2");
    append_fn("清水泵PU2");

    ui_->lv->setModel(list_view_model_.get());

    ui_->lv->setContextMenuPolicy(Qt::CustomContextMenu);
    list_view_menu_ = std::make_unique<QMenu>(ui_->lv);
    auto add_action = new QAction("添加");
    connect(add_action, &QAction::triggered, this, [this]() {
        params_config_->exec();
    });
    list_view_menu_->addAction(add_action);
    auto del_action = new QAction("删除");
    connect(del_action, &QAction::triggered, this, [this]() {
    });
    list_view_menu_->addAction(del_action);

    connect(ui_->lv, &QListView::customContextMenuRequested, this, [this](const QPoint& pos) {
        list_view_menu_->exec(ui_->lv->mapToGlobal(pos));
    });

    params_config_ = std::make_unique<device::ParamsConfig>();
}



