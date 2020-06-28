#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "doublelist.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Пользователь"<<"Понедельник"<<"Вторник"<<"Среда"<<"Четверг"<<"Пятница"<<"Суббота"<<"Воскресенье"); //задание параметров таблиц
    ui->tableWidget_2->setColumnCount(1);
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

MyList<MyNode<int>> stack;
int i=1,j=0,a=0,b=0,flag=0;

void MainWindow::on_pushButton_3_clicked()
{
    stack.push(new MyNode<int>(i));
    ui->tableWidget->insertRow(a);
    ui->tableWidget_2->insertRow(a);
    i++;a++;
}

void MainWindow::on_pushButton_2_clicked()
{
    if((ui->tableWidget->rowCount())>0)
    {
         i--;
         a--;
         //stack.pop();
         ui->tableWidget->removeRow(a);
         ui->tableWidget_2->removeRow(a);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if (flag!=0)
    {
        while(a>0)
        {
           a--;
           ui->tableWidget->removeRow(a);
        }
    }
    QString buffer="",path="";
    path=ui->lineEdit->text();
    QFile file (path);
    QTextStream stream(&file);
    if ((file.exists())&&(file.open(QIODevice::ReadOnly| QIODevice::Text)))
    {
        buffer=stream.readLine(150); //пропуск первой строки в файле
        while (!stream.atEnd())
        {
            ui->tableWidget->insertRow(a);
            for (int i=0;i<8;i++)
                {
                    stream>>buffer;
                    QTableWidgetItem *pCell = ui->tableWidget->item(a, b);
                    pCell = new QTableWidgetItem;
                    ui->tableWidget->setItem(a, b, pCell);
                    pCell->setText(buffer);
                    b++;
                }
            b=0;
            a++;
         }
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Неверный путь к файлу");
    }
    file.close();
    flag=1;
}
