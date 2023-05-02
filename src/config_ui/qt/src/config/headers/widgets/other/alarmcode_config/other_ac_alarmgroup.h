#ifndef OTHER_AC_ALARMGROUP_H
#define OTHER_AC_ALARMGROUP_H

#include <QDialog>
#include <QStandardItemModel>

#include "ui_other_ac_alarmgroup.h"

namespace other {

namespace alarmcode_config {

class Alarmgroup : public QDialog {
    Q_OBJECT

public:
    Alarmgroup(QWidget *parent= nullptr);
    ~Alarmgroup() = default;

private:
    std::unique_ptr<Ui::OtherACAlarmgroup> ui_;
    std::unique_ptr<QStandardItemModel> table_view_model_;
};

}

}

#endif // OTHER_AC_ALARMGROUP_H
