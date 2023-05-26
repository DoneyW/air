#include "AddCity.h"
#include "File.h"
#include "qmessagebox.h"
AddCity::AddCity(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::AddCityClass())
{
	ui->setupUi(this);
	connect(ui->PsBt_Add, &QPushButton::clicked, this, [=] {
		QString inf;
		if (addCity(ui->LiEd_Cityname->text().toStdString()))inf = "添加成功";
		else inf = "添加失败";
		QMessageBox message(QMessageBox::Information, "",
			inf, QMessageBox::Yes, NULL);
		message.exec();
		});
}

AddCity::~AddCity()
{
	delete ui;
}
