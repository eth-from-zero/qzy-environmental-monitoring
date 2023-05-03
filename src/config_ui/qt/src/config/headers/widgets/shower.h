#ifndef SHOWER_H
#define SHOWER_H

#include <memory>
#include "ui_shower.h"

#include <QWidget>

class Shower : public QWidget {
    Q_OBJECT

public:
    Shower(QWidget *parent= nullptr);
    ~Shower() = default;

private:
    std::unique_ptr<Ui::Shower> ui_;
};

#endif // SHOWER_H
