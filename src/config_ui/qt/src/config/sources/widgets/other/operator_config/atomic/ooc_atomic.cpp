#include "headers/widgets/other/operator_config/atomic/ooc_atomic.h"

namespace other {

namespace operator_config {

OOCAtomic::OOCAtomic(QWidget* page): QDialog(nullptr) {
    ui_ = std::make_unique<Ui::OOCAtomic>();
    ui_->setupUi(page);

    {
        table_view_model_ = std::make_unique<QStandardItemModel>();
        table_view_model_->setHorizontalHeaderLabels({"序号", "名称", "资源", "定时模式", "允许手动", "实现模板"});

        auto insert_fn = [&](int x, int y, QString content) {
            auto item = new QStandardItem();
            item->setCheckable(false);
            item->setText(content);
            table_view_model_->setItem(x, y, item);
        };

        {
            insert_fn(0, 0, "1031");
            insert_fn(0, 1, "TP_仪表测量");
        }

        ui_->tv->setModel(table_view_model_.get());
        ui_->tv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
}

}

}
