#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    int year;
};

void addBook(vector<Book>& library) {
    Book b;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, b.title);
    cout << "Enter author: ";
    getline(cin, b.author);
    cout << "Enter year of publication: ";
    cin >> b.year;
    library.push_back(b);
    cout << "Book added.\n";
}

void searchByAuthor(const vector<Book>& library) {
    string searchAuthor;
    cout << "Enter author name to search: ";
    cin.ignore();
    getline(cin, searchAuthor);
    bool found = false;

    for (const auto& b : library) {
        if (b.author == searchAuthor) {
            cout << "Title: " << b.title << ", Year: " << b.year << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No books found by this author.\n";
    }
}

void searchByYear(const vector<Book>& library) {
    int searchYear;
    cout << "Enter publication year to search: ";
    cin >> searchYear;
    bool found = false;

    for (const auto& b : library) {
        if (b.year == searchYear) {
            cout << "Title: " << b.title << ", Author: " << b.author << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No books found from this year.\n";
    }
}

int main() {
    vector<Book> library;
    int choice;

    do {
        cout << "\n1. Add book\n2. Search by author\n3. Search by year\n4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(library);
                break;
            case 2:
                searchByAuthor(library);
                break;
            case 3:
                searchByYear(library);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
