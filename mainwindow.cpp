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
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Пользователь"<<"Понедельник"<<"Вторник"<<"Среда"<<"Четверг"<<"Пятница"<<"Суббота"<<"Воскресенье");
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
int i=1,j=0,a=0,b=0;
int kek=0;

void MainWindow::on_pushButton_3_clicked()
{
//MyList<MyNode<int>> stack;

//    QString name="Если меня видно, ты красава";
    stack.push(new MyNode<int>(i));
//    stack.wwriteName(name,i);
    ui->tableWidget->insertRow(a);
    ui->tableWidget_2->insertRow(a);
//    QTableWidgetItem *pCell = ui->tableWidget->item(a, b);
//    {
//         pCell = new QTableWidgetItem;
//         ui->tableWidget->setItem(a, b, pCell);
//    }
//         pCell->setText(stack.getName(i));
    i++;a++;
}







void MainWindow::on_pushButton_2_clicked()
{
if((ui->tableWidget->rowCount())>0)
{
if(i==1)
{
    stack.~MyList();
}
else{
    i--;
    a--;
    stack.pop();
ui->tableWidget->removeRow(a);
ui->tableWidget_2->removeRow(a);
}
}
}

void MainWindow::on_pushButton_4_clicked()
{
    QString buffer="",buffer2="",path="";
    path=ui->lineEdit->text();
    QTextStream stream(&buffer);
    QFile file (path);
    if ((file.exists())&&(file.open(QIODevice::ReadOnly| QIODevice::Text)))
    {
        buffer=file.readLine();
        while (!file.atEnd())
        {
            ui->tableWidget->insertRow(a);
            buffer=file.readLine();
            for (int i=0;i<8;i++)
                {
                    stream>>buffer2;
                    QTableWidgetItem *pCell = ui->tableWidget->item(a, b);
                    pCell = new QTableWidgetItem;
                    ui->tableWidget->setItem(a, b, pCell);
                    pCell->setText(buffer2);
                    b++;
                }
            stream.reset();
            buffer2="";
            b=0;
            a++;
         }
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Неверный путь к файлу");
    }
    file.close();
}
