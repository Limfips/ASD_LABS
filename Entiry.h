using namespace std;

#ifndef A_H_INCLUDED // если этот файл ещё не включён
#define A_H_INCLUDED // включить этот файл

struct Student{
    long id;
    char firstName[10];
    const char *secondName;
    long *pRatings;
    int count;
};

void printStudentInfo(Student* student){
    (student == nullptr ?
    cout << "NULL" :
    cout << "address: " << student << " | " << student->id
    ) << endl;
}

#endif

