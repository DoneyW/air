#pragma once

#include <QTableWidget>

class CityWidget  : public QTableWidget
{
	Q_OBJECT

public:
	CityWidget(QWidget *parent);
	~CityWidget();
public slots:
	void delCity();
private:
	std::vector<std::string> citys;
	void IniteWidget();
};
