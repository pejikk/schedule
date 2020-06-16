#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;



template <class T>
class MyNode {
    private:
        T data;
//        int name,mon,tue,wed,thu,fri,sat,sun;
    public:
        MyNode* next;
        MyNode* previous;
        MyNode(T data);
        T getData();
        string toString();
        ~MyNode();
};

template <class T>
MyNode<T>::MyNode(T data) {
    this->data = data;
}


template <class T>
T MyNode<T>::getData() {
    return this->data;
}

template <class T>
string MyNode<T>::toString() {
    stringstream s;
    s << this->getData();
    return s.str();
}

template <class T>
MyNode<T>::~MyNode() { }

/* Linked List: */

template <class T>
class MyList {
    private:
        T* head;
        T* tail;
        int list_size;
    public:
        MyList();
        T* getHead();
        T* getTail();
        int size(bool update=false);
        void addNodeAsTail(T* new_node);
        void addNodeAsHead(T* new_node);
        void push(T* new_node);
        T* pop();
        T* get(int index);
        ~MyList();
};

template <class T>
MyList<T>::MyList() {
    this->head = NULL;
    this->tail = NULL;
    this->list_size = 0;
}

template <class T>
T* MyList<T>::getHead() {
    return this->head;
}

template <class T>
T* MyList<T>::getTail() {
    return this->tail;
}

template <class T>
int MyList<T>::size(bool update) {
    if (!update) {
        return this->list_size;
    }
    int size = 0;
    T* temp = this->head;
    while (temp) {
        size++;
        temp = temp->next;
    }
    this->list_size = size;
    return this->list_size;
}

template <class T>
void MyList<T>::addNodeAsTail(T* new_node) {
    new_node->next = NULL;
    new_node->previous = NULL;

    if (this->head == NULL) {
        this->head = new_node;
        this->tail = this->head;
        this->list_size = this->list_size + 1;
    } else {
        this->tail->next = new_node;
        new_node->previous = this->tail;
        this->tail = new_node;
        this->list_size = this->list_size + 1;
    }
}

template <class T>
void MyList<T>::addNodeAsHead(T* new_node) {
    new_node->next = NULL;
    new_node->previous = NULL;

    if (this->head == NULL) {
        this->head = new_node;
        this->tail = this->head;
        this->list_size = this->list_size + 1;
    } else {
        this->head->previous = new_node;
        new_node->next = this->head;
        this->head = new_node;
        this->list_size = this->list_size + 1;
    }
}

template <class T>
void MyList<T>::push(T* new_node) {
    this->addNodeAsHead(new_node);
}

template <class T>
T* MyList<T>::pop() {
    T* temp = this->head;
    this->head = this->head->next;
    this->head->previous = NULL;
    this->list_size = this->list_size - 1;
    return temp;
}


template <class T>
T* MyList<T>::get(int index) {
    if (index == 0) {
        return this->head;
    } else if (index == this->list_size - 1) {
        return this->tail;
    } else if (index < 0 || index >= this->list_size) {
        return NULL;
    }
    if (index < this->list_size / 2) {
        T* temp = this->head;
        int i = 0;
        while (temp) {
            if (i == index) { return temp; }
            i++;
            temp = temp->next;
        }
    } else {
        T* temp = this->tail;
        int i = this->list_size - 1;
        while (temp) {
            if (i == index) { return temp; }
            i--;
            temp = temp->previous;
        }
    }
    return NULL;
}



template <class T>
MyList<T>::~MyList() {
    while (this->head) {
        T* next = this->head->next;
        delete this->head;
        this->list_size = this->list_size - 1;
        this->head = next;
    }
}



#endif // DOUBLELIST_H
