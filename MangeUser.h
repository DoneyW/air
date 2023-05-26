#pragma once

#include <QWidget>
#include "ui_MangeUser.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MangeUserClass; };
QT_END_NAMESPACE

class MangeUser : public QWidget
{
	Q_OBJECT

public:
	MangeUser(QWidget *parent = nullptr);
	~MangeUser();

private:
	Ui::MangeUserClass *ui;
};
