#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ------------------ Book Class ------------------
class Book {
    int id;
    string title;
    string author;
    bool isIssued;

public:
    Book(int id, string title, string author)
        : id(id), title(title), author(author), isIssued(false) {}

    void display() {
        cout << "Book ID: " << id
             << ", Title: " << title
             << ", Author: " << author
             << ", Available: " << (isIssued ? "No" : "Yes") << endl;
    }

    bool checkAvailability() {
        return !isIssued;
    }

    void issue() {
        isIssued = true;
    }

    void returnBook() {
        isIssued = false;
    }

    int getId() const {
        return id;
    }
};

// ------------------ Abstract User Class ------------------
class User {
protected:
    int userId;
    string name;

public:
    User(int userId, string name) : userId(userId), name(name) {}

    virtual void issueBook(Book& book) = 0;
    virtual void returnBook(Book& book) = 0;

    virtual void displayInfo() {
        cout << "User ID: " << userId << ", Name: " << name << endl;
    }

    int getUserId() const {
        return userId;
    }
};

// ------------------ Student Class ------------------
class Student : public User {
public:
    Student(int id, string name) : User(id, name) {}

    void issueBook(Book& book) override {
        if (book.checkAvailability()) {
            book.issue();
            cout << name << " (Student) issued the book." << endl;
        } else {
            cout << "Book is already issued!" << endl;
        }
    }

    void returnBook(Book& book) override {
        book.returnBook();
        cout << name << " (Student) returned the book." << endl;
    }
};

// ------------------ Teacher Class ------------------
class Teacher : public User {
public:
    Teacher(int id, string name) : User(id, name) {}

    void issueBook(Book& book) override {
        if (book.checkAvailability()) {
            book.issue();
            cout << name << " (Teacher) issued the book." << endl;
        } else {
            cout << "Book is already issued!" << endl;
        }
    }

    void returnBook(Book& book) override {
        book.returnBook();
        cout << name << " (Teacher) returned the book." << endl;
    }
};

// ------------------ Library Class ------------------
class Library {
    vector<Book> books;
    vector<User*> users;

public:
    void addBook(Book book) {
        books.push_back(book);
    }

    void addUser(User* user) {
        users.push_back(user);
    }

    void showBooks() {
        for (auto& book : books) {
            book.display();
        }
    }

    void issueBook(int bookId, int userId) {
        Book* book = nullptr;
        User* user = nullptr;

        for (auto& b : books) {
            if (b.getId() == bookId) {
                book = &b;
                break;
            }
        }

        for (auto& u : users) {
            if (u->getUserId() == userId) {
                user = u;
                break;
            }
        }

        if (book && user) {
            user->issueBook(*book);
        } else {
            cout << "Book or User not found!" << endl;
        }
    }

    void returnBook(int bookId, int userId) {
        Book* book = nullptr;
        User* user = nullptr;

        for (auto& b : books) {
            if (b.getId() == bookId) {
                book = &b;
                break;
            }
        }

        for (auto& u : users) {
            if (u->getUserId() == userId) {
                user = u;
                break;
            }
        }

        if (book && user) {
            user->returnBook(*book);
        } else {
            cout << "Book or User not found!" << endl;
        }
    }
};

// ------------------ Main Function ------------------
int main() {
    Library lib;

    lib.addBook(Book(1, "C++ Primer", "Lippman"));
    lib.addBook(Book(2, "Effective C++", "Scott Meyers"));

    lib.addUser(new Student(101, "Alice"));
    lib.addUser(new Teacher(102, "Dr. Bob"));

    cout << "\n--- Available Books ---\n";
    lib.showBooks();

    cout << "\n--- Issuing Book ---\n";
    lib.issueBook(1, 101); // Alice issues Book 1

    cout << "\n--- Available Books ---\n";
    lib.showBooks();

    cout << "\n--- Returning Book ---\n";
    lib.returnBook(1, 101); // Alice returns Book 1

    cout << "\n--- Available Books ---\n";
    lib.showBooks();

    return 0;
}

