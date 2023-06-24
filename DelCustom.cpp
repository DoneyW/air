#include "DelCustom.h"
#include "CustomWidget.h"
DelCustom::DelCustom(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::DelCustomClass())
{
	ui->setupUi(this);
	CustomWidget* cusw = new CustomWidget(this);
	cusw->setGeometry(10, 10, 730, 380);
	cusw->setVisible(true);
}

DelCustom::~DelCustom()
{
	delete ui;
}
