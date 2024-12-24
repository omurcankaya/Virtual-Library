#include "Global.h"
#ifdef TESTING
#include "Books.h"
#include "Author.h"

int BooksTest() {
	std::cout << "************** BOOKS TEST **************" << std::endl;
	Author* author = new Author("Author", 30);
	Books book ("Book", author, 2020, nullptr);

	Books book2 = book; 
	Books book3 = std::move(book2);

	Books book4;
	book4 = book3;

	book4 = std::move(book3);


	std::cout << "Book Name: " << book.getBookName() << std::endl;
	std::cout << "Author Name: " << book.getAuthorName() << std::endl;
	std::cout << "Author Info: " << book.getAuthorInfo() << std::endl;
	std::cout << "Year: " << book.getYear() << std::endl;
	std::cout << "Is Available: " << book.getIsAvailable() << std::endl;
	std::cout << "Rent Book: " << book.RentBook() << std::endl;
	std::cout << "Give Back Book: " << book.GiveBackBook() << std::endl;

	delete author;
	std::cout << "Author Name: " << book.getAuthorName() << std::endl;
	std::cout << "Author Info: " << book.getAuthorInfo() << std::endl;

	std::cout << "************** BOOKS TEST ENDS **************" << std::endl;


	return 0;
}
#endif