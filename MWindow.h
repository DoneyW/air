#pragma once

#include <QWidget>
#include "ui_MWindow.h"
#include "TicketSystem.h"
#include "Graph.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MWindowClass; };
QT_END_NAMESPACE

class MWindow : public QWidget
{
	Q_OBJECT

public:
	MWindow(std::string IDNumber,QWidget *parent = nullptr);
	~MWindow();
public slots:
	void Refund(std::string, std::string);
	void reserve(Path);
private:
	Ui::MWindowClass *ui;
	std::string IDNumber;
	Graph* graph;
	TicketSystem* ticket;
	FlightItem* flight;
};
