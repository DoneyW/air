#include "AddFlight.h"
#include "Graph.h"
#include "File.h"
#include "qmessagebox.h"
AddFlight::AddFlight(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::AddFlightClass())
{
	ui->setupUi(this);
	connect(ui->PsBt_Add, &QPushButton::clicked, this, [=] {
		Flight f{ui->LiEd_Start->text().toStdString(),
		ui->LiEd_End->text().toStdString(),
		ui->LiEd_Length->text().toInt(),
		ui->LiEd_Price->text().toInt(),
		ui->LiEd_Ticket->text().toInt()
		};
		QString inf;
		if (addFlight(f))inf = "添加成功";
		else inf = "添加失败";
		QMessageBox message(QMessageBox::Information, "",
			inf, QMessageBox::Yes, NULL);
		message.exec();
		});
}

AddFlight::~AddFlight()
{
	delete ui;
}
