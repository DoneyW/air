#pragma once

#include <QWidget>
#include "ui_Admin.h"
#include "AddCity.h"
#include "AddFlight.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AdminClass; };
QT_END_NAMESPACE

class Admin : public QWidget
{
	Q_OBJECT

public:
	Admin(QWidget *parent = nullptr);
	~Admin();

private:
	Ui::AdminClass *ui;
	void CloseWidget();
	AddCity* city=NULL;
	AddFlight* flight = NULL;
};
