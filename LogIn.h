#pragma once

#include <QtWidgets/QWidget>
#include "ui_LogIn.h"
#include "Custom.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LogInClass; };
QT_END_NAMESPACE

class LogIn : public QWidget
{
    Q_OBJECT

public:
    LogIn(QWidget *parent = nullptr);
    ~LogIn();
public slots:
    void Log();
    void Rge();
private:
    Ui::LogInClass *ui;
    void paintEvent(QPaintEvent* event);
    Custom_Tree *ct;
};
