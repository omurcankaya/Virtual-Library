#include "Global.h"

#ifdef TESTING
#include <iostream>
#include "RentedBooks.h"

using std::cout;

int RentedBooksTest() {

	cout << "************** RENTED BOOKS TEST **************" << std::endl;
	RentedBooks rentedBooks;
	Books b1("Fareler ve Insanlar", nullptr, 1937, nullptr);
	Books b2("1984", nullptr, 1949, nullptr);


	rentedBooks.AddBook(&b1);
	rentedBooks.AddBook(&b2);

	cout << "Add book test" << std::endl;
	rentedBooks.ListBooks();


	cout << "Move constructor test" << std::endl;
	RentedBooks rentedBooks2(std::move(rentedBooks));
	cout << "RentedBooks2: " << std::endl;
	rentedBooks2.ListBooks();
	cout << "RentedBooks: " << std::endl;
	rentedBooks.ListBooks();

	cout << "Move assignment operator test" << std::endl;
	RentedBooks rentedBooks3;
	rentedBooks3 = std::move(rentedBooks2);
	cout << "RentedBooks3: " << std::endl;
	rentedBooks3.ListBooks();
	cout << "RentedBooks2: " << std::endl;
	rentedBooks2.ListBooks();


	cout << "Give back book test" << std::endl;
	rentedBooks3.GiveBackBook(0);
	rentedBooks3.GiveBackBook(1);

	rentedBooks3.ListBooks();

	cout << "************** RENTED BOOKS TEST ENDS **************" << std::endl;

	return 0;
}


#endif
