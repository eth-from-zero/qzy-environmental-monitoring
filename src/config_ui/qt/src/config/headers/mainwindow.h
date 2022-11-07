#ifndef MAIN_H
#define MAIN_H

#include <QMainWindow>
#include <QHBoxLayout>

#include "headers/widgets/welcome.h"

#include <memory>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Main : public QMainWindow
{
    Q_OBJECT

public:
    Main(QWidget *parent = nullptr);
    ~Main();

private:
    void initData();
    void initUi(QWidget *parent);
    void initBind();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<WelcomePage> welcome_page_;
    int index_ = 0;
    std::unique_ptr<QHBoxLayout> page_layout_;
//    std::vector<std::unique_ptr<QWidget>> pages_;
    std::vector<QWidget*> pages_;
};

#endif // MAIN_H
