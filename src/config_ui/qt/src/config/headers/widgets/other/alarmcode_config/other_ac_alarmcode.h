#ifndef OTHER_AC_ALARMCODE_H
#define OTHER_AC_ALARMCODE_H

#include <QDialog>
#include <QStandardItemModel>

#include "ui_other_ac_alarmcode.h"

namespace other {

namespace alarmcode_config {

class Alarmcode : public QDialog {
    Q_OBJECT

public:
    Alarmcode(QWidget *parent= nullptr);
    ~Alarmcode() = default;

private:
    std::unique_ptr<Ui::OtherACAlarmcode> ui_;
    std::unique_ptr<QStandardItemModel> table_view_model_;
};

}

}

#endif // OTHER_AC_ALARMCODE_H
