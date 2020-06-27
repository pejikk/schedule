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
    QString login="", pass="",logincheck="",passcheck="",path="";
    path=ui->lineEdit->text();
    QFile file (path);
    if ((file.exists())&&(file.open(QIODevice::ReadOnly| QIODevice::Text)))
    {
        logincheck=file.readLine();
        passcheck=file.readLine();
        logincheck.chop(1);
        login = ui->login->text();
        pass = ui->pass->text();
        if ((login == logincheck) && (pass == passcheck))
        {
            QMessageBox::information(this, "Успешно", "Вы авторизовались как администратор");
            window = new MainWindow(this);
            window->show();
            window->resize(1348,574);
            this->hide();
        }
        else
        {
            QMessageBox::warning(this, "Ошибка", "Неверный логин и/или пароль");
        }
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Неверный путь к файлу");
    }

}

