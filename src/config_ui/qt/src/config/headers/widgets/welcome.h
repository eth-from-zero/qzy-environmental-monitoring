#ifndef WELCOME_H
#define WELCOME_H

#include <memory>

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Welcome; }
QT_END_NAMESPACE

class WelcomePage : public QWidget
{
    Q_OBJECT

public:
    WelcomePage(QWidget *parent= nullptr);
    ~WelcomePage() = default;

private:
    std::unique_ptr<Ui::Welcome> ui_;
};

#endif // WELCOME_H
