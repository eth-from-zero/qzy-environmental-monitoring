#include "headers/widgets/other/operator_config/editdialog/other_oc_edit_basic.h"

namespace other {

namespace operator_config {

OtherOCACEditBasic::OtherOCACEditBasic(QWidget* page): QDialog(nullptr) {
   ui_ = std::make_unique<Ui::OtherOCACEditBasic>();
   ui_->setupUi(page);

   connect(ui_->btn_timer, &QPushButton::clicked, this, [this]() {
   });
}

}

}
