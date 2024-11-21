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
// Getter for ISBN
    string getISBN() const { return isbn; }

    // Getter for availability
    bool isAvailable() const { return available; }
};

// Main Function
int main() {
    // Initialize the library with 5 books
    vector<Book> library = {
        Book("Jane Eyre", "Charlotte Brontë", "00254", true, "2022-01-10"),
        Book("Harry Potter and the Philosopher's Stone", " J. K. Rowling", "00523", true, "2022-03-15"),
        Book("To Kill a Mockingbird", "Harper Lee", "15368", true, "2022-06-20"),
        Book("Pride and Prejudice", "Jane Austen", "22003", true, "2022-09-05"),
        Book("Moby Dick", "Herman Melville", "27809", true, "2022-12-25") };
 cout << "Welcome to the Community Library!\n";

    string inputISBN;
    while (true) {
        cout << "\nLibrary Books:\n";
        for (const auto& book : library) {
            book.displayBookDetails();
        }

        cout << "\nEnter the ISBN of the book you want to borrow (or 0 to exit): ";
        cin >> inputISBN;

        if (inputISBN == "0") {
            cout << "Exiting the system. Thank you for using the library!" << endl;
            break;
        }

        bool found = false;
        for (auto& book : library) {
            if (book.getISBN() == inputISBN) {
                found = true;
                book.borrowBook();
                break;
            }
        }

        if (!found) {
            cout << "No book found with ISBN " << inputISBN << ". Please try again." << endl;
        }
    }

    return 0;
}
