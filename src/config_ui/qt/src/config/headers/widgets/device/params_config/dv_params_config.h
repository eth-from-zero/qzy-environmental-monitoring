#ifndef DV_PARAMS_CONFIG_H
#define DV_PARAMS_CONFIG_H

#include <QDialog>

namespace device {

class ParamsConfig : public QDialog
{
    Q_OBJECT

public:
    ParamsConfig(QWidget *parent= nullptr);
    ~ParamsConfig() = default;

private:
    std::unique_ptr<Ui::DVParamsConfig> ui_;
};

}

#endif // DV_PARAMS_CONFIG_H
