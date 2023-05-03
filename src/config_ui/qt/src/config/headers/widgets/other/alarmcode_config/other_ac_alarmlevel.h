#ifndef OTHER_AC_ALARMLEVEL_H
#define OTHER_AC_ALARMLEVEL_H

#include <QDialog>
#include <QStandardItemModel>

#include "ui_other_ac_alarmlevel.h"

namespace other {

namespace alarmcode_config {

class Alarmlevel : public QDialog {
    Q_OBJECT

public:
    Alarmlevel(QWidget *parent= nullptr);
    ~Alarmlevel() = default;

private:
    std::unique_ptr<Ui::OtherACAlarmlevel> ui_;
    std::unique_ptr<QStandardItemModel> table_view_model_;
};

}

}

#endif // OTHER_AC_ALARMLEVEL_H
