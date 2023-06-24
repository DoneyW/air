#pragma once

#include <QWidget>
#include "ui_DelCity.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DelCityClass; };
QT_END_NAMESPACE

class DelCity : public QWidget
{
	Q_OBJECT

public:
	DelCity(QWidget *parent = nullptr);
	~DelCity();

private:
	Ui::DelCityClass *ui;
};
