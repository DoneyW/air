#include "Booked.h"

Booked::Booked(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::BookedClass())
{
	ui->setupUi(this);
}

Booked::~Booked()
{
	delete ui;
}
