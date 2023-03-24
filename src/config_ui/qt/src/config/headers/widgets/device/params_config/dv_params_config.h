#ifndef DV_PARAMS_CONFIG_H
#define DV_PARAMS_CONFIG_H

#include <QDialog>

#include "ui_dv_params_config.h"

#include "headers/widgets/device/params_config/timer/dv_pc_timer.h"

namespace device {

class ParamsConfig : public QDialog
{
    Q_OBJECT

public:
    ParamsConfig(QWidget *parent= nullptr);
    ~ParamsConfig() = default;

private:
    std::unique_ptr<Ui::DVParamsConfig> ui_;
    std::unique_ptr<device::PCTimer> timer_dialog_;
};

}

#endif // DV_PARAMS_CONFIG_H
