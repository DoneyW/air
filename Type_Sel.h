#pragma once

#include <QWidget>
#include "ui_Type_Sel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Type_SelClass; };
QT_END_NAMESPACE

class Type_Sel : public QWidget
{
	Q_OBJECT

public:
	Type_Sel(QWidget *parent = nullptr);
	~Type_Sel();
public slots:
	void user();
	void admin();
private:
	Ui::Type_SelClass *ui;
};
