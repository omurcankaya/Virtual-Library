#include "Global.h"
#ifdef TESTING
#include "Author.h"
int AuthorTest() {

	std::cout << "************** AUTHOR TEST **************" << std::endl;
	Author author;
	author.setName("Author");
	author.setAge(20);

	author.AuthorDetails();

	Books b("Fareler ve Insanlar", &author, 1937, nullptr);
	author.RemoveBook(&b);
	author.AddBook(&b);

	Author author2("Author3", 30);

	Author author3 = std::move(author2);
	
	Author author4;
	author4 = std::move(author3);

	std::cout << "************** AUTHOR TEST ENDS **************" << std::endl;

	return 0;
}

#endif