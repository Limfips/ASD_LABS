#include <iostream>
#include "SingleLinkList.h"


int main() {


    SingleLinkList linkedList = SingleLinkList();

    Student student1 = Student{1, "FN1", "SN1"};
    Student student2 = Student{2, "FN2", "SN2"};
    Student student3 = Student{3, "FN3", "SN3"};
    Student student4 = Student{4, "FN4", "SN4"};
    Student student5 = Student{5, "FN5", "SN5"};

    linkedList.addItem(&student1);
    linkedList.addItem(&student2);
    linkedList.addItem(&student3);
    linkedList.addItem(&student4);
    linkedList.addItem(&student5);

    char* list1 = new char[6] {'f', 'd', 'a', 'c', 'b', 'e'};



    return 0;
}
