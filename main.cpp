#include <iostream>

using namespace std;

// Алгоритм сортировки: 1. Пузырьковая; 2. Шелла.
// Одномерный символьный массив.



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

const int ST = 5;
void Shell_sort(char* item, int n){
    int step[ST] = {120, 40, 12, 4, 1}; // Массив убывающих шагов
    int i, j, k, h;
    char buf;
    for ( k = 0; k < ST; ++k)
    {
        h = step[k];
        for (i = h; i < n; ++i)
        {
            buf = item[i];
            for (j = i - h; buf < item[j] && j >= 0;
                 j -= h)
                item[j + h] = item[j];
            item[j + h] = buf;
        }
    }
}


void printArray(char* list) {
    for (int i = 0; i < 6; ++i) {
        cout << list[i] << " ";
    }
    cout << endl;
}


int main() {
    char* list1 = new char[6] {'f', 'd', 'a', 'c', 'b', 'e'};
    printArray(list1);
    bubble(list1, 6);
    printArray(list1);

    cout << endl;

    char* list2 = new char[6] {'f', 'd', 'a', 'c', 'b', 'e'};
    printArray(list2);
    Shell_sort(list2, 6);
    printArray(list2);

    return 0;
}

