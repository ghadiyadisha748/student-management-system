#include <iostream>
#include "student.h"

using namespace std;

int main()
{
    Student s;
    int choice;

    while (true)
    {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Update Student\n";
        cout << "6. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            s.addStudent();
            break;

        case 2:
            s.displayStudents();
            break;

        case 3:
            s.searchStudent();
            break;

        case 4:
            s.deleteStudent();
            break;

        case 5:
            s.updateStudent();
            break;

        case 6:
            exit(0);

        default:
            cout << "Invalid Choice\n";
        }
    }

    return 0;
}