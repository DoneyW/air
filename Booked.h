#pragma once

#include <QWidget>
#include "ui_Booked.h"

QT_BEGIN_NAMESPACE
namespace Ui { class BookedClass; };
QT_END_NAMESPACE

class Booked : public QWidget
{
	Q_OBJECT

public:
	Booked(QWidget *parent = nullptr);
	~Booked();

private:
	Ui::BookedClass *ui;
};
