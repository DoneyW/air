#include "FlightItem.h"
#include "qscrollbar.h"
FlightItem::FlightItem(Path path,QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::FlightItemClass()),path(path)
{
	ui->setupUi(this);
	ui->Tbw_Path->setColumnCount(path.city.size()*2-1);
	ui->Tbw_Path->setRowCount(1);
	ui->Tbw_Path->setRowHeight(0,40);
	ui->Tbw_Path->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->Tbw_Path->horizontalScrollBar()->setStyleSheet("QScrollBar{background:transparent; height:10px;}"
		"QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
		"QScrollBar::handle:hover{background:gray;}"
		"QScrollBar::sub-line{background:transparent;}"
		"QScrollBar::add-line{background:transparent;}");
	ui->Tbw_Path->verticalScrollBar()->setStyleSheet("QScrollBar{background:transparent; width: 10px;}"
		"QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
		"QScrollBar::handle:hover{background:gray;}"
		"QScrollBar::sub-line{background:transparent;}"
		"QScrollBar::add-line{background:transparent;}");
	ui->Tbw_Path->verticalHeader()->setVisible(false);
	ui->Tbw_Path->horizontalHeader()->setVisible(false);
	for (int i = 0; i < path.city.size() * 2 - 1; i++)
	{
		ui->Tbw_Path->setColumnWidth(i, 50);
		if (i % 2 == 0) {
			ui->Tbw_Path->setItem(0, i, new QTableWidgetItem(QString::fromStdString(path.city[i/2])));
		}
		else ui->Tbw_Path->setItem(0, i, new QTableWidgetItem(QString::fromLocal8Bit("¡ª¡ª>")));
	}
	ui->Lab_Length->setText(QString::number(path.total_length));
	ui->Lab_Price->setText(QString::number(path.total_prices));
	ui->Lab_Tickets->setText(QString::number(path.tickets));
}

FlightItem::~FlightItem()
{
	delete ui;
}
