#include "headers/widgets/other/operator_config/atomic/other_oc_ac_edit_basic.h"

namespace other {

namespace operator_config {

OtherOCACEditBasic::OtherOCACEditBasic(QWidget* page): QDialog(nullptr) {
    ui_ = std::make_unique<Ui::OtherOCACEditBasic>();
    ui_->setupUi(page);
}

}

}
