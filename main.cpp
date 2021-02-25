#include <cstdio>
#include <cstdlib>

struct person
{
    char name[16];
    int age;
};

int save(const char * filename, struct person *p);
int load(const char * filename);

int main()
{
    const char * filename = "person.dat";
    struct person tom = { "Tom", 21 };

    save(filename, &tom);
    load(filename);

    return 0;
}

// запись структуры в файл
int save(const char * filename, struct person *p)
{
    FILE * fp;
    char *c;
    int size = sizeof(struct person); // количество записываемых байтов

    if ((fp = fopen(filename, "wb")) == nullptr)
    {
        perror("Error occured while opening file");
        return 1;
    }
    // устанавливаем указатель на начало структуры
    c = (char *)p;
    // посимвольно записываем в файл структуру
    for (int i = 0; i < size; i++)
    {
        putc(*c++, fp);
    }
    fclose(fp);
    return 0;
}

// загрузка из файла структуры
int load(const char * filename)
{
    FILE * fp;
    char *c;
    int i; // для считывания одного символа
    // количество считываемых байтов
    int size = sizeof(struct person);
    // выделяем память для считываемой структуры
    auto * ptr = (struct person *) malloc(size);

    if ((fp = fopen(filename, "rb")) == nullptr)
    {
        perror("Error occured while opening file");
        return 1;
    }

    // устанавливаем указатель на начало блока выделенной памяти
    c = (char *)ptr;
    // считываем посимвольно из файла
    while ((i = getc(fp))!=EOF)
    {
        *c = i;
        c++;
    }

    fclose(fp);
    // вывод на консоль загруженной структуры
    printf("%s %d \n", ptr->name, ptr->age);
    free(ptr);
    return 0;
}