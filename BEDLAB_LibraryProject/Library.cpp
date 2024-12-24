#include "Library.h"
#include "RentedBooks.h"
#include <iostream>

Library::Library() : bookCount(0)
{
	for (int i = 0; i < MAX_LIBRARY_SIZE; i++)
	{
		books[i] = nullptr;
	}
}
Library::Library(const int Capacity) : bookCount(0) {
	delete [] books; // delete the old array
	books = new Books*[Capacity];

	for (int i = 0; i < Capacity; i++)
	{
		books[i] = nullptr;
	}
}

Library::~Library()
{
	for (int i = 0; i < MAX_LIBRARY_SIZE; i++)
	{
		books[i] = nullptr;
	}
}

void Library::AddBook(Books* book)
{
	if (bookCount < MAX_LIBRARY_SIZE)
	{
		for(int i = 0; i < MAX_LIBRARY_SIZE; i++)
		{
			if(books[i] == nullptr)
			{
				books[i] = book;
				book->library = this;
				bookCount++;
				return;
			}
		}

	}
	else
	{
		std::cout << "Library is full\n";
	}
}

void Library::RemoveBook(int index) {
	if (index < MAX_LIBRARY_SIZE && index >= 0) {
		if(books[index]->getIsAvailable()){
			books[index] = nullptr;
			bookCount--;
		}
		else {
			std::cout << "Give it back to remove it from library!" << std::endl;
			return;
		}
	}
	else {
		std::cout << "Index is out of range\n";
	}
}
void Library::RemoveBook(Books* book) {
	for (int i = 0; i < MAX_LIBRARY_SIZE; i++) {
		if (books[i] == book) {
			books[i] = nullptr;
			bookCount--;
			return;
		}
	}
}
void Library::ListBooks() {
	std::cout << "Books in the library:" << std::endl;
	for (int i = 0; i < MAX_LIBRARY_SIZE; i++) {
		if (books[i] != nullptr) {
			std::cout << i << ". Book Name: " <<
				books[i]->getBookName() <<
				" Author: " << books[i]->getAuthorInfo() <<
				" Year: " << books[i]->getYear() <<
				" Is Available: " << books[i]->getIsAvailable() << std::endl;
		}
	}
}

Books* Library::GetBook(int index) {
	if (index < MAX_LIBRARY_SIZE && index >= 0) {
		return books[index];
	}
	else {
		std::cout << "Index is out of range\n";
		return nullptr;
	}
}
/*
Library::Library(const Library& other) : bookCount(other.bookCount)
{
	for (int i = 0; i < MAX_LIBRARY_SIZE; i++)
	{
		if (other.books[i] != nullptr)
		{
			books[i] = other.books[i];
			other.books[i]->library = this;
		}
		else
		{
			books[i] = nullptr;
		}
	}
}
*/

Library::Library(Library&& other) : bookCount(other.bookCount)
{
	for (int i = 0; i < MAX_LIBRARY_SIZE; i++)
	{
			books[i] = other.books[i];
			if (other.books[i] != nullptr)
				books[i]->library = this;
			other.books[i] = nullptr;
	}
}
/*
Library& Library::operator=(const Library& other)
{
	if (this != &other)
	{
		for (int i = 0; i < MAX_LIBRARY_SIZE; i++)
		{
			if (other.books[i] != nullptr)
			{
				books[i] = other.books[i];
				other.books[i]->library = this;
			}
			else
			{
				books[i] = nullptr;
			}
		}
		bookCount = other.bookCount;
	}
	return *this;
}
*/
Library& Library::operator=(Library&& other)
{
	if (this != &other)
	{
		for (int i = 0; i < MAX_LIBRARY_SIZE; i++)
		{
			books[i] = other.books[i];
			if (other.books[i] != nullptr)
				other.books[i]->library = this;
			other.books[i] = nullptr;
		}
		bookCount = other.bookCount;
		other.bookCount = 0;
	}
	return *this;
}