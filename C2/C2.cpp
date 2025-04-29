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
        cout << "Default constructor called: Book object created!" << endl;
    }

    // Parameterized constructor
    Book(string t, string a, double p) {
        title = t;
        author = a;
        price = p;
        cout << "Parameterized constructor called!" << endl;
    }

    // Destructor
    ~Book() {
        cout << "Destructor called: Book object destroyed!" << endl;
    }

    void displayDetails() {
        cout << "Title: " << title << ", Author: " << author << ", Price: Rs." << price << endl;
    }
};

int main() {
    Book book1; // Calls default constructor
    Book book2("Wings of Fire", "A.P.J. Abdul Kalam", 450.00); // Calls parameterized constructor

    cout << "\nDetails of book2:" << endl;
    book2.displayDetails();

    return 0;
}

