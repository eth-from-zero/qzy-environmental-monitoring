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

    ui_->lv->setModel(list_view_model_.get());
}



