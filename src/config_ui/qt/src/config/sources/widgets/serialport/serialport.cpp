#include "headers/widgets/serialport/serialport.h"

#include <QDebug>

SerialportPage::SerialportPage(QWidget* parent)
    : QWidget(parent) {
    ui_ = std::make_unique<Ui::Serialport>();
    ui_->setupUi(this);

    auto append_fn = [&](const QString& text) {
        auto item = new QStandardItem();
        item->setCheckable(true);
        item->setCheckState(Qt::Unchecked);
        item->setText(text);
        list_view_model_->appendRow(item);
    };

    list_view_model_ = std::make_unique<QStandardItemModel>();
    append_fn("和利时PLC_2023版");
    append_fn("FPI水质归一化仪表(NH4)");
    append_fn("FPI水质归一化仪表(CODMn)");
    append_fn("FPI水质归一化仪表(TP)");

    auto append_tv_fn = [&](int i, int j, const QString& text) {
        auto item = new QStandardItem();
        item->setCheckable(false);
        item->setText(text);
        table_view_model_->setItem(i, j, item);
    };

    table_view_model_ = std::make_unique<QStandardItemModel>();
    table_view_model_->setHorizontalHeaderLabels({"有效", "通道名称", "端口号", "波特率", "目标值"});
    {
        auto item = new QStandardItem();
        item->setCheckable(true);
        item->setCheckState(Qt::Checked);
        table_view_model_->setItem(0, 0, item);

        append_tv_fn(0, 1, "和利时PLC_2023版通道");
        append_tv_fn(0, 2, "COM1");
        append_tv_fn(0, 3, "38400");
    }
    ui_->tv->setModel(table_view_model_.get());
    ui_->tv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui_->lv->setModel(list_view_model_.get());
}



