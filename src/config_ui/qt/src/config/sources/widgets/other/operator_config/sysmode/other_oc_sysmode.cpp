#include "headers/widgets/other/operator_config/sysmode/other_oc_sysmode.h"

namespace other {

namespace operator_config {

OtherOCSysmode::OtherOCSysmode(QWidget* page): QWidget(nullptr) {
    ui_ = std::make_unique<Ui::OtherOCSysmode>();
    ui_->setupUi(page);
}

}

}
