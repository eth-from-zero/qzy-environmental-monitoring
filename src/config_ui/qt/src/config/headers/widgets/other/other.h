#ifndef OTHER_H
#define OTHER_H

#include <memory>
#include "ui_other.h"

#include <QWidget>

#include "headers/widgets/other/operator_config/operator_config.h"
#include "headers/widgets/other/timer_config/other_timer_config.h"
#include "headers/widgets/other/alarmcode_config/alarmcode_config.h"

class OtherPage : public QWidget
{
    Q_OBJECT

public:
    OtherPage(QWidget *parent= nullptr);
    ~OtherPage() = default;

Q_SIGNALS:
    void signal_shower();

private:
    std::unique_ptr<Ui::Other> ui_;
    std::unique_ptr<other::operator_config::OperatorConfig> operator_config_;
    std::unique_ptr<other::timer_config::TimerConfig> timer_config_;
    std::unique_ptr<other::alarmcode_config::AlarmcodeConfig> alarmcode_config_;
};


#endif // OTHER_H
