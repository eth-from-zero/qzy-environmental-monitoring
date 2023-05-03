#include "headers/widgets/shower.h"

#include <QGraphicsItem>

Shower::Shower(QWidget* parent)
    : QWidget(parent) {
    ui_ = std::make_unique<Ui::Shower>();
    ui_->setupUi(this);

    QImage image(":/common/images/resources/shower.jpeg");
    auto pix_map = QPixmap::fromImage(image);
    pix_map = pix_map.scaled(ui_->lb_image->width(), ui_->lb_image->height(), Qt::KeepAspectRatio);
//    pix_map = pix_map.scaled(1000, 800, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui_->lb_image->setPixmap(pix_map);
}
