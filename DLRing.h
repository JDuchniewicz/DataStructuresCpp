//
// Created by jduchniewicz on 25/10/17.
//

#ifndef DLRING_DLRING_H
#define DLRING_DLRING_H
template <typename K, typename T>
class DLRing{
    struct element{
        K key;
        T data;
        element* prev;
        element* next;
    };
    element* head;

    void insertEnd(const K &key, const T &data);
    void insertBegin(const K &key, const T &data);
    bool removeAt(const K& key);
    void purge();
    int getSize();
    element* findElementAt(const K& key);

};

template <typename K, typename T>
void DLRing<K,T>::insertEnd(const K &key, const T &data) {
    if(!head){
        head = new element;
        head->key = key;
        head->data = data;
        head->next = head->prev = head;
        return;
    }

    element* last = head->prev;
    element* tmp = new element;
    tmp->key = key;
    tmp->data = data;
    tmp->next = last->next;
    last->next = tmp;
    tmp->prev = last;
}

template <typename K, typename T>
void DLRing<K,T>::insertBegin(const K &key, const T &data) {
    if(!head){
        head = new element;
        head->key = key;
        head->data = data;
        head->next = head->prev = head;
        return;
    }

    element* last = head->prev;
    element* tmp = new element;
    tmp->key = key;
    tmp->data = data;
    last->next = tmp;
    tmp->next = head;
    head->prev = tmp;
    head = tmp;
}

template <typename K, typename T>
bool DLRing<K,T>::removeAt(const K &key) {
    if(!head){ return false;} //nohead
    if(head->next == head && head->key == key){ //just head
        head->prev = nullptr;
        head->next = nullptr;
        delete head;
    }
    element* itr =  head;
    do{
        if(itr->key == key){
            itr->prev->next = itr->next;
            itr->next->prev = itr->prev;
            delete itr;
            return true;
        }
        itr = itr->next;
    }while(itr!=head);
    return false;
}

template <typename K, typename T>
void DLRing<K,T>::purge() {
    if(!head) {return;}
    element* itr = head;
    while(head){
        itr->next->prev = itr->prev;


    }

}

template <typename K, typename T>
int DLRing<K,T>::getSize(){
    if(!head) { return 0;}
    element* itr = head->next;
    int i = 1;
    while(itr!= head){
        ++i;
        itr = itr->next;
    }
    return i;
}

template <typename K, typename T>
DLRing::element *DLRing::findElementAt(const K &key) {
    element* itr = head;
    if(!head){ return  nullptr;}
    do{
        if(itr->key == key){
            return itr;
        }
        itr = itr->next;
    }while(itr != head);
    return nullptr;
}


#endif //DLRING_DLRING_H
