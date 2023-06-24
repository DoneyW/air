#include "FlightWidget.h"
#include "File.h"
#include <QPushButton>
#include <QMessageBox>
FlightWidget::FlightWidget(QWidget *parent)
	: QTableWidget(parent)
{
	IniteWidget();
}

FlightWidget::~FlightWidget()
{}

void FlightWidget::IniteWidget()
{
	this->clear();
	fls = getFlight();
	setRowCount(fls.size());
	setColumnCount(6);
	for (int i = 0; i < 6; ++i) setColumnWidth(i, 90);
	setEditTriggers(QAbstractItemView::NoEditTriggers);
	QStringList headList;
	headList << QStringLiteral("账号") << QStringLiteral("姓名") << QStringLiteral(
		"年龄") << QStringLiteral("电话") << QStringLiteral("操作");
	setHorizontalHeaderLabels(headList);
	for (int i = 0; i < fls.size(); ++i)
	{
		setRowHeight(i, 30);
		setItem(i, 0, new QTableWidgetItem(QString::fromStdString(fls[i].start)));
		setItem(i, 1, new QTableWidgetItem(QString::fromStdString(fls[i].end)));
		setItem(i, 2, new QTableWidgetItem(QString::number(fls[i].length)));
		setItem(i, 3, new QTableWidgetItem(QString::number(fls[i].price)));
		setItem(i, 4, new QTableWidgetItem(QString::number(fls[i].tickets)));
		QPushButton* bt = new QPushButton("删除", this);
		bt->setProperty("item", i);
		setCellWidget(i, 5, bt);
		connect(bt, &QPushButton::clicked, this, &FlightWidget::delFlight);
	}
}

void FlightWidget::delFlight() {
	QPushButton* bt = dynamic_cast<QPushButton*> (this->sender());
	int nRow = bt->property("item").toInt();
	fls.erase(fls.begin() + nRow);
	writeFlight(fls);
	QMessageBox message(QMessageBox::Information, "", "删除成功!", QMessageBox::Yes, NULL);
	message.exec();
	IniteWidget();
}
