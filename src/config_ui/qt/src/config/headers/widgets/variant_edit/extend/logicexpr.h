#ifndef LOGICEXPR_H
#define LOGICEXPR_H

#include <QDialog>
#include <QStandardItemModel>

#include "ui_ve_ed_logicexpr.h"

class Logicexpr : public QDialog {
public:
    Logicexpr(QWidget* parent = nullptr);
    ~Logicexpr() = default;

private:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    std::unique_ptr<Ui::VEEDLogicexpr> ui_;
    std::unique_ptr<QStandardItemModel> left_list_view_model_;
    std::unique_ptr<QStandardItemModel> right_list_view_model_;
};

#endif // LOGICEXPR_H
