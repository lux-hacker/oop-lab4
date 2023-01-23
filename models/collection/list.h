#ifndef OOP_LAB4_LIST_H
#define OOP_LAB4_LIST_H
#include <stdexcept>

namespace collection {
    template<class T>
    struct ListNode {
        T data;
        ListNode<T> *next;
        ListNode<T> *prev;

        ListNode(T &data) : data(data), next(nullptr), prev(nullptr) {}
    };

    template<class T>
    class ListIterator;

    template<class T>
    class list {
        ListNode<T> *head;
        ListNode<T> *tail;
    public:
        friend class ListIterator<T>;
        typedef ListIterator<T> iterator;

        list(): head(nullptr), tail(nullptr){}

        void push_back(T& data){
            if(this->tail) {
                this->tail->next = new ListNode<T>(data);
                this->tail->next->prev = this->tail;
                this->tail = this->tail->next;
            } else {
                this->head = new ListNode<T>(data);
                this->tail = this->head;
            }
        }
        void push_front(T&data) {
            if(this->head) {
                auto *t = new ListNode<T>(data);
                t->next = this->head;
                this->head->prev = t;
                t->prev = nullptr;
                this->head = t;
            } else {
                this->head = new ListNode<T>(data);
                this->tail = this->head;
            }

        }
        void insert(const iterator pos, T& data){
            auto new_node = new ListNode<T>(data);
            ListNode<T> *node = nullptr;
            if(pos.ptr != nullptr) node = pos.ptr->prev;
            if(node != nullptr){
                new_node->next = node->next;
                new_node->prev = node;
                node->next = new_node;
            }
            if(pos.ptr != nullptr)
                new_node->next->prev = new_node;
            if(pos == this->begin())
                this->head = new_node;
        }

        iterator begin(){
            return list<T>::iterator(head);
        }
        iterator end(){
            return list<T>::iterator(nullptr);
        }
    };

    template<class T>
    class ListIterator {
        ListNode<T> *ptr;
    public:
        ListIterator() : ptr(nullptr) {};
        ListIterator(ListNode<T> *it) : ptr(it) {};

        int operator!=(const ListIterator<T> &other) const{
            return this->ptr != other.ptr;
        }
        int operator==(const ListIterator<T> &other) const{
            return this->ptr == other.ptr;
        }

        const T& operator*(){
            if (this->ptr) return ptr->data;
            throw std::invalid_argument("Exception#1: illegal value for List iterator");
        }

        ListIterator<T> &operator++(){
            this->ptr = this->ptr->next;
            return *this;
        }
        const ListIterator<T> operator++(int){
            ListIterator<T> res;
            res.ptr = this->ptr->next;
            return res;
        }

        ListIterator<T> &operator--(){
            this->ptr = this->ptr->prev;
            return *this;
        }
        const ListIterator<T> operator--(int){
            ListIterator<T> res;
            res.ptr = this->ptr->prev;
            return res;
        }

        friend class list<T>;
    };


}

#endif //OOP_LAB4_LIST_H
