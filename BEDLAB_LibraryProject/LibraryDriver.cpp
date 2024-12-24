#include "Global.h"

#ifdef TESTING
#include <iostream>

#include "Library.h"
#include "Books.h"
#include "Author.h"


int LibraryTest()
{
	std::cout << "************** LIBRARY TEST **************" << std::endl;
	// Constructor Testi
	Library library; 
	Library library1(10); // Manuel kapasite atama testi
	Author* author1 = new Author("J.K. Rowling", 33);
	Books* book1 = new Books("Harry Potter and the Philosopher's Stone", author1, 1997, &library);


	/*
	KITAP EKLEME OPERASYONU TEST EDILIYOR
	*/
	library.AddBook(book1);
	library.ListBooks(); // LISTBOOKS FONKSIYONU TEST EDILIYOR

	/*
	KITAP SILME OPERASYONU TEST EDILIYOR
	*/
	library.RemoveBook(0);
	library.ListBooks(); 
	
	Books* book2 = new Books("Harry Potter and the Chamber of Secrets", author1, 1998, &library);
	library.AddBook(book2);


	/*
	Move constructor test
	*/
	Library library2(std::move(library));
	library2.ListBooks();
	library.ListBooks();

	/*
	Move Assignment Test
	*/
	Library library3;
	library3 = std::move(library2);
	library3.ListBooks();
	library2.ListBooks();



	/*
	SENARYO 1
	KITAP SILINDIKTEN SONRA LISTBOOKS FONKSIYONU CALISIYOR MU ?
	*/

	delete book2;
	library.ListBooks();


	std::cout << "************** LIBRARY TEST ENDS **************" << std::endl;
	return 0;
}
#endif