#include "headers/widgets/other/alarmcode_config/alarmcode_config.h"

namespace other {

namespace alarmcode_config {

AlarmcodeConfig::AlarmcodeConfig(QWidget *parent)
    : QDialog(parent) {
    ui_ = std::make_unique<Ui::OtherAlarmcodeConfig>();
    ui_->setupUi(this);

   alarmcode_widget_ = std::make_unique<Alarmcode>(ui_->tab_alarmcode);
   alarmgroup_widget_ = std::make_unique<Alarmgroup>(ui_->tab_alarmgroup);
   alarmlevel_widget_ = std::make_unique<Alarmlevel>(ui_->tab_alarmlevel);
   alarmsource_widget_ = std::make_unique<Alarmsource>(ui_->tab_alarmsource);

//   edit_dialog_ = std::make_unique<OtherOCACEdit>();

   connect(ui_->btn_add, &QPushButton::clicked, this, [this]() {
//       edit_dialog_->exec();
   });
}

}

}
