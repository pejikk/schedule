#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <QMainWindow>
#include <QWidget>

class DoubleList
{
public:
    QString name,mon,tue,wed,thu,fri,sat,sun;
    void addElement(int position, QString name, QString mon,QString tue,QString wed,QString thu,QString fri,QString sat,QString sun);
    void delElement(int position);
    void setElement(int position, QString name, QString mon,QString tue,QString wed,QString thu,QString fri,QString sat,QString sun);

    DoubleList()
    {
      DoubleList *head=NULL,*prev=NULL,*next=NULL;
    };
};

#endif // DOUBLELIST_H
