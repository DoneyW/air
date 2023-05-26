#pragma once

#include <QWidget>
#include "ui_AddCity.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AddCityClass; };
QT_END_NAMESPACE

class AddCity : public QWidget
{
	Q_OBJECT

public:
	AddCity(QWidget *parent = nullptr);
	~AddCity();

private:
	Ui::AddCityClass *ui;
};
