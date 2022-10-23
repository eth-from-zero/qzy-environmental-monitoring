#ifndef MAIN_H
#define MAIN_H

#include <QMainWindow>

#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class welcome;

class Main : public QMainWindow
{
    Q_OBJECT

public:
    Main(QWidget *parent = nullptr);
    ~Main();

private:
    void initUi(QWidget *parent);

private:
    Ui::MainWindow *ui;
};

#endif // MAIN_H
