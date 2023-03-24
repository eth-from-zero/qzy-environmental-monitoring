#ifndef DV_PC_TIMER_H
#define DV_PC_TIMER_H

#include <QDialog>

#include "ui_dv_pc_timer.h"

namespace device {

class PCTimer : public QDialog
{
    Q_OBJECT

public:
    PCTimer(QWidget *parent= nullptr);
    ~PCTimer() = default;

private:
    std::unique_ptr<Ui::DVPCTImer> ui_;
};

}

#endif // DV_PC_TIMER_H
