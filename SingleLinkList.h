#include <iostream>

using namespace std;

struct Student{
    long id;
    char firstName[10];
    const char *secondName;
    long *pRatings;
    int count;
};

class SingleLinkList {

private: struct Link {
        Link *next;
        Student *value;
    };

private: Link* header;

public: SingleLinkList() {
    header = new Link{nullptr, nullptr};
}

private: static void printStudentInfo(Student *student) {
        cout << student->id << ": " << student->firstName << " " << student->secondName << " ";
    }

public: void showList() {
        Link *q = header->next;
        while (q) {
            cout << "address: " << q << " | next: " << q->next  << " | value: (";
            printStudentInfo(q->value);
            cout << ")" << endl;
            q = q->next;
        }
        cout << endl;
    }

public: Link* addItem(Student *value) {
        Link *q = header;
        while (q->next != nullptr) { q = q->next; };
        Link *nextLink = new Link{nullptr, value};
        q->next = nextLink;
        return header;
    }

public: Link* deleteItem(Student *value) {
        Link *q = header;
        while (q->next->value->id != value->id) { q = q->next; };
        Link *tmp = q->next;
        q->next = tmp->next;
        free(tmp);
        return header;
    }

public: Student* findById(int id) {
        Link *q = header;
        while (q->next != nullptr) {
            if (q->value != nullptr && q->value->id == id) {
                return q->value;
            } else {
                q = q->next;
            }
        };
        return nullptr;
}
};
