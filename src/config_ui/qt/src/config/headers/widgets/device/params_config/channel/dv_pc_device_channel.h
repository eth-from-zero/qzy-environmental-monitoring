#ifndef DV_PC_DEVICE_CHANNEL_H
#define DV_PC_DEVICE_CHANNEL_H

#include <QDialog>

#include <QStandardItemModel>

#include "ui_dv_pc_device_channel.h"

namespace device {

class DVPCDeviceChannel : public QDialog {
    Q_OBJECT

public:
    DVPCDeviceChannel(QWidget *parent= nullptr);
    ~DVPCDeviceChannel() = default;

private:
    std::unique_ptr<Ui::DVPCDeviceChannel> ui_;
    std::unique_ptr<QStandardItemModel> table_view_model_;
};

}

#endif // DV_PC_DEVICE_CHANNEL_H
