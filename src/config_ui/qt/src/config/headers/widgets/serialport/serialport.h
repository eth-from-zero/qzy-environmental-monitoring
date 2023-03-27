#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <memory>
#include "ui_serialport.h"

#include <QWidget>
#include <QStandardItemModel>

class SerialportPage : public QWidget
{
    Q_OBJECT

public:
    SerialportPage(QWidget *parent= nullptr);
    ~SerialportPage() = default;

private:
    std::unique_ptr<Ui::Serialport> ui_;
    std::unique_ptr<QStandardItemModel> list_view_model_;
    std::unique_ptr<QStandardItemModel> table_view_model_;
};

#endif // SERIALPORT_H
