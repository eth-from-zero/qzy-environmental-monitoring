#ifndef OTHER_OC_AC_EDIT_BASIC_H
#define OTHER_OC_AC_EDIT_BASIC_H

#include <QDialog>
#include <QStandardItemModel>

#include "ui_other_oc_edit_basic.h"

namespace other {

namespace operator_config {

class OtherOCACEditBasic : public QDialog {
    Q_OBJECT

public:
    OtherOCACEditBasic(QWidget *parent= nullptr);
    ~OtherOCACEditBasic() = default;

private:
    std::unique_ptr<Ui::OtherOCACEditBasic> ui_;
};

}

}


#endif // OTHER_OC_AC_EDIT_BASIC_H
