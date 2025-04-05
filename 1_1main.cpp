#include <iostream>
using namespace std;

struct Student {
    string name;
    int age;
    float gpa;
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student* students = new Student[n];

    for (int i = 0; i < n; i++) {
        cin.ignore();
        cout << "Enter name: ";
        getline(cin, students[i].name);
        cout << "Enter age: ";
        cin >> students[i].age;
        cout << "Enter GPA: ";
        cin >> students[i].gpa;
    }

    for (int i = 0; i < n; i++) {
        cout << "Name: " << students[i].name << ", Age: " << students[i].age << ", GPA: " << students[i].gpa << endl;
    }

    delete[] students;
    return 0;
}
