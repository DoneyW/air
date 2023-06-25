#include "DelCity.h"
#include "CityWidget.h"
DelCity::DelCity(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::DelCityClass())
{
	ui->setupUi(this);
	CityWidget* city = new CityWidget(this);
	city->setGeometry(10, 10, 730, 380);
	city->setVisible(true);
}

DelCity::~DelCity()
{
	delete ui;
}
