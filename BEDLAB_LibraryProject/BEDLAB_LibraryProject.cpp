#include <iostream>
#include <vector>
#include <iomanip>

#include "Global.h"
#include "Author.h"
#include "Books.h"
#include "Library.h"
#include "RentedBooks.h"

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::string;
using std::vector;

inline void CinClear() {
    system("cls");
	cin.clear();
	cin.ignore();
    cout << "Invalid Input" << endl;
}
#ifndef TESTING


int main()
{
    RentedBooks rentedBooks;

    vector<Author*> authors;
    vector<Books*> books; 

    authors.push_back(new Author("J.K. Rowling", 55));
    authors.push_back(new Author("George R.R. Martin", 72));
    authors.push_back(new Author("J.R.R. Tolkien", 81));

    books.push_back(new Books("Harry Potter and the Philosopher's Stone", authors[0], 1997));
    books.push_back(new Books("A Game of Thrones", authors[1], 1996));
    books.push_back(new Books("The Hobbit", authors[2], 1937));

    Library library;
    for (int i = 0; i < books.size(); i++) {
		library.AddBook(books[i]);
	}

    string bookName, authorName;
    while (true) {

        cout << "1. List Books" << endl;
        cout << "2. Rent Book" << endl;
        cout << "3. Give Back Book" << endl;
        cout << "4. Donate A Book" << endl; // Added this option to donate a book to the library
        cout << "5. Remove Book" << endl; // Added this option to remove a book from the library
        cout << "4. Exit" << endl;
        cout << "\nEnter your choice: ";

        int choice, index;
        cin >> choice;
        cin.ignore();
        if(cin.fail()) {
            CinClear();
			continue;
		}

        switch (choice) {
        case 1:
            system("cls");
            library.ListBooks();
            cout << endl;
            break;
        case 2:
            system("cls");
            library.ListBooks();
            cout << "\nEnter the index of the book you want to rent: ";
            cin >> index;
            cin.ignore();
            if (cin.fail()) {
                CinClear();
                continue;
            }
            rentedBooks.AddBook(library.GetBook(index));
            break;
        case 3:
            system("cls");
            rentedBooks.ListBooks();
            cout << "\nEnter the index of the book you want to give back: ";
            cin >> index;
            cin.ignore();

            if (cin.fail()) {
                CinClear();
                continue;
            }
            rentedBooks.GiveBackBook(index);

            break;
        case 4:
            system("cls");

            int year,age;
			cout << "Enter the name of the book you want to donate: ";

			std::getline(cin, bookName);
            
            cout << "Enter the year of the book: ";
            cin >> year;
            if(cin.fail()) {
				CinClear();
				continue;
			}
            for (int i = 0; i < authors.size(); i++) {
                cout << i << ". ";
                authors[i]->AuthorDetails();
            }
            cout << "Enter the index of the author of the book (to add author type -1): ";
            cin >> index;
            if (index == -1) {
                cout << "Enter the author of the book: ";
                cin.ignore();
                std::getline(cin, authorName);
                cout << "Enter the author's age:";
                cin >> age;
                authors.push_back(new Author(authorName, age));
                books.push_back(new Books(bookName, authors[authors.size() - 1], year));

            }
            else {
                books.push_back(new Books(bookName, authors[index], year));

            }
			library.AddBook(books[books.size()-1]);
			break;
        case 5:
            system("cls");
			library.ListBooks();
			cout << "\nEnter the index of the book you want to remove: ";
			cin >> index;
			if (cin.fail()) {
				CinClear();
				continue;
			}
			library.RemoveBook(index);
			break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
    for(auto& author: authors) {
		delete author;
	}
    for(auto& book: books) {
		delete book;
	}
	return 0;
}

#endif // !TESTING