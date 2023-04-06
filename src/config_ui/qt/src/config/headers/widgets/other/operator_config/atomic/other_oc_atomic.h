#ifndef OOC_ATOMIC_H
#define OOC_ATOMIC_H

#include <QDialog>
#include <QStandardItemModel>

#include "ui_ooc_atomic.h"

namespace other {

namespace operator_config {

class OOCAtomic : public QDialog {
    Q_OBJECT

public:
    OOCAtomic(QWidget *parent= nullptr);
    ~OOCAtomic() = default;

private:
    std::unique_ptr<Ui::OOCAtomic> ui_;
    std::unique_ptr<QStandardItemModel> table_view_model_;
};

}

}

#endif // OOC_ATOMIC_H
