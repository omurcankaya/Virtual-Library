#pragma once
#include <iostream>
#include <string>
#include "Author.h"
#include "Library.h"

using std::string;
class Library;
class Author;

class Books
{
	friend class Library;
private:
	
	string bookName;
	Author* author;
	Library* library;
	int year;
	bool isAvailable;
public:
	Books() = default;
	Books(Books&);
	Books(Books&&);
	Books& operator=(Books&);
	Books& operator=(Books&&);
	Books(string bookName, Author* author, int year);
	Books(string bookName, Author* author, int year, Library* library);
	virtual ~Books();
	void SetAuthor(Author* author) {
		this->author = author;
	};
	string getBookName() const {
		return bookName;
	};
	string getAuthorName() const;
	string getAuthorInfo() const;
	int getYear() const {
		return year;
	};
	bool getIsAvailable() const {
		return isAvailable;
	};
	bool RentBook();
	bool GiveBackBook();
};
