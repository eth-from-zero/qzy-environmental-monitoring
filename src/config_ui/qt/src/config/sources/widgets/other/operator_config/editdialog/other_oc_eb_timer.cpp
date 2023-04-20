#include "headers/widgets/other/operator_config/editdialog/other_oc_eb_timer.h"

namespace other {

namespace operator_config {

OtherOCEBTimer::OtherOCEBTimer(QWidget* page): QDialog(nullptr) {
    ui_ = std::make_unique<Ui::OtherOCEBTimer>();
    ui_->setupUi(page);

    {
        table_view_model_ = std::make_unique<QStandardItemModel>();
        table_view_model_->setHorizontalHeaderLabels({"类型", "状态", "优先级", "重量", "最多并行", "描述"});

        auto insert_fn = [&](int x, int y, QString content) {
            auto item = new QStandardItem();
            item->setCheckable(false);
            item->setText(content);
            table_view_model_->setItem(x, y, item);
        };

        {
            insert_fn(0, 0, "周期");
            insert_fn(0, 1, "非活跃");
            insert_fn(0, 2, "10");
            insert_fn(0, 3, "10");
            insert_fn(0, 4, "1");
            insert_fn(0, 5, "和利时PLC_2023版数据采集定时器");
        }

        ui_->tv->setModel(table_view_model_.get());
        ui_->tv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
}

}

}
