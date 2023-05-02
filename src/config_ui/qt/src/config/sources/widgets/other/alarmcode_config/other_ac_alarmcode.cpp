#include "headers/widgets/other/alarmcode_config/other_ac_alarmcode.h"

namespace other {

namespace alarmcode_config {

Alarmcode::Alarmcode(QWidget* page): QDialog(nullptr) {
    ui_ = std::make_unique<Ui::OtherACAlarmcode>();
    ui_->setupUi(page);

    {
        table_view_model_ = std::make_unique<QStandardItemModel>();
        table_view_model_->setHorizontalHeaderLabels({"报警码", "报警名称", "报警等级", "重复判定时间(s)", "报警描述"});

        auto insert_fn = [&](int x, int y, QString content) {
            auto item = new QStandardItem();
            item->setCheckable(false);
            item->setText(content);
            table_view_model_->setItem(x, y, item);
        };

        {
            insert_fn(0, 0, "10");
            insert_fn(0, 1, "通信异常");
            insert_fn(0, 2, "故障");
            insert_fn(0, 3, "3600");
            insert_fn(0, 4, "系统软件与设备通信异常");
        }

        ui_->tv->setModel(table_view_model_.get());
        ui_->tv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
}

}

}
