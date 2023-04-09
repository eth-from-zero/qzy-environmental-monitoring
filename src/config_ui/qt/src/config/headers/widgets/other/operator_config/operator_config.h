#ifndef OPERATOR_CONFIG_H
#define OPERATOR_CONFIG_H

#include <QDialog>

#include "ui_other_operator_config.h"

#include "headers/widgets/other/operator_config/atomic/other_oc_atomic.h"
#include "headers/widgets/other/operator_config/process/other_oc_process.h"
#include "headers/widgets/other/operator_config/sysmode/other_oc_sysmode.h"

namespace other {

namespace operator_config {

class OperatorConfig: public QDialog {
    Q_OBJECT

public:
    OperatorConfig(QWidget *parent= nullptr);
    ~OperatorConfig() = default;

private:
    std::unique_ptr<Ui::OtherOperatorConfig> ui_;
    std::unique_ptr<OOCAtomic> atomic_widget_;
    std::unique_ptr<OtherOCProcess> process_widget_;
    std::unique_ptr<OtherOCSysmode> sysmode_widget_;
};

}

}

#endif // OPERATOR_CONFIG_H
