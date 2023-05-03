#include "headers/widgets/shower.h"

#include <QGraphicsItem>

Shower::Shower(QWidget* parent)
    : QWidget(parent) {
    ui_ = std::make_unique<Ui::Shower>();
    ui_->setupUi(this);

    QImage image(":/common/images/resources/config_main.jpeg");
    auto pix_map = QPixmap::fromImage(image);
//    pix_map = pix_map.scaled(200, 600, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui_->lb_image->setPixmap(pix_map);
}
