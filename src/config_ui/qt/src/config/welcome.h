#ifndef WELCOME_H
#define WELCOME_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class welcome; }
QT_END_NAMESPACE

class welcome : public QMainWindow
{
    Q_OBJECT

public:
    welcome(QWidget *parent = nullptr);
    ~welcome();

private:
    Ui::welcome *ui;
};
#endif // WELCOME_H
