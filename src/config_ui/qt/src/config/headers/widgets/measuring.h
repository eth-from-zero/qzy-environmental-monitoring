#ifndef MEASURING_H
#define MEASURING_H

#include <memory>
#include "ui_measuring.h"

#include <QWidget>

//QT_BEGIN_NAMESPACE
//namespace Ui { class Welcome; }
//QT_END_NAMESPACE

class MesuringPage : public QWidget
{
    Q_OBJECT

public:
    MesuringPage(QWidget *parent= nullptr);
    ~MesuringPage() = default;

private:
    std::unique_ptr<Ui::Mesuring> ui_;
};


#endif // MEASURING_H
