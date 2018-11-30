#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <class T>
struct Node
{
    Node *next;
    T data;
};

template<class T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    const T& at(size_t index) const;

    const T& const_first() const;
    const T& const_last() const;

    bool isEmpty() const;

    void pop_back();
    void pop_front();

    void push_back(const T& _data);
    void push_front(const T& _data);
//    void push_back(T&& _data);

    size_t size() const;

private:
    size_t size_;
    Node<T>* head;
    Node<T>* tail;
};

//**************************************//

template<class T>
LinkedList<T>::LinkedList():
    size_{0},
    head{nullptr},
    tail{nullptr}
{ }

template<class T>
LinkedList<T>::~LinkedList()
{
    while (size_ != 0) {
        Node<T> *tmp = nullptr;
        tmp = head;
        head = tmp->next;
        --size_;
        delete tmp;
    }
}

template<class T>
const T& LinkedList<T>::at(size_t index) const
{
    Node<T>* tmp = head;
    for(size_t cnt = 0; cnt != index; ++cnt)
        tmp = tmp->next;
    return tmp->data;
}

template<class T>
const T& LinkedList<T>::const_first() const
{
    return head->data;
}

template<class T>
const T &LinkedList<T>::const_last() const
{
    return tail->data;
}

template<class T>
bool LinkedList<T>::isEmpty() const
{
    return (size_ == 0);
}

template<class T>
void LinkedList<T>::pop_back()
{
    if (size_ > 1) {
        Node<T>* tmp = head;
        for(size_t cnt = 0; cnt != size_-2; ++cnt)
            tmp = tmp->next;
        tail = tmp;
        delete tmp->next;
        tmp->next = nullptr;
        --size_;
    } else if (size_ == 1) {
        delete tail;
        head = nullptr;
        tail = nullptr;
        --size_;
    }
}

template<class T>
void LinkedList<T>::pop_front()
{
    if (size_ > 1) {
        Node<T>* tmp = head;
        head = head->next;
        delete tmp;
        --size_;
    } else if (size_ == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
        --size_;
    }
}

template<class T>
void LinkedList<T>::push_back(const T &_data)
{
    try {
        Node<T> *node = new Node<T>();
        node->next = nullptr;
        node->data = _data;
        if(size_++ != 0){
            tail->next = node;
            tail = node;
        }
        else{
            head = node;
            tail = node;
        }
    } catch (std::bad_alloc &ex) {
        std::cout<<"Vsyo propalo!!!-->push_back"<<std::endl;
    }
}

template<class T>
void LinkedList<T>::push_front(const T &_data)
{
    try {
        Node<T> *node = new Node<T>();
        node->data = _data;
        if(size_++ != 0){
            node->next = head;
            head = node;
        }
        else{
            node->next = nullptr;
            head = node;
            tail = node;
        }
    } catch (std::bad_alloc &ex) {
        std::cout<<"Vsyo propalo!!!-->push_back"<<std::endl;
    }
}

//template<class T>
//void LinkedList<T>::push_back(T&& _data)
//{
//    //TODO : empliment this method
//}

template<class T>
inline size_t LinkedList<T>::size() const
{
    return size_;
}

#include "Linkedlist.hpp"

#endif // LINKEDLIST_H
