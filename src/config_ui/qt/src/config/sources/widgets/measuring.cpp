#include "headers/widgets/measuring.h"

#include <QMenu>

MeasuringPage::MeasuringPage(QWidget* parent)
    : QWidget(parent) {
    ui_ = std::make_unique<Ui::Measuring>();
    ui_->setupUi(this);

    list_view_model_ = std::make_unique<QStandardItemModel>();
//    auto item = std::make_unique<QStandardItem>();
    auto item = new QStandardItem();
    item->setCheckable(true);
    item->setCheckState(Qt::Unchecked);
    item->setText("水温");
    list_view_model_->appendRow(item);
    ui_->lv->setModel(list_view_model_.get());

    ui_->lv->setContextMenuPolicy(Qt::CustomContextMenu);
    auto menu = new QMenu(ui_->lv);
    menu->addAction("添加");

    connect(ui_->lv, &QListView::customContextMenuRequested, this, [this, menu](const QPoint& pos) {
        menu->exec(ui_->lv->mapToGlobal(pos));
    });
}

