#include <iostream>
#include <cstdio>
using namespace std;

//Lab_3
struct Student{
        long id;
        char firstName[10];
        char *secondName;
        long *pRatings;
        int count;
};

Student initStudent(int id) {
    Student student = {};
    student.id = id;
    return student;
}

void fillArray(Student &student) {
    int sizeArray;
    cout << "How many elements of the array?:\n>>";
    cin >> sizeArray;
    student.pRatings = new long[sizeArray]();
    for (int i = 0; i < sizeArray; ++i) {
        cout << "[" << i << "]" << "=";
        cin >> student.pRatings[i];
    }
    student.count = sizeArray;
}

void inputFirstAndSecondName(Student &student) {
    cout << "How first name?:\n>>";
    cin >> student.firstName;
    cout << "How second name?:\n>>";
    student.secondName = new char[20];
    cin >> student.secondName;

}

void printInfo(Student *student) {
    cout << "------------------------------------------" << endl;
    cout << "(" << (void*) student << ") - " << "address structure" << endl;
    cout << "(" << &(student->id) << ") - " << "id: "<< student->id << endl;
    cout << "(" << &(student->firstName) << ") - " << "firstName: " << student->firstName << endl;
    cout << "(" << &(student->secondName) << ") - " << "secondName: " << student->secondName << endl;

    cout  << "(" << &(student->pRatings) << ") - pRatings:";
    for (int i = 0; i < student->count; i++) {
        cout << " " << *(student->pRatings + i);
    }
    cout << endl;
    cout << "(" << &(student->count) << ") - " << "count: " << student->count << endl;
    cout << "------------------------------------------" << endl;
}

void clear(Student &student) {
    delete [] student.secondName;
    delete [] student.pRatings;
}

void readDataText(Student &student) {

}

void readDataBinary(Student &student, FILE *file) {

}

void writeDataText(Student &student) {

}

void writeDataBinary(Student &student, FILE *file) {

}

FILE *fileBinary;

int main() {
    FILE *fileText;
    Student *student;


    return 0;
}
