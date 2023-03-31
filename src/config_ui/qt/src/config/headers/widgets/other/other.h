#ifndef OTHER_H
#define OTHER_H

#include <memory>
#include "ui_other.h"

#include <QWidget>

class OtherPage : public QWidget
{
    Q_OBJECT

public:
    OtherPage(QWidget *parent= nullptr);
    ~OtherPage() = default;

private:
    std::unique_ptr<Ui::Other> ui_;
};


#endif // OTHER_H
