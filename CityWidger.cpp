#include "CityWidget.h"
#include "File.h"
#include "qpushbutton.h"
#include "qmessagebox.h"
CityWidget::CityWidget(QWidget *Widget)
	: QTableWidget(Widget)
{
	citys = getCity();
	IniteWidget();
}

CityWidget::~CityWidget()
{}

void CityWidget::IniteWidget()
{
	this->clear();
	setRowCount(citys.size());
	setColumnCount(2);
	for (int i = 0; i < 2; ++i) setColumnWidth(i, 90);
	setEditTriggers(QAbstractItemView::NoEditTriggers);
	QStringList headList;
	headList << QStringLiteral("城市") << QStringLiteral("操作");
	setHorizontalHeaderLabels(headList);
	for (int i = 0; i < citys.size(); ++i)
	{
		setRowHeight(i, 30);
		setItem(i, 0, new QTableWidgetItem(QString::fromStdString(citys[i])));
		QPushButton* bt = new QPushButton("删除", this);
		bt->setProperty("item", i);
		setCellWidget(i, 1, bt);
		connect(bt, &QPushButton::clicked, this, &CityWidget::delCity);
	}
}

void CityWidget::delCity() {
	QPushButton* bt = dynamic_cast<QPushButton*> (this->sender());
	int nRow = bt->property("item").toInt();
	citys.erase(citys.begin() + nRow);
	QMessageBox message(QMessageBox::Information, "", "删除成功!", QMessageBox::Yes, NULL);
	message.exec();
	IniteWidget();
}
