#include "headers/mainwindow.h"
#include "ui_main.h"

#include "headers/widgets/welcome.h"
#include "headers/widgets/measurement/measurement.h"
#include "headers/widgets/switching/switching.h"
#include "headers/widgets/device/device.h"
#include "headers/widgets/serialport/serialport.h"
#include "headers/widgets/other/other.h"

#include <QDebug>

namespace {
    static constexpr auto kPageIndexOther = 5;
}

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
        setWindowTitle("[尼诺安自控] 系统配置向导");

        QImage image(":/common/images/resources/window_icon.png");
        auto pix_map = QPixmap::fromImage(image);
        pix_map = pix_map.scaled(10, 10, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        setWindowIcon(QIcon(pix_map));
    }
    // init image on left
    {
        QImage image(":/common/images/resources/config_main.jpeg");
        auto pix_map = QPixmap::fromImage(image);
        pix_map = pix_map.scaled(200, 600, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        ui->lb_image->setPixmap(pix_map);
    }

    pages_.resize(6);
    pages_[0].reset(new WelcomePage(parent));
    pages_[1].reset(new MeasuringPage(parent));
    pages_[2].reset(new SwitchingPage(parent));
    pages_[3].reset(new DevicePage(parent));
    pages_[4].reset(new SerialportPage(parent));
    pages_[kPageIndexOther].reset(new OtherPage(parent));

    for (auto& page : pages_) {
        page->setAttribute(Qt::WA_StyledBackground);
    }

    ui->page->addWidget(pages_[0].get());

    shower_ = std::make_unique<Shower>(parent);
}

void Main::initBind() {
    {
        auto btn_prev = ui->btn_prev;
        auto btn_next = ui->btn_next;

        connect(btn_prev, &QPushButton::clicked, this, [this]() {
            --index_;
            switchToPrevPage();
        });

        connect(btn_next, &QPushButton::clicked, this, [this]() {
            ++index_;
            switchToNextPage();
        });
    }

    {
        connect(reinterpret_cast<OtherPage*>(pages_[kPageIndexOther].get()), &OtherPage::signal_shower, this, [this]() {
            this->hide();
            shower_->show();
        });
    }
}

void Main::switchToPrevPage() {
    int last_index = index_ + 1;
    if (index_ == -1) {
        index_ = static_cast<int>(pages_.size()-1);
    }
    qDebug() << "to_prev: last_index = " << last_index << ", index_ = " << index_;
    auto last_page = pages_[last_index].get();
    auto page = pages_[index_].get();

    last_page->hide();
    page->show();

    ui->page->replaceWidget(last_page, page);
}

void Main::switchToNextPage() {
    int last_index = index_ - 1;
    if (index_ == static_cast<int>(pages_.size())) {
        index_ = 0;
    }
    qDebug() << "to_next: last_index = " << last_index << ", index_ = " << index_;
    auto last_page = pages_[last_index].get();
    auto page = pages_[index_].get();

    last_page->hide();
    page->show();

    ui->page->replaceWidget(last_page, page);
}

Main::~Main()
{
    delete ui;
}

