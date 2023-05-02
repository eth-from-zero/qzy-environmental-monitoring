#ifndef ALARMCODE_CONFIG_H
#define ALARMCODE_CONFIG_H

#include <QDialog>

#include "ui_other_alarmcode_config.h"

namespace other {

namespace alarmcode_config {

class AlarmcodeConfig: public QDialog {
    Q_OBJECT

public:
    AlarmcodeConfig(QWidget *parent= nullptr);
    ~AlarmcodeConfig() = default;

private:
    std::unique_ptr<Ui::OtherAlarmcodeConfig> ui_;
//    std::unique_ptr<OOCAtomic> atomic_widget_;
};

}

}

#endif // ALARMCODE_CONFIG_H
