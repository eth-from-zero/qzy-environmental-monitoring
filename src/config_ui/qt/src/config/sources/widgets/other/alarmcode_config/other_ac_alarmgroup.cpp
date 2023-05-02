#include "headers/widgets/other/alarmcode_config/other_ac_alarmgroup.h"

namespace other {

namespace alarmcode_config {

Alarmgroup::Alarmgroup(QWidget* page): QDialog(nullptr) {
    ui_ = std::make_unique<Ui::OtherACAlarmgroup>();
    ui_->setupUi(page);

    {
        table_view_model_ = std::make_unique<QStandardItemModel>();
        table_view_model_->setHorizontalHeaderLabels({"报警组编号", "报警组名称"});

        auto insert_fn = [&](int x, int y, QString content) {
            auto item = new QStandardItem();
            item->setCheckable(false);
            item->setText(content);
            table_view_model_->setItem(x, y, item);
        };

        {
            insert_fn(0, 0, "FPI_Equip");
            insert_fn(0, 1, "(报警组)FPI水质归一化仪表");
        }

        ui_->tv->setModel(table_view_model_.get());
        ui_->tv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
}

}

}
