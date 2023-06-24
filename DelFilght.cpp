#include "DelFilght.h"
#include "FlightWidget.h"
DelFilght::DelFilght(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::DelFilghtClass())
{
	ui->setupUi(this);
	FlightWidget* flw = new FlightWidget(this);
	flw->setGeometry(10, 10, 730, 380);
	flw->setVisible(true);
}

DelFilght::~DelFilght()
{
	delete ui;
}
