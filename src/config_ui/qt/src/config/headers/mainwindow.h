#ifndef MAIN_H
#define MAIN_H

#include <QMainWindow>

#include "headers/widgets/welcome.h"

#include <memory>

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
    void initUi(QWidget *parent);
    void initBind();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<WelcomePage> welcome_page_;
};

#endif // MAIN_H
