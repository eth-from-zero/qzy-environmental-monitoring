#include "headers/widgets/other/operator_config/editdialog/other_oc_edit.h"

namespace other {

namespace operator_config {

OtherOCACEdit::OtherOCACEdit(QWidget *parent)
    : QDialog(parent) {
    ui_ = std::make_unique<Ui::OtherOCACEdit>();
    ui_->setupUi(this);

   basic_widget_ = std::make_unique<OtherOCACEditBasic>(ui_->tab_basic);
   extend_widget_ = std::make_unique<OtherOCACEditExtend>(ui_->tab_extend);
}

}

}
