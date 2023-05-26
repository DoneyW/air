#include "MangeUser.h"

MangeUser::MangeUser(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::MangeUserClass())
{
	ui->setupUi(this);
}

MangeUser::~MangeUser()
{
	delete ui;
}
