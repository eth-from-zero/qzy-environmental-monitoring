#ifndef MEASURING_H
#define MEASURING_H

#include <memory>
#include "ui_measuring.h"

#include <QWidget>
#include <QStandardItemModel>

//QT_BEGIN_NAMESPACE
//namespace Ui { class Welcome; }
//QT_END_NAMESPACE

class MeasuringPage : public QWidget
{
    Q_OBJECT

public:
    MeasuringPage(QWidget *parent= nullptr);
    ~MeasuringPage() = default;

private:
    std::unique_ptr<Ui::Measuring> ui_;
    std::unique_ptr<QStandardItemModel> list_view_model_;
};


#endif // MEASURING_H
