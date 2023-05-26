#pragma once

#include <QWidget>
#include "ui_FlightItem.h"
#include"Graph.h"
QT_BEGIN_NAMESPACE
namespace Ui { class FlightItemClass; };
QT_END_NAMESPACE

class FlightItem : public QWidget
{
	Q_OBJECT

public:
	FlightItem(Path path,QWidget *parent = nullptr);
	~FlightItem();

private:
	Ui::FlightItemClass *ui;
	Path path;
};
