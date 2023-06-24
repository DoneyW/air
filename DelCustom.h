#pragma once

#include <QWidget>
#include "ui_DelCustom.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DelCustomClass; };
QT_END_NAMESPACE

class DelCustom : public QWidget
{
	Q_OBJECT

public:
	DelCustom(QWidget *parent = nullptr);
	~DelCustom();

private:
	Ui::DelCustomClass *ui;
};
