#ifndef OTHER_OC_SYSMODE_H
#define OTHER_OC_SYSMODE_H

#include <QWidget>
#include <QStandardItemModel>

#include "ui_other_oc_sysmode.h"

namespace other {

namespace operator_config {

class OtherOCSysmode : public QWidget {
    Q_OBJECT

public:
    OtherOCSysmode(QWidget *parent= nullptr);
    ~OtherOCSysmode() = default;

private:
    std::unique_ptr<Ui::OtherOCSysmode> ui_;
};

}

}

#endif // OTHER_OC_SYSMODE_H
