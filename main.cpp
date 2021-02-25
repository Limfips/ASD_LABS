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

Student *initStudent(int id) {
    auto *student = new Student();
    student->id = id;
    student->secondName = new char[0]();
    student->pRatings = new long[0]();
    student->count = 0;
    return student;
}

void fillArray(Student &student) {
    int sizeArray;
    cout << "How many elements of the array are create?:\n>>";
    cin >> sizeArray;
    student.pRatings = new long[sizeArray]();
    for (int i = 0; i < sizeArray; ++i) {
        cout << "[" << i << "]" << "=";
        cin >> student.pRatings[i];
    }
    student.count = sizeArray;
}

void inputFirstAndSecondName(Student &student) {
    cout << "What is your first name?:\n>>";
    cin >> student.firstName;
    cout << "What is your second name?:\n>>";
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

Student *readDataText(int size, FILE *file) {
    auto *students = new Student[size]();

    const char *errorText = "Error occured while opening file";
    const char *filename = "text_data_file.dat";
    const char *fTextFormat = "id:%d | fName:%s | sName:%s | count:%d | array:";
    const char *sTextFormat = "%d ";
    const char *tTextFormat = "\n";

    if ((file = fopen(filename, "r")) == nullptr)
    {
        perror(errorText);
    }

    for(int i=0; i<size; i++)
    {
        students[i] = *initStudent(0);
        fscanf(file, fTextFormat, &(students[i].id), &(students[i].firstName), (students[i].secondName), &(students[i].count));
        for (int j = 0; j < students[i].count; j++) {
            fscanf(file, sTextFormat, &(students[i].pRatings[j]));
        }
        fscanf(file, tTextFormat);
    }

    fclose(file);
    return students;
}

FILE *fileBinary;

void writeDataText(Student *array, int size, FILE *file) {
    const char *errorText = "Error occured while opening file";
    const char *filename = "text_data_file.dat";
    const char *fTextFormat = "id:%d | fName:%s | sName:%s | count:%d | array:";
    const char *sTextFormat = "%d ";
    const char *tTextFormat = "\n";

    if ((file = fopen(filename, "w")) == nullptr)
    {
        perror(errorText);
    }

    for(int i=0; i<size; i++)
    {
        fprintf(file, fTextFormat, (array + i)->id, (array + i)->firstName, (array + i)->secondName, (array + i)->count);
        for (int j = 0; j < (array + i)->count; j++) {
            fprintf(file, sTextFormat, ((array + i)->pRatings)[j]);
        }
        fprintf(file, tTextFormat);
    }
    fclose(file);
}

Student *readAllDataBinary(int size) {
    auto *students = new Student[size]();

    const char *errorText = "Error occured while opening file";
    const char *filename = "binary_data_file.dat";

    char *c;
    int j;
    int sizeB = sizeof(struct Student);

    if ((fileBinary = fopen(filename, "rb")) == nullptr)
    {
        perror(errorText);
    }

    Student *ptr;
    int k = 0;
    int i = 0;
    while ((j = getc(fileBinary))!=EOF)
    {
        if (k == sizeB) {
            k = 0;
            students[i++] = *ptr;
        }
        if (k == 0) {
            ptr = (struct Student *) malloc(sizeB);
            c = (char *) ptr;
        }

        *c = (char) j;
        c++;
        k++;
    }
    students[i++] = *ptr;

    fclose(fileBinary);
    free(ptr);
    return students;
}

void writeAllDataBinary(Student *array, int size) {
    const char *errorText = "Error occured while opening file";
    const char *filename = "binary_data_file.dat";

    char *c;
    int sizeB = sizeof(struct Student);

    if ((fileBinary = fopen(filename, "wb")) == nullptr)
    {
        perror(errorText);
    }

    for(int i=0; i<size; i++)
    {
        c = (char *) &(array[i]);
        for (int j = 0; j < sizeB; j++) {
            putc(*c++, fileBinary);
        }
    }
    fclose(fileBinary);
}

int main() {
    FILE *textFile = nullptr;
    int baseCount = 3;
    Student *student[baseCount];
    // для ввода данных и их сохранения в файлах
    student[0] = new Student[baseCount]();
    // для считывания данных из текстового файла
    student[1] = new Student[baseCount]();
    // для считывания данных из двоичного файла
    student[2] = new Student[baseCount]();

    for (int i = 0; i < baseCount; i++) {
        student[0][i] = *initStudent(0 + i);
        fillArray(student[0][i]);
        inputFirstAndSecondName(student[0][i]);
    }

    writeDataText(student[0], baseCount, textFile);
    writeAllDataBinary(student[0], baseCount);

    student[1] = readDataText(baseCount, textFile);
    student[2] = readAllDataBinary(baseCount);
    for (int i = 0; i < baseCount; i++) {
        cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
        printInfo(&(student[0][i]));
        printInfo(&(student[1][i]));
        printInfo(&(student[2][i]));
        cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
    }

    // очистка памяти
    for (int i = 0; i < baseCount; i++) {
        for (int j = 0; j < baseCount; j++) {
            clear(student[i][j]);
        }
    }

    return 0;
}
