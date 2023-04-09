#ifndef OTHER_OC_AC_EDIT_H
#define OTHER_OC_AC_EDIT_H

#include <QDialog>

#include "ui_other_oc_ac_edit.h"

namespace other {

namespace operator_config {

class OtherOCACEdit: public QDialog {
    Q_OBJECT

public:
    OtherOCACEdit(QWidget *parent= nullptr);
    ~OtherOCACEdit() = default;

private:
    std::unique_ptr<Ui::OtherOCACEdit> ui_;
};

}

}

#endif // OTHER_OC_AC_EDIT_H
