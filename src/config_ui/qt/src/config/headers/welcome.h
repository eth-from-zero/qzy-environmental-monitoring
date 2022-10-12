#ifndef WELCOME_H
#define WELCOME_H

#include <QMainWindow>

#include "headers/base_widget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class welcome; }
QT_END_NAMESPACE

class welcome : public BaseWidget
{
    Q_OBJECT

public:
    welcome(QWidget *parent = nullptr);
    ~welcome();

private:
    Ui::welcome *ui;
};
#endif // WELCOME_H
