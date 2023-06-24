#include "MyWidget.h"
MyWidget::MyWidget(std::vector<Purchase_Record> rcs,QWidget *parent)
	: rcs(rcs),QTableWidget(parent)
{
	setRowCount(rcs.size());
	setColumnCount(5);
	for (int i = 0; i < 5; ++i) setColumnWidth(i,90);
	setEditTriggers(QAbstractItemView::NoEditTriggers);
	QStringList headList;
	headList << QStringLiteral("始发地") << QStringLiteral("目的地")<<QStringLiteral(
	"距离")<<QStringLiteral("票价")<< QStringLiteral("操作");
	setHorizontalHeaderLabels(headList);
	for (int i = 0; i < rcs.size(); ++i)
	{
		setRowHeight(i, 30);
		setItem(i, 0, new QTableWidgetItem(QString::fromStdString(rcs[i].flight.start)));
		setItem(i, 1, new QTableWidgetItem(QString::fromStdString(rcs[i].flight.end)));
		setItem(i, 2, new QTableWidgetItem(QString::number(rcs[i].flight.length)));
		setItem(i, 3, new QTableWidgetItem(QString::number(rcs[i].flight.price)));
		QPushButton* bt = new QPushButton("退票",this);
		bt->setProperty("item", i);
		setCellWidget(i, 4, bt);
		connect(bt, &QPushButton::clicked, this, &MyWidget::Click);
	}
}

MyWidget::~MyWidget()
{}


void MyWidget::Click() {
	QPushButton* bt = dynamic_cast<QPushButton*>(this->sender());
	if (bt != NULL)
	{
		int nRow = bt->property("item").toInt();
		emit refund(this->item(nRow,0)->text().toStdString(), this->item(nRow, 1)->text().toStdString());
	}
}
