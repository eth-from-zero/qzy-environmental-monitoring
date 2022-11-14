#ifndef MAIN_H
#define MAIN_H

#include <QMainWindow>
#include <QHBoxLayout>

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
    void switchToNextPage();

private:
    int index_ = 0;
    Ui::MainWindow *ui;
    std::unique_ptr<QHBoxLayout> page_layout_;
    std::vector<std::unique_ptr<QWidget>> pages_;
};

#endif // MAIN_H
