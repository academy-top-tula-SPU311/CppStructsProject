#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct Date
{
    int day;
    int month;
    int year;
};

struct String
{
    char* str;
    int length;
};

struct Person
{
    char* name = new char[10];
    int age;
    Person* parent;
};

struct Student
{
    char* name = new char[10];
    int age;
    //Date birthDate;
    double label;
};

template <typename T>
void Swap(T& a, T& b);

void StudentPrint(Student student);
void GroupPrint(Student* students, int size);
Student StudentCreate(const char* name, int age, double label);

void StudentSortName(Student* students, int size);
void StudentSortAge(Student* students, int size);


int main()
{
    std::cout << sizeof(Student) << "\n";

    /*Student bob;
    strcpy(bob.name, "Bobby");
    bob.birthDate.day = 15;
    bob.birthDate.month = 9;
    bob.birthDate.year = 2001;
    bob.label = 10.8;*/

    /*Student bob = StudentCreate("Bob", 29, 10.9);
    StudentPrint(bob);

    Student* sam = new Student;
    *sam = StudentCreate("Sammy", 32, 9.8);
    StudentPrint(*sam);*/

    int groupSize{ 5 };
    Student* group = new Student[groupSize];
    group[0] = StudentCreate("Tom", 26, 10);
    group[1] = StudentCreate("Jim", 41, 10);
    group[2] = StudentCreate("Sam", 19, 10);
    group[3] = StudentCreate("Leo", 33, 10);
    group[4] = StudentCreate("Ben", 28, 10);

    GroupPrint(group, groupSize);
    std::cout << "\n";

    StudentSortName(group, groupSize);
    GroupPrint(group, groupSize);
    std::cout << "\n";

    StudentSortAge(group, groupSize);
    GroupPrint(group, groupSize);
    std::cout << "\n";
}

template <typename T>
void Swap(T& a, T& b)
{
    T temp{ a };
    a = b;
    b = temp;
}

void StudentPrint(Student student)
{
    std::cout << "Name: " << student.name;
    std::cout << ", Age: " << student.age;
    std::cout << ", Label: " << student.label << "\n";
}

void GroupPrint(Student* students, int size)
{
    for (int i{}; i < size; i++)
        StudentPrint(students[i]);
}

Student StudentCreate(const char* name, int age, double label)
{
    Student student;

    student.age = age;
    student.label = label;
    strcpy(student.name, name);

    return student;
}

void StudentSortName(Student* students, int size)
{
    for (int i{}; i < size - 1; i++)
    {
        for (int j{ size - 1 }; j > i; j--)
            if (strcmp(students[j].name, students[j - 1].name) < 0)
                Swap(students[j], students[j - 1]);
    }
}

void StudentSortAge(Student* students, int size)
{
    for (int i{}; i < size - 1; i++)
    {
        for (int j{ size - 1 }; j > i; j--)
            if (students[j].age < students[j - 1].age)
                Swap(students[j], students[j - 1]);
    }
}
