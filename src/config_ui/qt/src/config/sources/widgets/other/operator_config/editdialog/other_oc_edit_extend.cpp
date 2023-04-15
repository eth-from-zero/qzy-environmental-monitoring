#include "headers/widgets/other/operator_config/editdialog/other_oc_edit_extend.h"

namespace other {

namespace operator_config {

OtherOCACEditExtend::OtherOCACEditExtend(QWidget* page): QDialog(nullptr) {
    ui_ = std::make_unique<Ui::OtherOCACEditExtend>();
    ui_->setupUi(page);
}

}

}
