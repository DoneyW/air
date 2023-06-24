#pragma once

#include <QTableWidget>
#include "Custom.h"

class CustomWidget  : public QTableWidget
{
	Q_OBJECT

public:
	CustomWidget(QWidget *parent);
	~CustomWidget();
public slots:
	void delCustom();
private:
	std::vector<Custom> cus;
	void IniteWidget();
};

