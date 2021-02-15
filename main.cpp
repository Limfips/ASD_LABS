#include <iostream>


int main() {
    char array[4];
    char *pointer;
//2.2 Ввести данные в массив №1
    std::cout << "Ввод данных в массив №1" << std::endl;
    int arraySize = sizeof (array)/sizeof (array[0]);
    for (int i = 0; i < arraySize; ++i) {
        std::cout << "»";
        std::cin >> array[i];
    }
    std::cout << std::endl;

//2.3 Ещё раз проверить содержимое массива №1
    std::cout << "Вывод содержимого массива №1 после заполнения" << std::endl;
    for (char symbol:array){
        std::cout << symbol;
    }
    std::cout << std::endl;
    std::cout << "Присваиваем указателю адрес массива №1..." << std::endl;
    pointer = array;

    std::cout << "Адрес массива ->" << &array << std::endl;
    std::cout << "Адрес указателя ->" << &pointer<< std::endl;
    std::cout << "Содержимое указателя ->" << *pointer << std::endl;

    return 0;
}
