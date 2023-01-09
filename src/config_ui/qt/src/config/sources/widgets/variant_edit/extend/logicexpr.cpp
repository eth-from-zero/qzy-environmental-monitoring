#include <QStandardItemModel>

#include <QDebug>
#include <QMouseEvent>

#include "headers/widgets/variant_edit/extend/logicexpr.h"

Logicexpr::Logicexpr(QWidget*): QDialog(nullptr) {
    ui_ = std::make_unique<Ui::VEEDLogicexpr>();
    ui_->setupUi(this);

    select_var_ = std::make_unique<Selectvar>();

    {
        left_list_view_model_ = std::make_unique<QStandardItemModel>();

        right_list_view_model_ = std::make_unique<QStandardItemModel>();
        {
            auto item = new QStandardItem();
            item->setCheckable(true);
            item->setCheckState(Qt::Unchecked);
            item->setText("IF");
            right_list_view_model_->appendRow(item);
        }
        {
            auto item = new QStandardItem();
            item->setCheckable(true);
            item->setCheckState(Qt::Unchecked);
            item->setText("CASE");
            right_list_view_model_->appendRow(item);
        }
        ui_->lv_function->setModel(right_list_view_model_.get());
    }

    ui_->lv_function->viewport()->installEventFilter(this);

    connect(ui_->btn_ok, &QPushButton::clicked, this, [this]() {
        this->reject();
    });
    connect(ui_->btn_cancel, &QPushButton::clicked, this, [this]() {
        this->reject();
    });
}

bool Logicexpr::eventFilter(QObject *watched, QEvent *event) {
    if(watched ==  ui_->lv_function->viewport() && event->type() == QEvent::MouseButtonDblClick){
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        qDebug()<<"listview of function: MouseButtonDblClick"<<mouseEvent->pos();
        select_var_->exec();
    }
    return Logicexpr::eventFilter(watched, event);
}
