#include <iostream>
#include "TreeList.h"

using namespace std;

void printStudentInfo(Student* student){
    if (student == nullptr) return;
    cout
            << "address: " << student
            << " | " <<  student->id
            << endl;
}

int main() {

    TreeList list = TreeList();
    int* args = new int[13]{70, 60, 85, 87, 90, 45, 30, 88, 35, 20, 86, 82, 83};

    for (int i = 0; i < 13; i++) {
        list.add(args[i], new Student{args[i] * 10});
    }

    list.print1();
    cout << endl;
    list.print2();
    cout << endl;
    list.print3();
    cout << endl;

    printStudentInfo(list.searchByKey(90));
    printStudentInfo(list.searchByKey(12313));

    cout << "test delete_1: ";
    list.remove(85);
    list.print2();
    cout << "test delete_2: ";
    list.remove(3093);

    return 0;
}
