#pragma once

#include <QWidget>
#include "ui_Booked.h"
#include "Graph.h"
#include "MyWidget.h"
QT_BEGIN_NAMESPACE
namespace Ui { class BookedClass; };
QT_END_NAMESPACE

class Booked : public QWidget
{
	Q_OBJECT

public:
	Booked(std::string IDNumber,QWidget *parent = nullptr);
	~Booked();
public slots:
	void MySlot(std::string, std::string);
	void ReNew();
signals:
	void MySignal(std::string, std::string);
private:
	Ui::BookedClass *ui;
	std::vector<Purchase_Record> rcs;
	std::string IDNumber;
	MyWidget* widget=NULL;
};
