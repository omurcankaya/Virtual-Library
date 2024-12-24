#include "Global.h"

#ifdef TESTING
#include <iostream>
#include "AuthorDriver.h"
#include "BooksDriver.h"
#include "LibraryDriver.h"
#include "RentedBookSDriver.h"

int main()
{
	AuthorTest();
	BooksTest();
	LibraryTest();
	RentedBooksTest();
	return 0;
}
#endif