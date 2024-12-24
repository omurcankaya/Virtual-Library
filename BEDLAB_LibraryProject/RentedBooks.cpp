#include "RentedBooks.h"

RentedBooks::RentedBooks() : Library(MAX_RENTED_BOOKS) {
	bookCount = 0;
	for (int i = 0; i < MAX_RENTED_BOOKS; i++) {
		books[i] = nullptr;
	}
}

RentedBooks::~RentedBooks() {
	for (int i = 0; i < MAX_RENTED_BOOKS; i++) {
		books[i] = nullptr;
	}
}

void RentedBooks::AddBook(Books* book) {
	if (bookCount < MAX_RENTED_BOOKS) {
		if (book != nullptr && book->RentBook()) {
			books[bookCount] = book;
			bookCount++;
		}
		else {
			std::cout << "Book is not available\n";
			return;
		}
	}
	else {
		std::cout << "You cannot rent books more than " << MAX_RENTED_BOOKS << std::endl;
	}
}

void RentedBooks::ListBooks() {
	if(bookCount == 0) {
		std::cout << "No books rented (Type 0 to return main menu) \n";
		return;
	}
	for (int i = 0; i < MAX_RENTED_BOOKS; i++) {
		if (books[i] != nullptr) {
			std::cout << i << ". " << books[i]->getBookName() << " - " << books[i]->getAuthorName() << " - " << books[i]->getYear() << std::endl;
		}
	}
}

void RentedBooks::GiveBackBook(int index) {
	if (index < MAX_RENTED_BOOKS && index >= 0) {
		if (books[index] != nullptr && books[index]->GiveBackBook()) {
			books[index] = nullptr;
			bookCount--;
		}
		else {
			std::cout << "Book is not rented!\n";
		}
	}
	else {
		std::cout << "Index is out of range\n";
	}
}

RentedBooks::RentedBooks(RentedBooks&& other) {
	bookCount = other.bookCount;
	for (int i = 0; i < MAX_RENTED_BOOKS; i++) {
		books[i] = other.books[i];
		other.books[i] = nullptr;
	}
}
RentedBooks& RentedBooks::operator=(RentedBooks&& other) {
	if (this != &other) {
		bookCount = other.bookCount;
		for (int i = 0; i < MAX_RENTED_BOOKS; i++) {
			books[i] = other.books[i];
			other.books[i] = nullptr;
		}
	}
	return *this;
}