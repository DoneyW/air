#include "CustomWidget.h"
#include "File.h"
#include <QPushButton>
#include <QMessageBox>
CustomWidget::CustomWidget(QWidget *parent)
	: QTableWidget(parent)
{
	IniteWidget();
}

CustomWidget::~CustomWidget()
{

}

void CustomWidget::IniteWidget()
{
	this->clear();
	cus = getCustom();
	setRowCount(cus.size());
	setColumnCount(5);
	for (int i = 0; i < 5; ++i) setColumnWidth(i, 90);
	setEditTriggers(QAbstractItemView::NoEditTriggers);
	QStringList headList;
	headList << QStringLiteral("账号") << QStringLiteral("姓名") << QStringLiteral(
		"年龄") << QStringLiteral("电话") << QStringLiteral("操作");
	setHorizontalHeaderLabels(headList);
	for (int i = 0; i < cus.size(); ++i)
	{
		setRowHeight(i, 30);
		setItem(i, 0, new QTableWidgetItem(QString::fromStdString(cus[i].IDNumber)));
		setItem(i, 1, new QTableWidgetItem(QString::fromStdString(cus[i].name)));
		setItem(i, 2, new QTableWidgetItem(QString::number(cus[i].age)));
		setItem(i, 3, new QTableWidgetItem(QString::fromStdString(cus[i].phoneNumber)));
		QPushButton* bt = new QPushButton("删除", this);
		bt->setProperty("item", i);
		setCellWidget(i, 4, bt);
		connect(bt, &QPushButton::clicked, this,&CustomWidget::delCustom);
	}
}

void CustomWidget::delCustom() {
	QPushButton* bt = dynamic_cast<QPushButton*> (this->sender());
	int nRow = bt->property("item").toInt();
	cus.erase(cus.begin() + nRow);
	writeCustom(cus);
	QMessageBox message(QMessageBox::Information, "", "删除成功!", QMessageBox::Yes, NULL);
	message.exec();
	IniteWidget();
}
