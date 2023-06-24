#pragma once

#include <QWidget>
#include "ui_DelFilght.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DelFilghtClass; };
QT_END_NAMESPACE

class DelFilght : public QWidget
{
	Q_OBJECT

public:
	DelFilght(QWidget *parent = nullptr);
	~DelFilght();

private:
	Ui::DelFilghtClass *ui;
};
