//
// Created by jduchniewicz
//

#ifndef SLLIST_SLLIST_H
#define SLLIST_SLLIST_H

#include <iostream>
#include <cassert>

//This class is a singly linked ordered structure implemented as a stack, the keys are unique and
//they are unordered, meaning that the structure is unsorted

template<typename K, typename T>
class SLList{
    struct Node{
        K key;
        T data;
        Node* next;
    };
public:
    SLList();
    SLList(const SLList& list);
    ~SLList();
    SLList& operator=(const SLList& list);
    SLList& operator+(const SLList& list);
    SLList& operator-(const SLList& list);
    bool operator==(const SLList& list);
    bool operator!=(const SLList& list);
    bool isEmpty()const;
    void printList()const;
    int getLength()const;
    T getFirstNodeData()const;
    T getLastNodeData()const;
    bool addNode(const K& key, const T& data);
    bool insertNode(const K& key,const T& data, const int& where);
    bool deleteNode(const K& key);

private:
    Node* head;
    int size;

    Node* findNode(const K& key);
    void print()const;
    void clearList();
    void copyList(const SLList& list);
    bool isEqualTo(const SLList& list);

};

template<typename K, typename T>
SLList<K,T>::SLList(): head(nullptr), size(0) { }

template<typename K, typename T>
SLList<K,T>::~SLList() {
    clearList();
}

template<typename K, typename T>
SLList<K,T>::SLList(const SLList &list) {
    this->head = nullptr;
    copyList(list);
}

template<typename K, typename T>
SLList<K,T>& SLList<K,T>::operator=(const SLList<K,T> &list) {
    if(this!=&list){
        copyList(list);
    }
    return *this;
}
/*
SLList &SLList::operator+(const SLList &list) {

    return <#initializer#>;
}

SLList &SLList::operator-(const SLList &list) {

    return <#initializer#>;
}
 */
template<typename K, typename T>
int SLList<K,T>::getLength()const {
    return size;
}

template<typename K, typename T>
void SLList<K,T>::print() const{
    if(!head){ return;}
    Node* curr = head;
    while(curr->next){
        std::cout<<"For key: "<<curr->key<<" data is: "<< curr->data<<std::endl;
        curr = curr->next;
    }
}

template<typename K, typename T>
void SLList<K,T>::printList()const {
    std::cout<<"Printing List Now: "<<std::endl;
    print();
    std::cout<<"Finished printing list"<<std::endl;
}

template<typename K, typename T>
bool SLList<K,T>::isEmpty()const {
    return head == nullptr;
}

template<typename K, typename T>
T SLList<K,T>::getFirstNodeData()const {
    assert(head != nullptr);
    return head->data;
}

template<typename K, typename T>
T SLList<K,T>::getLastNodeData() const{
    assert(head!= nullptr);
    Node* curr = head;
    while(curr->next){
        curr= curr->next;
    }
    return curr->data;
}

template<typename K, typename T>
typename SLList<K,T>::Node* SLList<K,T>::findNode(const K &key) {
    if(!head){ return nullptr ;}
    Node* curr = head;
    while(curr->next){
        if(curr->key == key){ return curr;}
        curr= curr->next;
    }
    return nullptr;
}

template<typename K, typename T>
bool SLList<K,T>::addNode(const K &key, const T& data) {
    if(!head){
        Node* tmp = new Node;
        tmp->key = key;
        tmp->data = data;
        tmp->next = nullptr;
        head = tmp;
        return true;
    }
    Node* curr = head;
    while(curr->next){
        if(curr->key == key){ return false;}
        curr= curr->next;
    }
    Node* tmp = new Node;
    tmp->key = key;
    tmp->data = data;
    curr->next = tmp;
    tmp->next = nullptr;
    ++size;
    return true;
}

template<typename K, typename T>
bool SLList<K,T>::insertNode(const K &key, const T &data, const int &where) {
    if(findNode(key) || where > size){ return false;}
    Node* curr = head;
    int c = 0;
    while(curr->next){
        if(c == where){
            Node* tmp = new Node;
            tmp->key = key;
            tmp->data = data;
            tmp->next = curr->next;
            curr->next = tmp;
            ++size;
            return true;
        }
        curr= curr->next;
        ++c;
    }
    return false;
}

template<typename K, typename T>
bool SLList<K,T>::deleteNode(const K &key) {
    if(!head){return false;}
    Node* curr = head;
    Node* prev = curr;
    if(!curr->next){
        if(curr->key == key){
            delete curr;
            head = nullptr;
            --size;
            return true;
        }
        return false;
    }
    while(curr){
        if(curr->key == key){
            Node* tmp = curr;
            if(curr == head){
                head = curr->next;
                --size;
                delete tmp;
                return true;
            }
            prev->next = curr->next;
            delete tmp;
            --size;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}

template<typename K, typename T>
bool SLList<K,T>::operator==(const SLList &list) {
    return isEqualTo(list);
}

template<typename K, typename T>
bool SLList<K,T>::operator!=(const SLList &list) {
    return !isEqualTo(list);
}

template<typename K, typename T>
void SLList<K,T>::clearList() {
    if(!head){ return;}
    Node* curr = head;
    while(curr->next){
        Node* tmp = curr;
        curr = curr->next;
        delete tmp;
        --size;
    }
}

template<typename K, typename T>
void SLList<K,T>::copyList(const SLList& list) {
    if(head){clearList();}
    if(!list.head){
        head = nullptr;
        size = 0;
    } else {
        Node* tmp;
        Node* curr = list.head->next;
        Node* prev = list.head;
        size = list.size;
        head = new Node;
        head->key = list.head->key;
        head->data = list.head->data;
        head->next = nullptr;
        ++size;
        while(curr){
            tmp = new Node;
            tmp->key = curr->key;
            tmp->data = curr->data;
            tmp->next = nullptr;
            prev->next = tmp;
            prev = curr;
            curr = curr->next;
            ++size;
        }
    }
}

template<typename K, typename T>
bool SLList<K,T>::isEqualTo(const SLList &list) {
    if(size != list.size){return false;}
    bool eq = true;
    Node* curr = head;
    Node* other = list.head;
    while(curr->next){
        if(curr->key == other->key){
            if(curr->data != other->data){
                return false;
            }
        } else {return false;}
        curr = curr->next;
        other = other->next;
    }
    return eq;
}

template<typename K, typename T>
SLList<K,T> &SLList<K,T>::operator+(const SLList<K,T> &list) {
    return <#initializer#>;
}

template<typename K, typename T>
SLList<K,T> &SLList<K,T>::operator+(const SLList<K,T> &list) {
    return <#initializer#>;
}


#endif //SLLIST_SLLIST_H
