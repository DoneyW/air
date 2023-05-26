#include "LogIn.h"
#include "qdebug.h"
//#include "User.h"
//#include "User_DataBase.h"
//#include "WinClass.h"
#include "Rg.h"
#include"qstyleoption.h"
#include "qpainter.h"
LogIn::LogIn(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LogInClass())
{
    ui->setupUi(this);
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
    /*QString AccNum = ui->LiEd_AccNum->text();
    QString PassWord = ui->LiEd_PsWd->text();*/
    /*qDebug() << AccNum << " " << PassWord;*/
   /* User u(AccNum.toLatin1().data(),PassWord.toLatin1().data());
    User_DataBase db;
    if (db.CheckUser(u) == 3)
    {
        WinClass *mw=new WinClass(u);
        mw->setWindowFlag(Qt::Window);
        mw->setWindowModality(Qt::WindowModal);
        mw->show();
        this->close();
    }*/
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