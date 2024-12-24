#include "Books.h"
Books::Books(string bookName, Author* author, int year) : bookName(bookName), author(author), year(year), isAvailable(true), library(nullptr)
{
	if (author != nullptr)
		author->AddBook(this);
}
Books::Books(string bookName, Author* author, int year, Library *library) : bookName(bookName), author(author), year(year), isAvailable(true), library(library)
{
	if(author != nullptr)
		author->AddBook(this);
}
Books::~Books() {
	if (author != nullptr) {
 		author->RemoveBook(this);
		author = nullptr;
	}
	if(library != nullptr)
		library->RemoveBook(this);

}

Books::Books(Books& other) : bookName(other.bookName), author(other.author), year(other.year), isAvailable(other.isAvailable), library(other.library)
{
	author->AddBook(this);
}
Books::Books(Books&& other) : bookName(other.bookName), author(other.author), year(other.year), isAvailable(other.isAvailable), library(other.library)
{
	other.bookName = "";
	other.year = 0;
	other.isAvailable = false;
	other.author = nullptr;
	other.library = nullptr;
	author->RemoveBook(&other);
	author->AddBook(this);

}
Books& Books::operator=(Books& other) {
	if (this != &other) {
		bookName = other.bookName;
		year = other.year;
		isAvailable = other.isAvailable;
		author = other.author;
		library = other.library;
		author->AddBook(this);
	}
	return *this;
}
Books& Books::operator=(Books&& other) {
	if (this != &other) {
		bookName = other.bookName;
		year = other.year;
		isAvailable = other.isAvailable;
		author = other.author;
		library = other.library;
		other.bookName = "";
		other.year = 0;
		other.isAvailable = false;
		other.author = nullptr;
		other.library = nullptr;
		author->RemoveBook(&other);
		author->AddBook(this);

	}
	return *this;
}

string Books::getAuthorName() const {
	if(author == nullptr)
		return "Author is Anonymous";
	return author->getName();
}
string Books::getAuthorInfo() const {
	if(author == nullptr)
		return "Author is Anonymous";
	return author->getName() + " " + std::to_string(author->getAge());
}

// Kitap sayisi daima 1 olarak kabul edilir.
bool Books::RentBook() {
	if (isAvailable) {
		isAvailable = false;
		return true;
	}
	return false;
}
bool Books::GiveBackBook() {
	if (!isAvailable) {
		isAvailable = true;
		return true;
	}
	return false;
}

