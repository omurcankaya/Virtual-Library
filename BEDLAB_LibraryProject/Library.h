#pragma once
#include "Books.h"

constexpr auto MAX_LIBRARY_SIZE = 100;

class Library
{
	friend class Books;
protected:
	Books** books = new Books*[MAX_LIBRARY_SIZE];
	int bookCount;
private:
	void RemoveBook(Books* book);
public:
	Library();
	Library(const int Capacity);
	virtual ~Library();
	Library(const Library& other) = delete;
	Library(Library&& other); // move constructor
	Library& operator=(const Library& other) = delete;
	Library& operator=(Library&& other); // move assignment operator

	void AddBook(Books* book);
	void RemoveBook(int index);
	void ListBooks();
	
	Books* GetBook(int index);
};

