#include "Booked.h"
#include"File.h"
#include "MyWidget.h"
Booked::Booked(std::string IDNumber, QWidget *parent)
	: IDNumber(IDNumber),QWidget(parent)
	, ui(new Ui::BookedClass())
{
	ui->setupUi(this);
	ReNew();
}

Booked::~Booked()
{
	delete ui;
}

void Booked::MySlot(std::string st, std::string ed)
{
	emit MySignal(st, ed);
}

void Booked::ReNew() {
	if (widget)
	{
		delete widget;
		widget = NULL;
	}
	rcs = getRecord(IDNumber);
	widget = new MyWidget(rcs, this);
	widget->setGeometry(10, 10, 480, 600);
	widget->setVisible(true);
	connect(widget, &MyWidget::refund, this, &Booked::MySlot);
}