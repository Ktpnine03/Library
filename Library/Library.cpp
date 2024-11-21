#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Book Class
class Book {
private:
    string title;
    string author;
    string isbn;
    bool available;
    string dateAdded;

public:
    // Constructor
    Book(string t, string a, string i, bool avl, string date)
        : title(t), author(a), isbn(i), available(avl), dateAdded(date) {}

    // Set book details 
    void setBookDetails(string t, string a, string i, bool avl, string date) {
        title = t;
        author = a;
        isbn = i;
        available = avl;
        dateAdded = date;
    }

    // Display book details
    void displayBookDetails() const {
        cout << "Title: " << title << ", Author: " << author
            << ", ISBN: " << isbn
            << ", Availability: " << (available ? "Available" : "Borrowed") << endl;
    }
 // Borrow book
    bool borrowBook() {
        if (available) {
            available = false;
            cout << "You successfully borrowed \"" << title << "\"." << endl;
            return true;
        }
        else {
            cout << "Sorry, \"" << title << "\" is currently unavailable." << endl;
            return false;
        }
    }

    // Return book
    void returnBook() {
        available = true;
        cout << "\"" << title << "\" has been returned and is now available." << endl;
    }
