#include "headers/mainwindow.h"
#include "ui_main.h"

#include <QDebug>

Main::Main(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initData();
    initUi(parent);
    initBind();
}

void Main::initData() {
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

    pages_.emplace_back(new WelcomePage(parent));

    for (auto& page : pages_) {
        page->setAttribute(Qt::WA_StyledBackground);
    }

    ui->page->addWidget(pages_[0].get());
}

void Main::initBind() {
    {
        auto btn_next = ui->btn_next;
        connect(btn_next, &QPushButton::clicked, this, [this]() {
            ++index_;
        });
    }
}

void Main::switchToNextPage() {
    int last_index = index_ - 1;
    if (index_ == static_cast<int>(pages_.size())) {
        last_index = index_ - 1;
        index_ = 0;
    }
    auto page = pages_[index_].get();

//    ui->page->replaceWidget();
}

Main::~Main()
{
    delete ui;
}

