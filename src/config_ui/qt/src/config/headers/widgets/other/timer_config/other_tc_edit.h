#ifndef OTHER_TC_EDIT_H
#define OTHER_TC_EDIT_H

#include <QDialog>

#include "ui_other_tc_edit.h"

namespace other {

namespace timer_config {

class Edit: public QDialog {
    Q_OBJECT

public:
    Edit(QWidget *parent= nullptr);
    ~Edit() = default;

private:
    std::unique_ptr<Ui::OtherTCEdit> ui_;
};

}

}

#endif // OTHER_TC_EDIT_H
