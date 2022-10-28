#include "headers/mainwindow.h"
#include "ui_main.h"

Main::Main(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initUi(parent);
}

void Main::initUi(QWidget *parent) {
    // set window
    {
        setWindowTitle("[清泚源科技] 系统配置向导");

        QImage image(":/common/images/resources/window_icon.png");
        auto pix_map = QPixmap::fromImage(image);
        pix_map = pix_map.scaled(10, 10, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        setWindowIcon(QIcon(pix_map));
    }
    // init image on left
    {
        QImage image(":/common/images/resources/config1.png");
        auto pix_map = QPixmap::fromImage(image);
        pix_map = pix_map.scaled(200, 600, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        ui->lb_image->setPixmap(pix_map);
    }
//    ui->tb_welcome->setAutoFillBackground(true);
    welcome_page_ = std::make_unique<WelcomePage>(ui->welcome_page);
}

Main::~Main()
{
    delete ui;
}

