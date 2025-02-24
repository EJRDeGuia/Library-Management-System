#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Book {
private:
    string title;
    string author;
    int year;

public:
    // Constructor
    Book(string t, string a, int y) : title(t), author(a), year(y) {}

    // Getter methods
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getYear() const { return year; }

    // Display book details
    void display() const {
        cout << "| " << left << setw(25) << title 
             << "| " << setw(20) << author 
             << "| " << setw(6) << year << " |\n";
    }
};

class Library {
private:
    vector<Book> books; // Stores all books

public:
    // Add a book to the library using emplace_back
    void addBook(const string& title, const string& author, int year) {
        books.emplace_back(title, author, year); // Construct Book directly in the vector
        cout << "\nBook added successfully!\n";
    }

    // Display all books in the library
    void displayBooks() const {
        if (books.empty()) {
            cout << "\nNo books available in the library.\n";
            return;
        }

        cout << "\n+---------------------------+--------------------+--------+\n";
        cout << "| " << left << setw(25) << "Title"
             << "| " << setw(20) << "Author"
             << "| " << setw(6) << "Year" << " |\n";
        cout << "+---------------------------+--------------------+--------+\n";
        for (const auto& book : books) {
            book.display();
        }
        cout << "+---------------------------+--------------------+--------+\n";
    }
};

int main() {
    Library library;
    int choice;

    do {
        cout << "\n=================================\n";
        cout << "          Library Menu\n";
        cout << "=================================\n";
        cout << "1 - Add Book\n";
        cout << "2 - Display Books\n";
        cout << "3 - Exit\n";
        cout << "=================================\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
        case 1: {
            string title, author;
            int year;
            cout << "\nEnter title: ";
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter year: ";
            cin >> year;
            library.addBook(title, author, year);
            break;
        }
        case 2:
            cout << "\nBook List:\n";
            library.displayBooks();
            break;
        case 3:
            cout << "\nExiting the program. Goodbye!\n";
            break;
        default:
            cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}
