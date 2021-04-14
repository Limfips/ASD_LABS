#include <iostream>
#include "TreeList.h"
#include "Entiry.h"

using namespace std;

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

    return 0;
}
