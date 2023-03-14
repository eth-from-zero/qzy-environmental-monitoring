#ifndef DEVICE_H
#define DEVICE_H

#include <memory>
#include "ui_device.h"

#include <QWidget>
#include <QMenu>
#include <QStandardItemModel>

#include "headers/widgets/device/params_config/dv_params_config.h"

class DevicePage : public QWidget
{
    Q_OBJECT

public:
    DevicePage(QWidget *parent= nullptr);
    ~DevicePage() = default;

private:
    std::unique_ptr<QMenu> list_view_menu_;
    std::unique_ptr<Ui::Device> ui_;
    std::unique_ptr<QStandardItemModel> list_view_model_;
    std::unique_ptr<device::ParamsConfig> params_config_;
};


#endif // DEVICE_H
