#pragma once

#include <QWidget>
#include "ui_AddFlight.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AddFlightClass; };
QT_END_NAMESPACE

class AddFlight : public QWidget
{
	Q_OBJECT

public:
	AddFlight(QWidget *parent = nullptr);
	~AddFlight();

private:
	Ui::AddFlightClass *ui;
};
