#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Пользователь"<<"Понедельник"<<"Вторник"<<"Среда"<<"Четверг"<<"Пятница"<<"Суббота"<<"Воскресенье");
    ui->tableWidget_2->setColumnCount(1);
    ui->tableWidget_2->setRowCount(10);
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList() << "Список пользователей");
    ui->tableWidget_3->setColumnCount(1);
    ui->tableWidget_3->setRowCount(7);
    ui->tableWidget_3->setHorizontalHeaderLabels(QStringList() << "Дни недели");
    ui->tableWidget_3->setVerticalHeaderLabels(QStringList() <<"Понедельник"<<"Вторник"<<"Среда"<<"Четверг"<<"Пятница"<<"Суббота"<<"Воскресенье");
}

MainWindow::~MainWindow()
{
    delete ui;
}
