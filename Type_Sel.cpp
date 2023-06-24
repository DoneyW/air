#include "Type_Sel.h"
#include "Admin.h"
#include "LogIn.h"
Type_Sel::Type_Sel(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Type_SelClass())
{
	ui->setupUi(this);
}

Type_Sel::~Type_Sel()
{
	delete ui;
}

void Type_Sel::admin() {
	Admin* admin = new Admin();
	admin->setWindowFlag(Qt::Window);
	admin->show();
	this->close();
}

void Type_Sel::user() {
	LogIn* login = new LogIn();
	login->setWindowFlag(Qt::Window);
	login->show();
	this->close();
}
