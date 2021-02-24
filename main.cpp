#include <iostream>


struct person
{
    char name[20];
    int age;
};

template <size_t N>
void writeDataText(FILE *fp, person (&array)[N]);
void readDataText(FILE *fp);
int main()
{
    FILE *fp = nullptr;

    person people[] = { "Tom", 23, "Alice", 27, "Bob", 31, "Kate", 29 };
    writeDataText(fp, people);
    readDataText(fp);
    return 0;
}


template <size_t N>
void writeDataText(FILE *fp, person (&array)[N]) {
    const char * filename = "users.dat";

    if ((fp = fopen(filename, "w")) == nullptr)
    {
        perror("Error occured while opening file");
    }

    for(int i=0; i<N; i++)
    {
        fprintf(fp, "%s     %d\n", array[i].name, array[i].age);
    }
    fclose(fp);
}

void readDataText(FILE *fp) {
    const char * filename = "users.dat";
    char name[20];
    int age;
    if ((fp = fopen(filename, "r")) == nullptr)
    {
        perror("Error occured while opening file");
    }

    while((fscanf(fp, "%s   %d\n", &name, &age))!=EOF)
    {
        printf("%s      %d\n", name, age);
    }
    fclose(fp);
}
