#pragma once
#include <iostream>
#include "Books.h"
#include "AuthorDriver.h"

using std::string;
class Books;
constexpr int MAX_OWNED_BOOKS = 5;

class Author
{
	friend class Books;
private:
	string name;
	Books* books[MAX_OWNED_BOOKS]{ };
	void AddBook(Books* book);
	void RemoveBook(Books* book);
	int age;
public:
	Author();
	Author(string name, int age);
	~Author();
	Author(const Author& other) = delete; // Ayni yazar tekrar edemez
	Author& operator=(const Author& other) = delete; // Ayni yazar tekrar edemez
	Author(Author&& other);
	Author& operator=(Author&& other);
	string getName() const {
		return name;
	};
	int getAge() const {
		return age;
	};
	void AuthorDetails() const {
		std::cout << "Name: " << name << " Age: " << age << std::endl;
	}
	void setName(const char*);
	void setAge(int age);
	friend int AuthorTest();

};

