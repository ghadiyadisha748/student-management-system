#include <iostream>
#include <fstream>
#include "student.h"

using namespace std;

void Student::addStudent()
{
    ofstream file("data.txt", ios::app);

    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Age: ";
    cin >> age;

    file << id << " " << name << " " << age << endl;

    file.close();

    cout << "Student Added Successfully\n";
}

void Student::displayStudents()
{
    ifstream file("data.txt");

    while (file >> id >> name >> age)
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "------------------\n";
    }

    file.close();
}

void Student::searchStudent()
{
    ifstream file("data.txt");

    int searchId;
    bool found = false;

    cout << "Enter ID to Search: ";
    cin >> searchId;

    while (file >> id >> name >> age)
    {
        if (id == searchId)
        {
            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;

            found = true;
        }
    }

    if (!found)
    {
        cout << "Student Not Found\n";
    }

    file.close();
}

void Student::deleteStudent()
{
    ifstream file("data.txt");
    ofstream temp("temp.txt");

    int deleteId;
    bool found = false;

    cout << "Enter ID to Delete: ";
    cin >> deleteId;

    while (file >> id >> name >> age)
    {
        if (id != deleteId)
        {
            temp << id << " " << name << " " << age << endl;
        }
        else
        {
            found = true;
        }
    }

    file.close();
    temp.close();

    remove("data.txt");
    rename("temp.txt", "data.txt");

    if (found)
        cout << "Student Deleted Successfully\n";
    else
        cout << "Student Not Found\n";
}

void Student::updateStudent()
{
    ifstream file("data.txt");
    ofstream temp("temp.txt");

    int updateId;
    bool found = false;

    cout << "Enter ID to Update: ";
    cin >> updateId;

    while (file >> id >> name >> age)
    {
        if (id == updateId)
        {
            cout << "Enter New Name: ";
            cin >> name;

            cout << "Enter New Age: ";
            cin >> age;

            found = true;
        }

        temp << id << " " << name << " " << age << endl;
    }

    file.close();
    temp.close();

    remove("data.txt");
    rename("temp.txt", "data.txt");

    if (found)
        cout << "Student Updated Successfully\n";
    else
        cout << "Student Not Found\n";
}