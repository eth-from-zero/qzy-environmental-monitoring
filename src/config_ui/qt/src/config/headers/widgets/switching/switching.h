#pragma once

#ifndef SWITCHINT_H
#define SWITCHING_H

#include <memory>
#include "ui_switching.h"

#include <QWidget>
#include <QMenu>
#include <QStandardItemModel>

#include "headers/widgets/switching/variant_edit/si_variant_edit.h"

class SwitchingPage : public QWidget
{
    Q_OBJECT

public:
    SwitchingPage(QWidget *parent= nullptr);
    ~SwitchingPage() = default;

private:
    std::unique_ptr<QMenu> list_view_menu_;
    std::unique_ptr<Ui::Switching> ui_;
    std::unique_ptr<QStandardItemModel> list_view_model_;
    std::unique_ptr<switching::VariantEdit> variant_edit_;
};


#endif // SWITCHING_H
