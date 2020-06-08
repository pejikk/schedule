#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
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
    QString login = ui->login->text();
    QString pass = ui->pass->text();
    if ((login != "admin") && (pass != "admin"))
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

