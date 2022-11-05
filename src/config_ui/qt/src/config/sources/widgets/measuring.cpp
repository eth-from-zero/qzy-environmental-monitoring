#include "headers/widgets/measuring.h"

MeasuringPage::MeasuringPage(QWidget* parent)
    : QWidget(parent) {
    ui_ = std::make_unique<Ui::Measuring>();
    ui_->setupUi(parent);
}

