#ifndef OTHER_OC_PROCESS_H
#define OTHER_OC_PROCESS_H

#include <QDialog>
#include <QStandardItemModel>

#include "ui_other_oc_process.h"

namespace other {

namespace operator_config {

class OtherOCProcess : public QDialog {
    Q_OBJECT

public:
    OtherOCProcess(QWidget *parent= nullptr);
    ~OtherOCProcess() = default;

private:
    std::unique_ptr<Ui::OtherOCProcess> ui_;
    std::unique_ptr<QStandardItemModel> table_view_model_;
};

}

}

#endif // OTHER_OC_PROCESS_H
