#include "headers/widgets/measurement/measurement.h"

#include <QDebug>

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
    list_view_menu_ = std::make_unique<QMenu>(ui_->lv);
    auto add_action = new QAction("添加");
    connect(add_action, &QAction::triggered, this, [this]() {
        variant_edit_->exec();
    });
    list_view_menu_->addAction(add_action);
    auto del_action = new QAction("删除");
    connect(del_action, &QAction::triggered, this, [this]() {
    });
    list_view_menu_->addAction(del_action);

    connect(ui_->lv, &QListView::customContextMenuRequested, this, [this](const QPoint& pos) {
        list_view_menu_->exec(ui_->lv->mapToGlobal(pos));
    });

    variant_edit_ = std::make_unique<measuringset::VariantEdit>();
}

