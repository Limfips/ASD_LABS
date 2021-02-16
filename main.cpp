#include <iostream>


int main() {
    char array[4];
    char *pointer;
//2.2 Ввести данные в массив №1
    int arraySize = sizeof (array)/sizeof (array[0]);
    for (int i = 0; i < arraySize; ++i) {
        std::cout << ">>";
        std::cin >> array[i];
    }
    std::cout << std::endl;

//2.3 Ещё раз проверить содержимое массива №1
    for (char symbol:array){
        std::cout << symbol;
    }
    std::cout << std::endl;
    pointer = array;

    std::cout << "1 ->" << (void*) array << std::endl;
    std::cout << "2 ->" << (void*) pointer<< std::endl;
    std::cout << "3 ->" << *pointer << std::endl;

    return 0;
}
