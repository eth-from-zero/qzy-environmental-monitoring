#include "headers/widgets/other/timer_config/other_tc_edit.h"

namespace other {

namespace timer_config {

Edit::Edit(QWidget* parent): QDialog(parent) {
    ui_ = std::make_unique<Ui::OtherTCEdit>();
    ui_->setupUi(this);
}

}

}
