#pragma once

#include <QWidget>
#include "ui_Rg.h"

QT_BEGIN_NAMESPACE
namespace Ui { class RgClass; };
QT_END_NAMESPACE

class Rg : public QWidget
{
	Q_OBJECT

public:
	Rg(QWidget *parent = nullptr);
	~Rg();
public slots:
	void CreatAcc();
private:
	Ui::RgClass *ui;
};
