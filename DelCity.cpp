#include "DelCity.h"

DelCity::DelCity(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::DelCityClass())
{
	ui->setupUi(this);
}

DelCity::~DelCity()
{
	delete ui;
}
