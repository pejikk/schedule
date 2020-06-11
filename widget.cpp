#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QFile>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_pushButton_Authorization_clicked()
{

}
void Widget::on_pushButton_clicked()
{
    QString login="", pass="",logincheck="",passcheck="";
    QFile file ("C:/Users/User/Documents/schedule/cfg.txt");

    if ((file.exists())&&(file.open(QIODevice::ReadOnly| QIODevice::Text)))
    {
        logincheck=file.readLine();
        passcheck=file.readLine();
        logincheck.chop(1);
    }
    login = ui->login->text();
    pass = ui->pass->text();
    if ((login != logincheck) && (pass != passcheck))
    {
        QMessageBox::warning(this, "Ошибка", "Неверный логин и/или пароль");

    }
    else
    {
    QMessageBox::information(this, "Успешно", "Вы авторизовались как адмаинистратор");
    window = new MainWindow(this);
    window->show();
    window->resize(1348,574);
    this->hide();
    }
}

