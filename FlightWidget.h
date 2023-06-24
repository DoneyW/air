#pragma once

#include <QTableWidget>
#include "Graph.h"
class FlightWidget  : public QTableWidget
{
	Q_OBJECT

public:
	FlightWidget(QWidget *parent);
	~FlightWidget();
public slots:
	void delFlight();
private:
	void IniteWidget();
	std::vector<Flight> fls;
};
