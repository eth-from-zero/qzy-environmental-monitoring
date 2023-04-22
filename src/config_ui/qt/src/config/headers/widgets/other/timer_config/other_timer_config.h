#ifndef OTHER_TIMER_CONFIG_H
#define OTHER_TIMER_CONFIG_H

#include <QDialog>
#include <QStandardItemModel>

#include "ui_other_timer_config.h"

namespace other {

namespace timer_config {

class TimerConfig: public QDialog {
    Q_OBJECT

public:
    TimerConfig(QWidget *parent= nullptr);
    ~TimerConfig() = default;

private:
    std::unique_ptr<Ui::OtherTimerConfig> ui_;
    std::unique_ptr<QStandardItemModel> table_view_model_;
};

}

}


#endif // OTHER_TIMER_CONFIG_H
