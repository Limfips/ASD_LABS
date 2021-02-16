#include <iostream>

using namespace std;

/**
 * Lab_1:
 *
 * 1. Одномерный массив длинных целых чисел;
 * 2. Указатель на тип long int;
 * 3. Статический одномерный массив символов;
 * 4. Указатель на массив символов;
 * 5. Трехмерный массив целых чисел;
 * 6. Указатель на двумерный массив целых чисел.
 */


int main() {

    int inc = 0;
    // mass size
    const int n = 5;


    // 1. Определить в функции main() переменные и массивы по таблице 1 в
    //  соответствии с вариантом (см. таблицу 1).
    long first[n];
    long *second;
    static char third[n];
    char (*fourth)[n];
    int fifth[n][n][n];
    int (*sixth)[n][n];

    // 2. В функции main() выполнить следующие действия:

    // 2.1. Проверить содержимое массива №1 (с помощью цикла for и
    //  операции вывода cout<<).
    cout << "2.1 - long first[" << n << "]:";
    for (long value: first) {
        cout << " " << value;
    }
    cout << "." << endl;

    // 2.2. Ввести данные в массив №1 (с помощью цикла for и операции ввода cin>>).
    cout << "2.2 - " << endl;
    inc = 5;
    for (long & i : first) {
        i = ++inc;
//        cin >> i;
    }

    // 2.3. Еще раз проверить содержимое этого массива, сделать выводы.
    cout << "2.3 - long first[" << n << "]:";
    for (long value: first) {
        cout << " " << value;
    }
    cout << "." << endl;


    // 2.4. Присвоить указателю №2 адрес массива №1, вывести на экран адреса массива
    //  и указателя и содержимое указателя. Сделать выводы.
    cout << "2.4 - " << endl;
    second = first;
    std::cout << "Address mass: " << &first << " - address p: " << &second << std::endl;
    std::cout << "value mass[0]: " << *first << " - value *p: " << *second << std::endl;


    // 2.5. Повторить пункт 3 для указателя, содержащего адрес массива. Сделать выводы.
    cout << "2.5 - long *second:";
    for (int i = 0; i < n; i++) {
        cout << " " << *(second+i);
    }
    cout << "." << endl;


    // 2.6. Повторить пункты 1 – 3 для статического массива №3. Сделать выводы.
    cout << "2.6 - static char[" << n << "]:";
    for (char value: third) {
        cout << " \'" << value << "\'";
    }
    cout << "." << endl;
    inc = 70;
    for (char & i : third) {
        i = (char) ++inc;
    }
    cout << "2.6 - static char[" << n << "]:";
    for (char value: third) {
        cout << " \'" << value << "\'";
    }
    cout << "." << endl;

    // 2.7. Используя имеющийся указатель №2, создать динамический массив и повторить
    //  для него пункты 1 – 3. Сделать выводы.
    second = new long int[n]();
    cout << "2.7 - new long int[" << n << "]():";
    for (int i = 0; i < n; i++) {
        cout << " " << *(second+i);
    }
    cout << "." << endl;
    inc = 10;
    for (int i = 0; i < n; i++) {
        second[i] = inc++;
    }
    cout << "2.7 - new long int[" << n << "]():";
    for (int i = 0; i < n; i++) {
        cout << " " << *(second+i);
    }
    cout << "." << endl;


    // 2.8. Удалить динамический массив. Используя указатель №4, создать двумерный
    //  динамический массив и повторить для него пункты 2, 3. Сделать выводы.
    //  Удалить двумерный динамический массив.
    delete [] second;
    fourth = new char[n][n]();
    inc = 60;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fourth[i][j] = (char) inc++;
        }
    }
    cout << "2.8 - new char[" << n << "][" << n << "]:";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << " " << fourth[i][j];
        }
        cout << " | ";
    }
    cout << "." << endl;
    delete [] fourth;

    inc = 20;
    for (auto & i : fifth) {
        for (auto & j : i) {
            for (int & k : j) {
                k = inc++;
            }
        }
    }
    // 2.9. Вывести на экран любой из элементов трехмерного массива №5, используя
    //  операцию индексации.
    cout << "2.9 - *(*(*(fifth + 1) + 1) + 1): " << *(*(*(fifth + 1) + 1) + 1) << endl;


    // 2.10. Повторить пункт 9, используя имя массива как указатель и операцию
    //  доступа по указателю.
    cout << "2.10 - fifth[1][1][1]: " << fifth[1][1][1] << endl;


    // 2.11. Присвоить указателю №6 на двумерный массив адрес трехмерного массива №5.
    //  Повторить для этого указателя пункт 10. Сделать выводы.
    sixth = fifth;
    cout << "2.11 - *(*(*(sixth + 1) + 1) + 1): " << *(*(*(sixth + 1) + 1) + 1) << endl;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                cout << fifth[i][j][k] << "\t";
            }
            cout << endl;
        }
        cout << endl << endl;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                cout << sixth[i][j][k] << "\t";
            }
            cout << endl;
        }
        cout << endl << endl;
    }

    return 0;
}
