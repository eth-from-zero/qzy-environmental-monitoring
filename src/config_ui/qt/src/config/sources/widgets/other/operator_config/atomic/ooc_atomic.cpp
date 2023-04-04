#include "headers/widgets/other/operator_config/atomic/ooc_atomic.h"

namespace other {

namespace operator_config {

OOCAtomic::OOCAtomic(QWidget* page): QDialog(nullptr) {
    ui_ = std::make_unique<Ui::OOCAtomic>();
    ui_->setupUi(page);

    {
        table_view_model_ = std::make_unique<QStandardItemModel>();
        table_view_model_->setHorizontalHeaderLabels({"通道编号", "通道名称", "对应数值变量", "源单位"});
        {
            auto item = new QStandardItem();
            item->setCheckable(false);
            item->setText("InValueChannel_1");
            table_view_model_->setItem(0, 0, item);
        }
        {
            auto item = new QStandardItem();
            item->setCheckable(false);
            item->setText("数值输入通道1");
            table_view_model_->setItem(0, 1, item);
        }
        ui_->tv->setModel(table_view_model_.get());
        ui_->tv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }

    connect(ui_->btn_ok, &QPushButton::clicked, this, [this]() {
        this->reject();
    });
    connect(ui_->btn_cancel, &QPushButton::clicked, this, [this]() {
        this->reject();
    });
}

}

}
