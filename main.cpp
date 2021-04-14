#include <iostream>
#include "TreeList.h"
#include "Entiry.h"
#include <ctime>

using namespace std;

TreeList createdBinaryTreeList() {
    TreeList list = TreeList();
    int* args = new int[13]{70, 60, 85, 87, 90, 45, 30, 88, 35, 20, 86, 82, 83};

    for (int i = 0; i < 13; i++) {
        list.add(args[i], new Student{args[i] * 10});
    }
    return list;
}

TreeList createDegenerateTreeList() {
    TreeList list = TreeList();
    int* args = new int[13]{70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190};

    for (int i = 0; i < 13; i++) {
        list.add(args[i], new Student{args[i] * 10});
    }
    return list;
}

TreeList createPerfectlyBalancedTreeList() {
    TreeList list = TreeList();
    int* args = new int[15]{8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15};

    for (int i = 0; i < 15; i++) {
        list.add(args[i], new Student{args[i] * 10});
    }
    return list;
}

void testBinaryTreeList() {
    cout << "testBinaryTreeList: " << endl;
    unsigned int start_time =  clock(); // начальное время

    TreeList list = createdBinaryTreeList();

    list.print1();
    cout << endl;
    list.print2();
    cout << endl;
    list.print3();
    cout << endl;

    list.remove(70);
    list.print2();
    cout << endl;
    list.remove(85);
    list.print2();
    cout << endl;

    printStudentInfo(list.searchByKey(30));
    printStudentInfo(list.searchByKey(88));

    unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time; // искомое время
    cout << "runtime: " << search_time << "ms" << endl;
    cout << endl;
}


void testDegenerateTreeList() {
    cout << "testDegenerateTreeList: " << endl;
    unsigned int start_time =  clock(); // начальное время

    TreeList list = createDegenerateTreeList();

    list.print1();
    cout << endl;
    list.print2();
    cout << endl;
    list.print3();
    cout << endl;

    unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time; // искомое время
    cout << "runtime: " << search_time << "ms" << endl;
    cout << endl;
}

void test1PerfectlyBalancedTreeList() {
    cout << "test1PerfectlyBalancedTreeList: " << endl;
    unsigned int start_time =  clock(); // начальное время

    TreeList list = createPerfectlyBalancedTreeList();

    list.print1();
    cout << endl;
    list.print2();
    cout << endl;
    list.print3();
    cout << endl;

    unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time; // искомое время
    cout << "runtime: " << search_time << "ms" << endl;
    cout << endl;
}

void test2PerfectlyBalancedTreeList() {
    cout << "test2PerfectlyBalancedTreeList: " << endl;
    unsigned int start_time =  clock(); // начальное время

    TreeList list = createPerfectlyBalancedTreeList();
    list.add(16, new Student{16 * 10});
    list.add(17, new Student{17 * 10});
    list.add(18, new Student{18 * 10});

    list.print1();
    cout << endl;
    list.print2();
    cout << endl;
    list.print3();
    cout << endl;

    unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time; // искомое время
    cout << "runtime: " << search_time << "ms" << endl;
    cout << endl;
}

int main() {
    testBinaryTreeList();
    testDegenerateTreeList();
    test1PerfectlyBalancedTreeList();
    test2PerfectlyBalancedTreeList();

    /*
     * Идеально сбалнсированное дерево
     *
     * 
     * 1. Для организации двоичного поиска дерева определить соответствующий структурный тип,
     * содержащий поля, использованные в работе №2. Для хранения ключа использовать любое не
     * символьное поле.
     *
     * 2. Разработать функции:
     * – вставки узла в дерево,
     * – удаления узла из дерева,
     * – прохождения (просмотра) дерева в восходящем, нисходящем, последовательном порядке,
     * – создания идеально сбалансированного дерева с заданным числом узлов,
     * – поиска в дереве.
     *
     * 3. Создать двоичное дерево поиска с помощью функции вставки узла.
     *
     * 4. Выполнить просмотр дерева в восходящем, нисходящем и
     * последовательном порядке с помощью соответствующих функций.
     *
     * 5. Удалить несколько узлов из дерева, проверяя состояние
     * дерева после каждого удаления с помощью просмотра в нисходящем порядке.
     *
     * 6. Создать вырожденное дерево путѐм ввода в него упорядоченных данных.
     * Выполнить просмотр этого дерева в восходящем, нисходящем и последовательном порядке.
     * Зафиксировать результаты.
     *
     * 7. Создать идеально сбалансированное дерево и выполнить
     * его просмотр в нисходящем и последовательном порядках.
     * Сравнить результаты просмотров с результатами пункта 6. Сделать выводы.
     *
     * 8. Дополнить идеально сбалансированное дерево несколькими узлами и проверить его состояние,
     * просматривая дерево в нисходящем порядке.
     *
     * 9. Выполнить поиск информации в дереве. Проверить варианты успешного и неуспешного поиска.
     */
    
    
    return 0;
}
