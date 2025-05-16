#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
    int year;

    void display() const {
        cout << "\nID: " << id
             << "\nTitle: " << title
             << "\nAuthor: " << author
             << "\nYear: " << year << "\n";
    }
};

class Library 
{
private:
    vector<Book> books;
    const string filename = "library.dat";

public:
    void loadFromFile() {
        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            cout << "No existing library file found. Starting fresh.\n";
            return;
        }

        Book book;
        while (inFile.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
            books.push_back(book);
        }
        inFile.close();
        cout << "Loaded " << books.size() << " books from file.\n";
    }

    void saveToFile() {
        ofstream outFile(filename, ios::binary | ios::trunc);
        for (const auto& book : books) {
            outFile.write(reinterpret_cast<const char*>(&book), sizeof(Book));
        }
        outFile.close();
        cout << "Library saved successfully.\n";
    }

    void addBook() 
    {
        Book b;
        cout << "Enter book ID: ";
        cin >> b.id;
        cin.ignore();
        cout << "Enter title: ";
        getline(cin, b.title);
        cout << "Enter author: ";
        getline(cin, b.author);
        cout << "Enter year: ";
        cin >> b.year;

        books.push_back(b);
        cout << "Book added successfully.\n";
    }

    void listBooks() const {
        if (books.empty()) {
            cout << "No books in library.\n";
            return;
        }

        cout << "\n--- Book List ---\n";
        for (const auto& book : books) {
            cout << "----------------------";
            book.display();
        }
    }

    void searchBook() const {
        int id;
        cout << "Enter book ID to search: ";
        cin >> id;

        auto it = find_if(books.begin(), books.end(), [id](const Book& b) {
            return b.id == id;
        });

        if (it != books.end()) {
            cout << "Book found:";
            it->display();
        } else {
            cout << "Book with ID " << id << " not found.\n";
        }
    }

    void deleteBook() {
        int id;
        cout << "Enter book ID to delete: ";
        cin >> id;

        auto it = remove_if(books.begin(), books.end(), [id](const Book& b) {
            return b.id == id;
        });

        if (it != books.end()) {
            books.erase(it, books.end());
            cout << "Book deleted successfully.\n";
        } else {
            cout << "Book not found.\n";
        }
    }

    void menu() {
        int choice;
        do {
            cout << "\n===== Library Menu =====\n";
            cout << "1. Add Book\n";
            cout << "2. View Books\n";
            cout << "3. Search Book\n";
            cout << "4. Delete Book\n";
            cout << "5. Save Library\n";
            cout << "0. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1: addBook(); break;
                case 2: listBooks(); break;
                case 3: searchBook(); break;
                case 4: deleteBook(); break;
                case 5: saveToFile(); break;
                case 0: saveToFile(); cout << "Exiting...\n"; break;
                default: cout << "Invalid choice.\n";
            }
        } while (choice != 0);
    }
};

int main() 
{
    Library lib;
    lib.loadFromFile();
    lib.menu();
    return 0;
}

