#ifndef MEASURING_H
#define MEASURING_H

#include <memory>
#include "ui_measuring.h"

#include "ui_variant_edit.h"

#include <QWidget>
#include <QMenu>
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
    std::unique_ptr<QMenu> list_view_menu_;
    std::unique_ptr<Ui::Measuring> ui_;
    std::unique_ptr<QStandardItemModel> list_view_model_;

    std::unique_ptr<Ui::VariantEditDialog> variant_edit_dialog_;
};


#endif // MEASURING_H
