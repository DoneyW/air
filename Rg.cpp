#include "Rg.h"
#include "Custom.h"
#include "File.h"
#include"qmessagebox.h"
//#include "User.h"
//#include "User_DataBase.h"
Rg::Rg(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::RgClass())
{
	ui->setupUi(this);
	connect(ui->PsBt_CreatAcc, &QPushButton::clicked, this, &Rg::CreatAcc);
}

Rg::~Rg()
{
	delete ui;
}

void Rg::CreatAcc()
{
	Custom custom{ ui->LiEd_Name->text().toStdString(),
		ui->LiEd_PsWd->text().toStdString(),
	ui->LiEd_Age->text().toInt() ,
	ui->LiEd_ID->text().toStdString(),
	ui->LiEd_Phone->text().toStdString() };
	QString inf;
	if (addCustom(custom)) {
		inf = "创建成功";
	}
	else inf = "创建失败";
	QMessageBox message(QMessageBox::Information, "",
		inf, QMessageBox::Yes, NULL);
	message.exec();
	this->close();
}