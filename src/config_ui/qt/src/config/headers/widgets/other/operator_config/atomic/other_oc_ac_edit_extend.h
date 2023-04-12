#ifndef OTHER_OC_AC_EDIT_EXTEND_H
#define OTHER_OC_AC_EDIT_EXTEND_H

#include <QDialog>
#include <QStandardItemModel>

#include "ui_other_oc_ac_edit_extend.h"

namespace other {

namespace operator_config {

class OtherOCACEditExtend : public QDialog {
    Q_OBJECT

public:
    OtherOCACEditExtend(QWidget *parent= nullptr);
    ~OtherOCACEditExtend() = default;

private:
    std::unique_ptr<Ui::OtherOCACEditExtend> ui_;
};

}

}

#endif // OTHER_OC_AC_EDIT_EXTEND_H
