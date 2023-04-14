#include "headers/widgets/other/operator_config/operator_config.h"

namespace other {

namespace operator_config {

OperatorConfig::OperatorConfig(QWidget *parent)
    : QDialog(parent) {
    ui_ = std::make_unique<Ui::OtherOperatorConfig>();
    ui_->setupUi(this);

   atomic_widget_ = std::make_unique<OOCAtomic>(ui_->tab_atomic);
   process_widget_ = std::make_unique<OtherOCProcess>(ui_->tab_process);
   sysmode_widget_ = std::make_unique<OtherOCSysmode>(ui_->tab_sysmode);

   connect(ui_->btn_add, &QPushButton::clicked, this, [this]() {
       auto tw_index = ui_->tabWidget->currentIndex();
       if (tw_index == 1) {
       } else if (tw_index == 2) {
       } else {
       }
   });
}

}

}
