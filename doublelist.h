#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>
#include <string>
#include <sstream>
#include <QString>

using namespace std;

template <class T>
class MyNode
{
    private:
        T data;
    public:
        QString name,mon,tue,wed,thu,fri,sat,sun;
        QString writeName(QString name);
        string writeMon(string mon);
        string writeTue(string tue);
        string writeWed(string wed);
        string writeThu(string thu);
        string writeFri(string fri);
        string writeSat(string sat);
        string writeSun(string sun);
        MyNode* next;
        MyNode* previous;
        MyNode(T data);
        T getData();
        string toString();
        ~MyNode();
};

template <class T>
MyNode<T>::MyNode(T data)
{
    this->data = data;
}

template <class T>
QString MyNode<T>::writeName(QString name)
{
    this->name = name;
    return "0";
}

template <class T>
string MyNode<T>::writeMon(string mon)
{
    this->mon = mon;
    return "0";
}

template <class T>
string MyNode<T>::writeTue(string tue)
{
    this->tue = tue;
    return "0";
}

template <class T>
string MyNode<T>::writeWed(string wed)
{
    this->wed = wed;
    return "0";
}

template <class T>
string MyNode<T>::writeThu(string thu)
{
    this->thu = thu;
    return "0";
}

template <class T>
string MyNode<T>::writeFri(string fri)
{
    this->fri = fri;
    return "0";
}

template <class T>
string MyNode<T>::writeSat(string sat)
{
    this->sat = sat;
    return "0";
}

template <class T>
string MyNode<T>::writeSun(string sun)
{
    this->sun = sun;
    return "0";
}

template <class T>
T MyNode<T>::getData()
{
    return this->data;
}

template <class T>
string MyNode<T>::toString()
{
    stringstream s;
    s << this->getData();
    return s.str();
}

template <class T>
MyNode<T>::~MyNode()
{

}

/* Linked List: */

template <class T>
class MyList
{
    private:
        T* head;
        T* tail;
        int list_size;
    public:
        MyList();
        T* getHead();
        T* getTail();
        int size(bool update=false);
        QString getName(int pos);
        void wwriteName(QString name, int pos);
        void wwriteMon(string mon, int pos);
        void wwriteTue(string tue, int pos);
        void wwriteWed(string wed, int pos);
        void wwriteThu(string thu, int pos);
        void wwriteFri(string fri, int pos);
        void wwriteSat(string sat, int pos);
        void wwriteSun(string sun, int pos);
        void addNodeAsTail(T* new_node);
        void addNodeAsHead(T* new_node);
        void push(T* new_node);
        T* pop();
        T* get(int index);
        ~MyList();
};

template <class T>
MyList<T>::MyList()
{
    this->head = NULL;
    this->tail = NULL;
    this->list_size = 0;
}

template <class T>
T* MyList<T>::getHead()
{
    return this->head;
}

template <class T>
T* MyList<T>::getTail()
{
    return this->tail;
}

template <class T>
int MyList<T>::size(bool update)
{
    if (!update)
    {
        return this->list_size;
    }
    int size = 0;
    T* temp = this->head;
    while (temp)
    {
        size++;
        temp = temp->next;
    }
    this->list_size = size;
    return this->list_size;
}

template <class T>
void MyList<T>::addNodeAsTail(T* new_node)
{
    new_node->next = NULL;
    new_node->previous = NULL;

    if (this->head == NULL)
    {
        this->head = new_node;
        this->tail = this->head;
        this->list_size = this->list_size + 1;
    }
    else
    {
        this->tail->next = new_node;
        new_node->previous = this->tail;
        this->tail = new_node;
        this->list_size = this->list_size + 1;
    }
}

template <class T>
void MyList<T>::addNodeAsHead(T* new_node)
{
    new_node->next = NULL;
    new_node->previous = NULL;

    if (this->head == NULL)
    {
        this->head = new_node;
        this->tail = this->head;
        this->list_size = this->list_size + 1;
    }
    else
    {
        this->head->previous = new_node;
        new_node->next = this->head;
        this->head = new_node;
        this->list_size = this->list_size + 1;
    }
}

template <class T>
void MyList<T>::push(T* new_node)
{
    this->addNodeAsHead(new_node);
}

template <class T>
T* MyList<T>::pop()
{
    T* temp = this->head;
    this->head = this->head->next;
    this->head->previous = NULL;
    this->list_size = this->list_size - 1;
    return temp;
}

template <class T>
void MyList<T>::wwriteName(QString name, int pos)
{
    T* temp = this->head;
    for (int i=1; i<pos; i++)
        {
            temp = temp->next;
        }
    temp->writeName(name);
}

template <class T>
QString MyList<T>::getName(int pos)
{
    T* temp = this->head;
    for (int i=1; i<pos; i++)
        {
            temp = temp->next;
        }
    return temp->name;
}

template <class T>
void MyList<T>::wwriteMon(string mon, int pos)
{
    T* temp = this->head;
    for (int i=1; i<pos; i++)
    {
        temp = temp->next;
    }
    temp->writeMon(mon);
}

template <class T>
void MyList<T>::wwriteTue(string tue, int pos) {
    T* temp = this->head;
    for (int i=1; i<pos; i++)
        {
            temp = temp->next;
        }
    temp->writeTue(tue);
}

template <class T>
void MyList<T>::wwriteWed(string wed, int pos) {
    T* temp = this->head;
    for (int i=1; i<pos; i++)
        {
            temp = temp->next;
        }
    temp->writeWed(wed);
}

template <class T>
void MyList<T>::wwriteThu(string thu, int pos) {
    T* temp = this->head;
    for (int i=1; i<pos; i++)
        {
            temp = temp->next;
        }
    temp->writeThu(thu);
}

template <class T>
void MyList<T>::wwriteFri(string fri, int pos) {
    T* temp = this->head;
    for (int i=1; i<pos; i++)
        {
            temp = temp->next;
        }
    temp->writeFri(fri);
}

template <class T>
void MyList<T>::wwriteSat(string sat, int pos) {
    T* temp = this->head;
    for (int i=1; i<pos; i++)
        {
            temp = temp->next;
        }
    temp->writeSat(sat);
}

template <class T>
void MyList<T>::wwriteSun(string sun, int pos) {
    T* temp = this->head;
    for (int i=1; i<pos; i++)
        {
            temp = temp->next;
        }
    temp->writeSun(sun);
}

template <class T>
T* MyList<T>::get(int index)
{
    if (index == 0)
    {
        return this->head;
    }
    else
        if (index == this->list_size - 1)
        {
        return this->tail;
    }
        else
            if (index < 0 || index >= this->list_size)
            {
                return NULL;
            }
    if (index < this->list_size / 2)
    {
        T* temp = this->head;
        int i = 0;
        while (temp)
        {
            if (i == index)
            {
                return temp;
            }
            i++;
            temp = temp->next;
        }
    }
    else
    {
        T* temp = this->tail;
        int i = this->list_size - 1;
        while (temp)
        {
            if (i == index)
            {
                return temp;
            }
            i--;
            temp = temp->previous;
        }
    }
    return NULL;
}



template <class T>
MyList<T>::~MyList()
{
    while (this->head)
    {
        T* next = this->head->next;
        delete this->head;
        this->list_size = this->list_size - 1;
        this->head = next;
    }
}



#endif // DOUBLELIST_H
