#pragma once

#include <QWidget>
#include "ui_MWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MWindowClass; };
QT_END_NAMESPACE

class MWindow : public QWidget
{
	Q_OBJECT

public:
	MWindow(QWidget *parent = nullptr);
	~MWindow();

private:
	Ui::MWindowClass *ui;
};
