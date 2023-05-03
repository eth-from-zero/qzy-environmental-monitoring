#include "headers/widgets/other/alarmcode_config/other_ac_alarmlevel.h"

namespace other {

namespace alarmcode_config {

Alarmlevel::Alarmlevel(QWidget* page): QDialog(nullptr) {
    ui_ = std::make_unique<Ui::OtherACAlarmlevel>();
    ui_->setupUi(page);

    {
        table_view_model_ = std::make_unique<QStandardItemModel>();
        table_view_model_->setHorizontalHeaderLabels({"报警等级编号", "报警等级命名", "报警等级值"});

        auto insert_fn = [&](int x, int y, QString content) {
            auto item = new QStandardItem();
            item->setCheckable(false);
            item->setText(content);
            table_view_model_->setItem(x, y, item);
        };

        {
            insert_fn(0, 0, "1");
            insert_fn(0, 1, "故障");
            insert_fn(0, 2, "1");

            insert_fn(1, 0, "2");
            insert_fn(1, 1, "报警");
            insert_fn(1, 2, "2");
        }

        ui_->tv->setModel(table_view_model_.get());
        ui_->tv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
}

}

}
