#ifndef ALARMCODE_CONFIG_H
#define ALARMCODE_CONFIG_H

#include <QDialog>

#include "ui_other_alarmcode_config.h"

#include "headers/widgets/other/alarmcode_config/other_ac_alarmcode.h"
#include "headers/widgets/other/alarmcode_config/other_ac_alarmgroup.h"
#include "headers/widgets/other/alarmcode_config/other_ac_alarmlevel.h"
#include "headers/widgets/other/alarmcode_config/other_ac_alarmsource.h"

namespace other {

namespace alarmcode_config {

class AlarmcodeConfig: public QDialog {
    Q_OBJECT

public:
    AlarmcodeConfig(QWidget *parent= nullptr);
    ~AlarmcodeConfig() = default;

private:
    std::unique_ptr<Ui::OtherAlarmcodeConfig> ui_;
    std::unique_ptr<Alarmcode> alarmcode_widget_;
    std::unique_ptr<Alarmgroup> alarmgroup_widget_;
    std::unique_ptr<Alarmlevel> alarmlevel_widget_;
    std::unique_ptr<Alarmsource> alarmsource_widget_;
};

}

}

#endif // ALARMCODE_CONFIG_H
