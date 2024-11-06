//#include <iostream>
//#include <string>
//using namespace std;
//
//class Book {
//private:
//    string title;
//    string author;
//    string ISBN;
//    bool isAvailable;
//    static int totalBooks;
//
//public:
//    // Constructor
//    Book(string t = "", string a = "", string isbn = "", bool avail = true)
//        : title(t), author(a), ISBN(isbn), isAvailable(avail) {
//        totalBooks++;
//    }
//
//    // Destructor
//    ~Book() {
//        totalBooks--;
//    }
//
//    // Static method to get total books
//    static int getTotalBooks() {
//        return totalBooks;
//    }
//
//    // Getters
//    string getTitle() const { return title; }
//    string getAuthor() const { return author; }
//    string getISBN() const { return ISBN; }
//    bool getAvailability() const { return isAvailable; }
//
//    // Operator overloading for comparison
//    bool operator==(const Book &other) const {
//        return this->ISBN == other.ISBN;
//    }
//
//    bool operator<(const Book &other) const {
//        return this->title < other.title;
//    }
//
//    // Method to print book info
//    void display() const {
//        cout << "Title: " << title << "\nAuthor: " << author
//             << "\nISBN: " << ISBN << "\nAvailable: " << (isAvailable ? "Yes" : "No") << endl;
//    }
//};
//
//// Initialize static member
//int Book::totalBooks = 0;
//
//
//
//
//class Library {
//private:
//    Book* books[100]; // Pointer array for book objects (for dynamic allocation)
//    int bookCount;
//
//public:
//    Library() : bookCount(0) {}
//
//    // Add book function
//    void addBook(Book* book) {
//        if (bookCount < 100) {
//            books[bookCount] = book;
//            bookCount++;
//        } else {
//            cout << "Library is full!" << endl;
//        }
//    }
//
//    // Remove book function
//    void removeBook(const string& isbn) {
//        for (int i = 0; i < bookCount; i++) {
//            if (books[i]->getISBN() == isbn) {
//                delete books[i]; // Free dynamically allocated memory
//                books[i] = books[bookCount - 1]; // Replace with last book
//                bookCount--;
//                cout << "Book removed!" << endl;
//                return;
//            }
//        }
//        cout << "Book not found!" << endl;
//    }
//
//    // Search for a book by ISBN
//    void searchBook(const string& isbn) const {
//        for (int i = 0; i < bookCount; i++) {
//            if (books[i]->getISBN() == isbn) {
//                books[i]->display();
//                return;
//            }
//        }
//        cout << "Book not found!" << endl;
//    }
//
//    // Display all books
//    void listBooks() const {
//        for (int i = 0; i < bookCount; i++) {
//            books[i]->display();
//            cout << endl;
//        }
//    }
//
//    // Destructor to deallocate memory
//    ~Library() {
//        for (int i = 0; i < bookCount; i++) {
//            delete books[i];
//        }
//    }
//};
//
//
//
//void menu() {
//    cout << "\nLibrary Management System" << endl;
//    cout << "1. Add Book" << endl;
//    cout << "2. Remove Book" << endl;
//    cout << "3. Search Book" << endl;
//    cout << "4. List All Books" << endl;
//    cout << "5. Exit" << endl;
//    cout << "Enter your choice: ";
//}
//
//int main() {
//    Library lib;
//    int choice;
//    string title, author, isbn;
//    
//    do {
//        menu();
//        cin >> choice;
//        switch (choice) {
//            case 1: {
//                cout << "Enter title: "; cin >> title;
//                cout << "Enter author: "; cin >> author;
//                cout << "Enter ISBN: "; cin >> isbn;
//                lib.addBook(new Book(title, author, isbn));
//                break;
//            }
//            case 2: {
//                cout << "Enter ISBN to remove: "; cin >> isbn;
//                lib.removeBook(isbn);
//                break;
//            }
//            case 3: {
//                cout << "Enter ISBN to search: "; cin >> isbn;
//                lib.searchBook(isbn);
//                break;
//            }
//            case 4: {
//                lib.listBooks();
//                break;
//            }
//            case 5: {
//                cout << "Exiting program..." << endl;
//                break;
//            }
//            default:
//                cout << "Invalid choice! Try again." << endl;
//        }
//    } while (choice != 5);
//
//    return 0;
//}






//#include <iostream>
//#include <string>
//#include <iomanip> // For formatting
//using namespace std;
//
//const int MAX_BOOKS = 100;
//
//class Book {
//protected:
//    string title;
//    string author;
//    string ISBN;
//    bool isAvailable;
//    static int totalBooks;
//
//public:
//    // Constructor
//    Book(string t = "", string a = "", string isbn = "", bool avail = true)
//        : title(t), author(a), ISBN(isbn), isAvailable(avail) {
//        totalBooks++;
//    }
//
//    // Destructor
//    virtual ~Book() {
//        totalBooks--;
//    }
//
//    // Static method to get total books
//    static int getTotalBooks() {
//        return totalBooks;
//    }
//
//    // Getters
//    string getTitle() const { return title; }
//    string getAuthor() const { return author; }
//    string getISBN() const { return ISBN; }
//    bool getAvailability() const { return isAvailable; }
//
//    // Set availability
//    void setAvailability(bool avail) { isAvailable = avail; }
//
//    // Operator overloading for comparison
//    bool operator==(const Book &other) const {
//        return this->ISBN == other.ISBN;
//    }
//
//    bool operator<(const Book &other) const {
//        return this->title < other.title;
//    }
//
//    // Virtual method to display book info (polymorphism)
//    virtual void display() const {
//        cout << setw(30) << left << title
//             << setw(20) << author
//             << setw(15) << ISBN
//             << setw(10) << (isAvailable ? "Yes" : "No") << endl;
//    }
//};
//
//// Initialize static member
//int Book::totalBooks = 0;
//
//class Library {
//private:
//    Book* books[MAX_BOOKS]; // Pointer array for book objects
//    int bookCount;
//
//public:
//    Library() : bookCount(0) {}
//
//    // Add book function
//    void addBook(Book* book) {
//        if (bookCount < MAX_BOOKS) {
//            books[bookCount] = book;
//            bookCount++;
//            cout << "Book added successfully!" << endl;
//        } else {
//            cout << "Library is full! Cannot add more books." << endl;
//        }
//    }
//
//    // Remove book function
//    void removeBook(const string& isbn) {
//        for (int i = 0; i < bookCount; i++) {
//            if (books[i]->getISBN() == isbn) {
//                delete books[i]; // Free dynamically allocated memory
//                books[i] = books[bookCount - 1]; // Replace with last book
//                bookCount--;
//                cout << "Book removed successfully!" << endl;
//                return;
//            }
//        }
//        cout << "Book not found!" << endl;
//    }
//
//    // Search for a book by ISBN
//    void searchBook(const string& isbn) const {
//        for (int i = 0; i < bookCount; i++) {
//            if (books[i]->getISBN() == isbn) {
//                books[i]->display();
//                return;
//            }
//        }
//        cout << "Book not found!" << endl;
//    }
//
//    // Display all books
//    void listBooks() const {
//        cout << setw(30) << left << "Title"
//             << setw(20) << "Author"
//             << setw(15) << "ISBN"
//             << setw(10) << "Available" << endl;
//        cout << "--------------------------------------------------------------" << endl;
//
//        for (int i = 0; i < bookCount; i++) {
//            books[i]->display();
//        }
//    }
//
//    // Destructor to deallocate memory
//    ~Library() {
//        for (int i = 0; i < bookCount; i++) {
//            delete books[i];
//        }
//    }
//};
//
//// UI function to print cool menu
//void menu() {
//    cout << "\n=============================\n";
//    cout << "   LIBRARY MANAGEMENT SYSTEM   \n";
//    cout << "=============================\n";
//    cout << "1. Add Book\n";
//    cout << "2. Remove Book\n";
//    cout << "3. Search Book\n";
//    cout << "4. List All Books\n";
//    cout << "5. Exit\n";
//    cout << "=============================\n";
//    cout << "Enter your choice: ";
//}
//
//// Main program with enhanced UI and error handling
//int main() {
//    Library lib;
//    int choice;
//    string title, author, isbn;
//    
//    do {
//        menu();
//        cin >> choice;
//        cin.ignore(); // Clear the newline character after cin
//        
//        switch (choice) {
//            case 1: {
//                cout << "Enter book title: "; 
//                getline(cin, title); // Allows for long titles
//                cout << "Enter book author: "; 
//                getline(cin, author);
//                cout << "Enter ISBN: "; 
//                getline(cin, isbn);
//                lib.addBook(new Book(title, author, isbn));
//                break;
//            }
//            case 2: {
//                cout << "Enter ISBN to remove: "; 
//                getline(cin, isbn);
//                lib.removeBook(isbn);
//                break;
//            }
//            case 3: {
//                cout << "Enter ISBN to search: "; 
//                getline(cin, isbn);
//                lib.searchBook(isbn);
//                break;
//            }
//            case 4: {
//                lib.listBooks();
//                break;
//            }
//            case 5: {
//                cout << "Exiting... Have a nice day!" << endl;
//                break;
//            }
//            default:
//                cout << "Invalid choice! Please try again." << endl;
//        }
//    } while (choice != 5);
//
//    return 0;
//}




#include <iostream>
#include <string>
#include <limits> // For handling input errors
using namespace std;

// Maximum number of books allowed in the library
const int MAX_CAPACITY = 100;

class Book {
private:
    string title;
    string author;
    string ISBN;
    bool isAvailable;
    static int totalBooks;

public:
    // Constructor
    Book(string t = "", string a = "", string isbn = "", bool avail = true)
        : title(t), author(a), ISBN(isbn), isAvailable(avail) {
        totalBooks++;
    }

    // Destructor
    ~Book() {
        totalBooks--;
    }

    // Static method to get total books
    static int getTotalBooks() {
        return totalBooks;
    }

    // Getters
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return ISBN; }
    bool getAvailability() const { return isAvailable; }

    // Operator overloading for comparison
    bool operator==(const Book &other) const {
        return this->ISBN == other.ISBN;
    }

    bool operator<(const Book &other) const {
        return this->title < other.title;
    }

    // Method to print book info
    void display() const {
        cout << "--------------------------------------------" << endl;
        cout << "Title: " << title << "\nAuthor: " << author
             << "\nISBN: " << ISBN << "\nAvailable: " << (isAvailable ? "Yes" : "No") << endl;
        cout << "--------------------------------------------" << endl;
    }
};

// Initialize static member
int Book::totalBooks = 0;

// Library class
class Library {
private:
    Book* books[MAX_CAPACITY]; // Pointer array for book objects (dynamic allocation)
    int bookCount;

public:
    Library() : bookCount(0) {}

    // Add book function
    void addBook(Book* book) {
        if (bookCount < MAX_CAPACITY) {
            books[bookCount] = book;
            bookCount++;
            cout << "Book added successfully!" << endl;
        } else {
            cout << "Library is full! Cannot add more books." << endl;
        }
    }

    // Remove book function
    void removeBook(const string& isbn) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i]->getISBN() == isbn) {
                delete books[i]; // Free dynamically allocated memory
                books[i] = books[bookCount - 1]; // Replace with last book
                bookCount--;
                cout << "Book removed!" << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    // Search for a book by ISBN
    void searchBook(const string& isbn) const {
        for (int i = 0; i < bookCount; i++) {
            if (books[i]->getISBN() == isbn) {
                books[i]->display();
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    // Display all books
    void listBooks() const {
        if (bookCount == 0) {
            cout << "No books in the library!" << endl;
        } else {
            for (int i = 0; i < bookCount; i++) {
                books[i]->display();
            }
        }
    }

    // Clear all books from the library
    void clearLibrary() {
        for (int i = 0; i < bookCount; i++) {
            delete books[i];
        }
        bookCount = 0;
        cout << "All books have been cleared from the library!" << endl;
    }

    // Destructor to deallocate memory
    ~Library() {
        clearLibrary();
    }
};

// Input helper function for handling string inputs
void safeGetline(string &input) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Flush previous input
    getline(cin, input); // Get the full line of input
}

// Menu to display options
void menu() {
    cout << "\n===== Welcome to Cool Library Management System =====" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Remove Book" << endl;
    cout << "3. Search Book" << endl;
    cout << "4. List All Books" << endl;
    cout << "5. Clear Library" << endl;
    cout << "6. Exit" << endl;
    cout << "====================================================" << endl;
    cout << "Enter your choice: ";
}

// Main Function
int main() {
    Library lib;
    int choice;
    string title, author, isbn;

    do {
        menu();
        cin >> choice;
        
        if(cin.fail()) {
            cin.clear(); // Clear error flag
            cin.ignore(yynumeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input! Please enter a number between 1 and 6." << endl;
            continue;
        }

        switch (choice) {
            case 1: {
                cout << "Enter book title: "; 
                safeGetline(title);
                cout << "Enter author name: "; 
                safeGetline(author);
                cout << "Enter ISBN: "; 
                safeGetline(isbn);

                // Add a new book
                lib.addBook(new Book(title, author, isbn));
                break;
            }
            case 2: {
                cout << "Enter ISBN to remove: "; 
                cin >> isbn;
                lib.removeBook(isbn);
                break;
            }
            case 3: {
                cout << "Enter ISBN to search: "; 
                cin >> isbn;
                lib.searchBook(isbn);
                break;
            }
            case 4: {
                lib.listBooks();
                break;*
            }
            case 5: {
                lib.clearLibrary();
                break;
            }
            case 6: {
                cout << "Exiting program... Goodbye!" << endl;
                break;
            }
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}


