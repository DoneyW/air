#include "Booked.h"
#include"File.h"
#include "MyWidget.h"
Booked::Booked(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::BookedClass())
{
	ui->setupUi(this);
	rcs = getRecord(IDNumber);
	MyWidget* widget = new MyWidget(rcs, this);
	connect(widget, SIGNAL(widget->refund(std::string st,std::string ed)), this,  SLOT(MySlot(std::string,std::string)));
}

Booked::~Booked()
{
	delete ui;
}

void Booked::MySlot(std::string st, std::string ed)
{
	emit MySignal(st, ed);
}