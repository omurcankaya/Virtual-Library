#pragma once

#include "Books.h"
#include "Library.h"
constexpr auto MAX_RENTED_BOOKS = 5;
class RentedBooks : public Library
{
public:
	RentedBooks();
	~RentedBooks() override;
	RentedBooks(const RentedBooks& other) = delete;
	RentedBooks& operator=(const RentedBooks& other) = delete;
	RentedBooks(RentedBooks&& other);
	RentedBooks& operator=(RentedBooks&& other);
	void AddBook(Books* book);
	void ListBooks();
	void GiveBackBook(int index);
};

