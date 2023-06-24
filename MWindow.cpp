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
		Path path;
		if (ui->Rdb_Change->isChecked()) {
			path=graph->getPath(ui->Cbb_Start->currentText().toStdString(), ui->Cbb_End
			->currentText().toStdString());
		}
		else if (ui->Rdb_Time->isChecked()) {
			path = graph->getShortestPath(ui->Cbb_Start->currentText().toStdString(), ui->Cbb_End
				->currentText().toStdString());
		}
		else if (ui->Rdb_prices->isChecked()) {
			path = graph->getCheapestPath(ui->Cbb_Start->currentText().toStdString(), ui->Cbb_End
				->currentText().toStdString());
		}
		if (path.city.size() == 0) {
			QMessageBox message(QMessageBox::Information, " ", "找不到航班", QMessageBox
				::Yes, NULL);
			message.exec();
			return;
		}
		FlightItem *flight = new FlightItem(path,this);
		connect(flight, SIGNAL(reserve(Path)), this, SLOT(Reserve(Path)));
		flight->setGeometry(40, 150, 442, 125);
		flight->setVisible(true);
		});
	connect(ui->PsBt_Booked, &QPushButton::clicked, this, [=] {
		Booked* b = new Booked(IDNumber,this);
		connect(b, &Booked::MySignal, this, &MWindow::Refund);
		b->setWindowFlag(Qt::Window);
		b->setWindowModality(Qt::WindowModal);
		b->show();
		});
	ui->Rdb_Change->setChecked(true);
}

MWindow::~MWindow()
{
	delete ui;
}

void MWindow::Refund(std::string st, std::string ed) {
	ticket->refundTicket(st, ed,IDNumber);
	QMessageBox message(QMessageBox::Information, "", "退票成功！", QMessageBox::Yes, NULL);
	message.exec();
}
void MWindow::Reserve(Path path) {
	qDebug() << "get reserve signal";
	ticket->purchaseTicket(path);
	QMessageBox message(QMessageBox::Information, "", "购票成功！", QMessageBox::Yes, NULL);
	message.exec();
}