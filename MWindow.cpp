#include "MWindow.h"
#include "File.h"
#include "Graph.h"
#include "FlightItem.h"
MWindow::MWindow(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::MWindowClass())
{
	ui->setupUi(this);
	std::vector<string> citys = getCity();
	std::vector<Flight> flights = getFlight();
	Graph *graph=new Graph();
	for (int i = 0; i < citys.size(); ++i) 
	{
		ui->Cbb_Start->addItem(QString::fromStdString(citys[i]));
		ui->Cbb_End->addItem(QString::fromStdString(citys[i]));
		graph->addVex(citys[i]);
	}
	for (int i = 0; i < flights.size(); ++i)
	{
		graph->addArc(flights[i].start, flights[i].end, flights[i].length
			, flights[i].price, flights[i].tickets);
	}
	connect(ui->PsBt_Search, &QPushButton::clicked, this, [=] {
		Path path = graph->getPath(ui->Cbb_Start->currentText().toStdString(), ui->Cbb_End
			->currentText().toStdString());
		FlightItem *flight = new FlightItem(path,this);
		flight->setGeometry(40, 150, 442, 125);
		flight->setVisible(true);
		});
}

MWindow::~MWindow()
{
	delete ui;
}
