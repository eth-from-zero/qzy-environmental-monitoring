#ifndef OTHER_H
#define OTHER_H

#include <memory>
#include "ui_other.h"

#include <QWidget>

#include "headers/widgets/other/operator_config/operator_config.h"

class OtherPage : public QWidget
{
    Q_OBJECT

public:
    OtherPage(QWidget *parent= nullptr);
    ~OtherPage() = default;

private:
    std::unique_ptr<Ui::Other> ui_;
    std::unique_ptr<other::operator_config::OperatorConfig> operator_config_;
};


#endif // OTHER_H