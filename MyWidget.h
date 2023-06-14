#pragma once

#include <QTableWidget>
#include "qpushbutton.h"
#include "Graph.h"
class MyWidget  : public QTableWidget
{
	Q_OBJECT

public:
	MyWidget(std::vector<Purchase_Record> rcs,QWidget *parent=NULL);
	~MyWidget();
public slots:
	void Click();
signals:
	void refund(std::string,std::string);


private:
	std::vector<Purchase_Record> rcs;
};
