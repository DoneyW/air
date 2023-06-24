#pragma once

#include <QWidget>
#include "ui_MWindow.h"
#include "TicketSystem.h"
#include "Graph.h"
#include "FlightItem.h"
#include "MyWidget.h"
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
	void Reserve(Path);
signals:
private:
	Ui::MWindowClass *ui;
	std::string IDNumber;
	Graph* graph;
	TicketSystem* ticket;
};
