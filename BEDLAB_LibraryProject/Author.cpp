#include "Author.h"

Author::Author()
{
	name = "Anonymous";
	age = 0;
}
Author::Author(string name, int age) : name(name), age(age)
{
	
}
Author::~Author()
{
	for(int i = 0; i < MAX_OWNED_BOOKS; i++)
	{
		if(books[i] != nullptr)
		{
			books[i]->SetAuthor(nullptr);
		}
	}
}

Author::Author(Author&& other) : name(other.name), age(other.age)
{
	for (int i = 0; i < MAX_OWNED_BOOKS; i++)
	{
		if (other.books[i] != nullptr)
		{
			books[i] = other.books[i];
			other.books[i] = nullptr;
			books[i]->SetAuthor(this);
		}
	}
}

Author& Author::operator=(Author&& other)
{
	if(this != &other)
	{
		name = other.name;
		age = other.age;
		for(int i = 0; i < MAX_OWNED_BOOKS; i++)
		{
			if (other.books[i] != nullptr)
			{
				books[i] = other.books[i];
				other.books[i] = nullptr;
				books[i]->SetAuthor(this);
			}
		}
	}
	return *this;
}

void Author::setName(const char * name)
{
	this->name = name;
}
void Author::setAge(int age)
{
	this->age = age;
}

void Author::AddBook(Books* book)
{
	for(int i = 0; i < MAX_OWNED_BOOKS; i++)
	{
		if(books[i] == nullptr)
		{
			books[i] = book;
			book->SetAuthor(this);
			return;
		}
	}
	std::cout << "Author can't have more than 5 books" << std::endl;
}
void Author::RemoveBook(Books* book)
{
	for(int i = 0; i < MAX_OWNED_BOOKS; i++)
	{
		if(books[i] == book)
		{
			book[i].SetAuthor(nullptr);
			books[i] = nullptr;
			return;
		}
	}
	std::cout << "Book is not found " << std::endl;
}