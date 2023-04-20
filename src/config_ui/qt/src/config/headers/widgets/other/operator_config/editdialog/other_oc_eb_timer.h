#ifndef OTHER_OC_EB_TIMER_H
#define OTHER_OC_EB_TIMER_H

#include <QDialog>
#include <QStandardItemModel>

#include "ui_other_oc_eb_timer.h"

namespace other {

namespace operator_config {

class OtherOCEBTimer : public QDialog {
    Q_OBJECT

public:
    OtherOCEBTimer(QWidget *parent= nullptr);
    ~OtherOCEBTimer() = default;

private:
    std::unique_ptr<Ui::OtherOCEBTimer> ui_;
    std::unique_ptr<QStandardItemModel> table_view_model_;
};

}

}

#endif // OTHER_OC_EB_TIMER_H
