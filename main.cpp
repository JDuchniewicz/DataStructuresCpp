#include <iostream>
#include "SLList.h"

void testSinglyLinkedList(){
    auto list1 = new SLList<int,int>();
    SLList<int, int>* list2 = new SLList<int,int>();
    //PRINT BLANK LIST
    list1->printList();
    //ADD ELEMENTS
    for(int i = 0; i < 10; ++i){
        list1->addNode(i, i*4);
        list2->addNode(i*2, i*4);
    }
    //PRINT FRESH LIST
    list1->printList();

    //REMOVE FROM MIDDLE AND HEAD
    list1->deleteNode(0);
    list1->deleteNode(8);
    list1->insertNode(0,0,4);

    //COPY CTR
    auto list3(list1);
    //PRINT LIST
    list3->printList();

    //ASSIGNMENT OPERATOR
    list3 = list2;
    //PRINT LIST
    list3->printList();
    //TESTING GETTERS
    std::cout<<list1->isEmpty()<<std::endl;
    std::cout<<list1->getLength()<<std::endl;
    std::cout<< list1->getFirstNodeData()<<std::endl;
    std::cout<< list1->getLastNodeData()<<std::endl;
    //TESTING REMOVAL
    //EXISTING ELEMENT
    list2->deleteNode(2);
    list2->printList();
    //NONEXISTENT ELEMENT
    list2->deleteNode(3);
    list2->printList();

    //TESTING OPERATORS
    std::cout<<(*list1==*list2)<<std::endl;
    std::cout<<(*list1!=*list2)<<std::endl;

}



int main() {
    testSinglyLinkedList();
    return 0;
}