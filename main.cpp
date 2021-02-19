#include <iostream>
using namespace std;

/*
 * Lab_2:
 *  1. Переменная длинного целого типа;
 *  2. Указатель на тип long int;
 *  3. Переменная целого типа.
 */

struct Student{
    // 1.(Использовать одну из переменных для хранения некоторого
    //  идентификатора (номера))
    long id;
    // символьный массив, используемый для хранения строки,
    // например, с именем студента
    char firstName[10];
    // указатель на тип char – для организации динамического
    // массива, хранящего строку, например, с фамилией студента.
    char *secondName;
    // 2.(указатель на не символьный тип – для
    //  организации динамического массива целых или плавающих чисел)
    long *pRatings;
    // 3.(другую переменную – для хранения размера этого массива)
    int count;
};

void testLogic();

Student initStudent(Student student);

// функция инициализации структуры
Student initStudent(int id) {
    Student student = {};
    student.id = id;
    return student;
}

// функция заполнения массива чисел (по ссылке)
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

// функция ввода информации в строки имени и фамилии
void inputFirstAndSecondName(Student &student) {
    cout << "How first name?:\n>>";
    cin >> student.firstName;
    cout << "How second name?:\n>>";
    student.secondName = new char[20];
    cin >> student.secondName;

}

// функция вывода на экран всех полей структуры, кроме массива чисел (по значению)
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

// функция освобождения динамической памяти (по ссылке)
void clear(Student &student) {
    delete [] student.secondName;
    delete [] student.pRatings;
}

int main() {
    Student *refObj;
    cout << "How many objects to create?\n>>";
    int countObject;
    cin >> countObject;
    refObj = new Student[countObject];
    for (int i = 0; i < countObject; i++) {
        refObj[i] = initStudent(i);
        fillArray(refObj[i]);
        inputFirstAndSecondName(refObj[i]);
        printInfo(&refObj[i]);
        clear(refObj[i]);
    }

    delete [] refObj;

//    {
//        Student student = {};
//        student = initStudent(123);
//        fillArray(student);
//        inputFirstAndSecondName(student);
//    }
//    printInfo(student);

    return 0;
}
