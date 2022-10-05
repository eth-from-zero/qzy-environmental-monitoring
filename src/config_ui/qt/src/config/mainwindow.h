#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
    class Welcome;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<Ui::Welcome> welcome_;
};
#endif // MAINWINDOW_H
