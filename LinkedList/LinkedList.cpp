//#include "LinkedList.h"
//#include <list>

//template<class T>
//LinkedList<T>::LinkedList():
//    size_{0},
//    head{nullptr},
//    tail{nullptr}
//{

//}

//template<class T>
//LinkedList<T>::~LinkedList()
//{
//    if(size_ != 0){
//        //TODO : delete all elements
//    }
//}

//template<class T>
//void LinkedList<T>::push_back(const T &_data)
//{
//    try {
//        Node<T> *node = new Node<T>();
//        node->next = nullptr;
//        node->data = _data;
//        if(size_++ != 0){
//            tail->next = node;
//            tail = node;
//        }
//        else{
//            head = node;
//            tail = node;
//        }
//    } catch (std::bad_alloc &ex) {
//        std::cout<<"Vsyo propalo!!!"<<std::endl;
//    }
//}

//template<class T>
//size_t LinkedList<T>::size() const
//{
//    return size_;
//}
