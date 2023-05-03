#ifndef OTHER_AC_ALARMSOURCE_H
#define OTHER_AC_ALARMSOURCE_H

#include <QDialog>
#include <QStandardItemModel>

#include "ui_other_ac_alarmsource.h"

namespace other {

namespace alarmcode_config {

class Alarmsource : public QDialog {
    Q_OBJECT

public:
    Alarmsource(QWidget *parent= nullptr);
    ~Alarmsource() = default;

private:
    std::unique_ptr<Ui::OtherACAlarmsource> ui_;
    std::unique_ptr<QStandardItemModel> table_view_model_;
};

}

}

#endif // OTHER_AC_ALARMSOURCE_H
