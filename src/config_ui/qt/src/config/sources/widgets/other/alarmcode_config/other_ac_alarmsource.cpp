#include "headers/widgets/other/alarmcode_config/other_ac_alarmsource.h"

namespace other {

namespace alarmcode_config {

Alarmsource::Alarmsource(QWidget* page): QDialog(nullptr) {
    ui_ = std::make_unique<Ui::OtherACAlarmsource>();
    ui_->setupUi(page);

    {
        table_view_model_ = std::make_unique<QStandardItemModel>();
        table_view_model_->setHorizontalHeaderLabels({"报警源编号", "报警源名称"});

        auto insert_fn = [&](int x, int y, QString content) {
            auto item = new QStandardItem();
            item->setCheckable(false);
            item->setText(content);
            table_view_model_->setItem(x, y, item);
        };

        {
            insert_fn(0, 0, "SYS_Alarm");
            insert_fn(0, 1, "系统及报警");
        }

        ui_->tv->setModel(table_view_model_.get());
        ui_->tv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
}

}

}
