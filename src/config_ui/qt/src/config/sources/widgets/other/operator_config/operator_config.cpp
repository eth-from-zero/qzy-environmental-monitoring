#include "headers/widgets/other/operator_config/operator_config.h"

namespace other {

namespace operator_config {

OperatorConfig::OperatorConfig(QWidget *parent)
    : QDialog(parent) {
    ui_ = std::make_unique<Ui::OtherOperatorConfig>();
    ui_->setupUi(this);

   atomic_widget_ = std::make_unique<OOCAtomic>(ui_->tab_atomic);
   process_widget_ = std::make_unique<OtherOCProcess>(ui_->tab_process);
}

}

}
