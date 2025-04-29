#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    double price;

public:
    // Default constructor
    Book() {
        cout << "Default constructor called." << endl;
    }

    // Parameterized constructor
    Book(string t, string a, double p) {
        title = t;
        author = a;
        price = p;
        cout << "Parameterized constructor called." << endl;
    }

    // Copy constructor
    Book(const Book &b) {
        title = b.title;
        author = b.author;
        price = b.price;
        cout << "Copy constructor called!" << endl;
    }

    // Destructor
    ~Book() {
        cout << "Destroying book: " << title << endl;
    }

    void displayDetails() {
        cout << "Title: " << title << ", Author: " << author << ", Price: $" << price << endl;
    }
};

int main() {
    Book b1("Atomic Habits", "James Clear", 499);
    Book b2 = b1; // Calls copy constructor

    cout << "\nDetails of copied book (b2):" << endl;
    b2.displayDetails();

    return 0;
}

