#include <iostream>

using namespace std;

//Lab_4

struct Student{
    long id;
    char firstName[10];
    const char *secondName;
    long *pRatings;
    int count;
};

void printStudentInfo(Student *student) {
    cout << student->id << ": " << student->firstName << " " << student->secondName << " ";
}

struct Link {
    Link *prev;
    Link *next;
    Student *value;
};

void showList(Link *link) {
    Link *q = link->next;
    while (q->value != nullptr) {
        cout << "address: " << q << " | next: " << q->next  << " | value: (";
        printStudentInfo(q->value);
        cout << ")" << endl;
        q = q->next;
    }
    cout << endl;
}

Link* initLink(Student *firstValue) {
    Link *firstLink = new Link{nullptr, nullptr, firstValue};
    Link *header = new Link{firstLink, firstLink, nullptr};
    firstLink->prev = header;
    firstLink->next = header;
    return header;
};

Link* addItem(Link *list, Student *value) {
    Link *q = list->next;
    while (q->next->value != nullptr) { q = q->next; };
    Link *nextLink = new Link{q, q->next, value};
    q->next = nextLink;
    return list;
}

Link* deleteItem(Link *list, Student *value) {
    Link *q = list->next;
    while (q->value->id != value->id) { q = q->next; };
    q->prev->next = q->next;
    q->next->prev = q->prev;
    free(q);
    return list;
}

int main() {
    Student student1 = Student{1, "FN1", "SN1"};
    Link *linkedList = initLink(&student1);
    showList(linkedList);

    Student student2 = Student{2, "FN2", "SN2"};
    Student student3 = Student{3, "FN3", "SN3"};
    Student student4 = Student{4, "FN4", "SN4"};
    Student student5 = Student{5, "FN5", "SN5"};
    linkedList = addItem(linkedList, &student2);
    showList(linkedList);
    linkedList = addItem(linkedList, &student3);
    showList(linkedList);
    linkedList = addItem(linkedList, &student4);
    showList(linkedList);
    linkedList = addItem(linkedList, &student5);
    showList(linkedList);

    linkedList = deleteItem(linkedList, &student5);
    showList(linkedList);

    linkedList = deleteItem(linkedList, &student1);
    showList(linkedList);

    linkedList = addItem(linkedList, &student1);
    showList(linkedList);

    return 0;
}
