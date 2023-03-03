#ifndef SWITCHINT_H
#define SWITCHING_H

#include <memory>
#include "ui_switching.h"

#include <QWidget>
#include <QMenu>
#include <QStandardItemModel>

#include "headers/widgets/variant_edit/variant_edit.h"

//QT_BEGIN_NAMESPACE
//namespace Ui { class Welcome; }
//QT_END_NAMESPACE

class SwitchingPage : public QWidget
{
    Q_OBJECT

public:
    SwitchingPage(QWidget *parent= nullptr);
    ~SwitchingPage() = default;

private:
    std::unique_ptr<QMenu> list_view_menu_;
    std::unique_ptr<Ui::Switching> ui_;
    std::unique_ptr<QStandardItemModel> list_view_model_;
    std::unique_ptr<VariantEdit> variant_edit_;
};


#endif // SWITCHING_H
