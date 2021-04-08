#include <iostream>
#include "SingleLinkList.h"



// линейниый поиск в массиве, двоичный поиск в массиве (использовать сортировку), поиск в списке


int indexOf(char *chars, char key, int size);
int indexOf2(char *chars, char key, int size);

void bubble(char* item, int n);

void printStudentInfo(Student *pStudent);

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

    char* chars = new char[6] {'f', 'd', 'a', 'c', 'b', 'e'};

    char findItem1 = 'b';
    char findItem2 = 'g';
    char findItem3 = 'f';
    char findItem4 = 'n';
    // 1. линейниый поиск в массиве
    cout << "'"<< findItem1 <<"' index: " << indexOf(chars, findItem1, 6) << endl;
    cout << "'"<< findItem2 <<"' index: " << indexOf(chars, findItem2, 6) << endl;

    // 2. двоичный поиск в массиве (использовать сортировку)
    bubble(chars, 6);
    cout << "'"<< findItem3 <<"' index: " << indexOf2(chars, findItem3, 6) << endl;
    cout << "'"<< findItem4 <<"' index: " << indexOf2(chars, findItem4, 6) << endl;

    // 3. поиск в списке
    int findId = 3;
    cout << "item with id = " << findId << " : [";
    printStudentInfo(linkedList.findById(findId));
    cout << "]"<< endl;

    return 0;
}

void printStudentInfo(Student *student) {
    cout << student->id << ": " << student->firstName << " " << student->secondName << " ";
}

void bubble(char* item, int n) {
    int a, b;
    char buf;
    for (a = 1; a < n; ++a)
        for (b = n - 1; b >= a; --b)
            if (item[b - 1] > item[b])
            {
                buf = item[b - 1]; // Перестановка
                item [b - 1] = item[b];
                item[b] = buf;
            }
}

int indexOf(char *chars, char key, int size) {
    for (int i = 0; i < size; i++)
        if (key == chars[i])
            return i;
    return -1;
}

int indexOf2(char *chars, char key, int size)
{
    int low, high, mid;
    low = 0; high= size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key < chars[mid])
            high = mid - 1;
        else
        if (key > chars[mid])
            low = mid + 1;
        else return mid;
    }
    return -1;
}

