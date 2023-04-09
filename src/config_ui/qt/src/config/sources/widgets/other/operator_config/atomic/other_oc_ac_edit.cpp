#include "headers/widgets/other/operator_config/atomic/other_oc_ac_edit.h"

namespace other {

namespace operator_config {

OtherOCACEdit::OtherOCACEdit(QWidget *parent)
    : QDialog(parent) {
    ui_ = std::make_unique<Ui::OtherOCACEdit>();
    ui_->setupUi(this);

   atomic_widget_ = std::make_unique<OOCAtomic>(ui_->tab_atomic);
   process_widget_ = std::make_unique<OtherOCProcess>(ui_->tab_process);
}

}

}
