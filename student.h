#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student
{
public:
    int id;
    string name;
    int age;

    void addStudent();
    void displayStudents();
    void searchStudent();
    void deleteStudent();
    void updateStudent();
};

#endif