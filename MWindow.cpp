#include "MWindow.h"
#include "File.h"
#include "Graph.h"
#include "FlightItem.h"
#include "qmessagebox.h"
#include "Booked.h"
MWindow::MWindow(std::string IDNumber, QWidget *parent)
	: IDNumber(IDNumber),QWidget(parent)
	, ui(new Ui::MWindowClass())
{
	ui->setupUi(this);
	std::vector<string> citys = getCity();
	std::vector<Flight> flights = getFlight();
	graph=new Graph();
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
	ticket = new TicketSystem(IDNumber,graph);//
	connect(ui->PsBt_Search, &QPushButton::clicked, this, [=] {
		Path path = graph->getPath(ui->Cbb_Start->currentText().toStdString(), ui->Cbb_End
			->currentText().toStdString());
		if (path.city.size() == 0) {
			QMessageBox message(QMessageBox::Information, " ", "找不到航班", QMessageBox
				::Yes, NULL);
			message.exec();
			return;
		}
		flight = new FlightItem(path,this);
		flight->setGeometry(40, 150, 442, 125);
		flight->setVisible(true);
		});
	connect(ui->PsBt_Booked, &QPushButton::clicked, this, [=] {
		Booked* b = new Booked(this);
		connect(b, SIGNAL(b->MySignal(std::string, std::string)), this, SLOT(Refund(std::string, std::string)));
		b->setWindowFlag(Qt::Window);
		b->setWindowModality(Qt::WindowModal);
		b->show();
		});
	connect(flight, SIGNAL(flight->reserve(Path)), this, SLOT(reserve(Path)));
}

MWindow::~MWindow()
{
	delete ui;
}

void MWindow::Refund(std::string st, std::string ed) {
	ticket->refundTicket(st, ed,IDNumber);
}
void MWindow::reserve(Path path) {
	ticket->purchaseTicket(path);
}