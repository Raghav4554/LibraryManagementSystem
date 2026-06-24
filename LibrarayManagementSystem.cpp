#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Book Class
class Book {
public:
    int id;
    string title;
    string author;
    bool issued;

    Book(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
        issued = false;
    }
};

// Member Class
class Member {
public:
    int id;
    string name;

    Member(int i, string n) {
        id = i;
        name = n;
    }
};

// Library Class
class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:

    // Add Book
    void addBook(int id, string title, string author) {
        books.push_back(Book(id, title, author));
        cout << "Book added successfully!\n";
    }

    // Add Member
    void addMember(int id, string name) {
        members.push_back(Member(id, name));
        cout << "Member added successfully!\n";
    }

    // Display Books
    void displayBooks() {
        cout << "\n--- Book List ---\n";

        for (auto &b : books) {
            cout << "ID: " << b.id
                 << ", Title: " << b.title
                 << ", Author: " << b.author
                 << ", Status: ";

            if (b.issued)
                cout << "Issued";
            else
                cout << "Available";

            cout << endl;
        }
    }

    // Issue Book
    void issueBook(int bookId) {
        for (auto &b : books) {
            if (b.id == bookId) {

                if (b.issued) {
                    cout << "Book already issued!\n";
                } else {
                    b.issued = true;
                    cout << "Book issued successfully!\n";
                }

                return;
            }
        }

        cout << "Book not found!\n";
    }

    // Return Book
    void returnBook(int bookId) {
        for (auto &b : books) {

            if (b.id == bookId) {

                if (!b.issued) {
                    cout << "Book was not issued!\n";
                } else {
                    b.issued = false;
                    cout << "Book returned successfully!\n";
                }

                return;
            }
        }

        cout << "Book not found!\n";
    }

    // Search by Title
    void searchByTitle(string title) {
        bool found = false;

        for (auto &b : books) {

            if (b.title == title) {
                cout << "\nBook Found:\n";
                cout << "ID: " << b.id
                     << ", Title: " << b.title
                     << ", Author: " << b.author << endl;

                found = true;
            }
        }

        if (!found)
            cout << "No book found with this title!\n";
    }

    // Search by Author
    void searchByAuthor(string author) {
        bool found = false;

        for (auto &b : books) {

            if (b.author == author) {
                cout << "\nBook Found:\n";
                cout << "ID: " << b.id
                     << ", Title: " << b.title
                     << ", Author: " << b.author << endl;

                found = true;
            }
        }

        if (!found)
            cout << "No books found by this author!\n";
    }
};

// Main Function
int main() {

    Library lib;

    int choice;

    do {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Add Member\n";
        cout << "3. Display Books\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Search by Title\n";
        cout << "7. Search by Author\n";
        cout << "8. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

        case 1: {
            int id;
            string title, author;

            cout << "Enter Book ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Title: ";
            getline(cin, title);

            cout << "Enter Author: ";
            getline(cin, author);

            lib.addBook(id, title, author);
            break;
        }

        case 2: {
            int id;
            string name;

            cout << "Enter Member ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Member Name: ";
            getline(cin, name);

            lib.addMember(id, name);
            break;
        }

        case 3:
            lib.displayBooks();
            break;

        case 4: {
            int id;

            cout << "Enter Book ID to issue: ";
            cin >> id;

            lib.issueBook(id);
            break;
        }

        case 5: {
            int id;

            cout << "Enter Book ID to return: ";
            cin >> id;

            lib.returnBook(id);
            break;
        }

        case 6: {
            string title;

            cin.ignore();

            cout << "Enter Title to search: ";
            getline(cin, title);

            lib.searchByTitle(title);
            break;
        }

        case 7: {
            string author;

            cin.ignore();

            cout << "Enter Author to search: ";
            getline(cin, author);

            lib.searchByAuthor(author);
            break;
        }

        case 8:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while(choice != 8);

    return 0;
}
