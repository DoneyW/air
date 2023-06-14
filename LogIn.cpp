#include "LogIn.h"
#include "qdebug.h"
//#include "User.h"
//#include "User_DataBase.h"
//#include "WinClass.h"
#include "Rg.h"
#include"qstyleoption.h"
#include "qpainter.h"
#include "File.h"
#include <vector>
#include "Custom.h"
#include "qmessagebox.h"
#include "MWindow.h"
LogIn::LogIn(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LogInClass())
{
    ui->setupUi(this);
    std::vector<Custom> custums = getCustom();
    ct=new Custom_Tree(custums);
    connect(ui->PsBt_LogIn, &QPushButton::clicked, this, &LogIn::Log);
    connect(ui->PsBt_Rg, &QPushButton::clicked, this, &LogIn::Rge);
}

LogIn::~LogIn()
{
    delete ui;
}

void LogIn::Rge()
{
    Rg* rg = new Rg(this);
    rg->setWindowFlag(Qt::Window);
    rg->setWindowModality(Qt::WindowModal);
    rg->show();

}

void LogIn::Log() {
    std::string Number=ui->LiEd_AccNum->text().toStdString();
    std::string value = ct->get(Number);
    if (value.size() == 0) {
        QMessageBox message(QMessageBox::Information, "", "账号不存在", QMessageBox::Yes
            , NULL);
        message.exec();
    }
    else if (value == ui->LiEd_PsWd->text().toStdString())
    {
        MWindow *w=new MWindow(Number);
        w->setWindowFlag(Qt::Window);
        w->setWindowModality(Qt::WindowModal);
        w->show();
        this->close();
    }
    else {
        QMessageBox message(QMessageBox::Information, "", "密码错误", QMessageBox::Yes
            , NULL);
        message.exec();
    }
}
void LogIn::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
    QWidget::paintEvent(event);
}