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

const char *getStudentToText(Student *student);

char *getArrayToText(Student *student);

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

void readDataText(Student &student, FILE *file) {
//    file = fopen ("text_data_file.dat","r");
//    if (file!=nullptr)
//    {
//        fgets((char*) &student, sizeof(student), file);
//        fclose (file);
//    }
}

void writeDataText(Student student[], FILE *file) {
    file = fopen("text_data_file.txt","w");
    const char *textFormat = "id:%d | fName:%s | sName:%s | array:%s | count:%d";
    char *arrayText;
    if (file!=nullptr)
    {
        int size = (int) sizeof((void*)student)/ sizeof(student[0]);

        for (int i = 0; i < size; i++) {
            arrayText = getArrayToText(&student[i]);
            fprintf(file, textFormat, student->id, student->firstName, student->secondName, arrayText, student->count);
        }

        fclose(file);
    }
}

char *getArrayToText(Student *student) {
    char text[student->count];
    for (int i = 0; i < student->count; i++) {
       text[i] = (char) (student->pRatings)[i];
    }
    return text;
}

//void readAllDataBinary(vector <Student> vStudent) {
//    Student student;
//    ifstream fin("binary_data_file.txt", ios::in);
//    while(!fin.eof())
//    {
//        fin.read((char*)&student, sizeof(Student));
//        vStudent.push_back(student);
//    }
//    fin.close();
//}
//
//void writeAllDataBinary(vector <Student> vStudent) {
//    ofstream fout("binary_data_file.txt", ostream::binary);
//    for(int i =0; i<= vStudent.size(); ++i)
//    {
//        fout.write((char*)&vStudent.at(i), sizeof(Student));
//    }
//    fout.close();
//}

int main() {
    FILE *textFile = nullptr;
    int baseCount = 1;
    Student *student[baseCount];
    // для ввода данных и их сохранения в файлах
    student[0] = new Student[baseCount];
    // для считывания данных из текстового файла
    student[1] = new Student[baseCount];
    // для считывания данных из двоичного файла
    student[2] = new Student[baseCount];

    for (int i = 0; i < baseCount; i++) {
        student[0][i] = initStudent(0 + i);
        fillArray(student[0][i]);
        inputFirstAndSecondName(student[0][i]);
    }

    writeDataText(student[0], textFile);
//        writeAllDataBinary(student[0][i]);

    for (int i = 0; i < baseCount; i++) {
        readDataText(student[1][i], textFile);
        printInfo(&student[1][i]);
    }


    // очистка памяти
    for (int i = 0; i < baseCount; i++) {
        for (int j = 0; j < baseCount; j++) {
            clear(student[i][j]);
        }
    }

    return 0;
}
