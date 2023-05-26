#include "Admin.h"
Admin::Admin(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::AdminClass())
{
	ui->setupUi(this);
	connect(ui->PsBt_City, &QPushButton::clicked, this, [=] {
		CloseWidget();
		city = new AddCity(this);
		city->setGeometry(100, 0, 700, 450);
		city->setVisible(true);
		});
	connect(ui->PsBt_Flight, &QPushButton::clicked, this, [=] {
		CloseWidget();
		flight = new AddFlight(this);
		flight->setGeometry(100, 0, 700, 450);
		flight->setVisible(true);
		});
}

Admin::~Admin()
{
	delete ui;
}

void Admin::CloseWidget()
{
	if (city) { delete city; city = NULL;}
	if (flight) { delete flight; flight = NULL; }
}
