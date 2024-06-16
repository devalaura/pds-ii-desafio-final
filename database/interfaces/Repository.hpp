#ifndef REPOSITORY
#define REPOSITORY

#include "./../../model/Book.hpp"
#include <mongocxx/collection.hpp>
#include <vector>
#include <string>

using std::vector;

class Repository {
	public:
		Repository();
		~Repository();
		void insert_document(Book* book);
		vector<Book*> get_all_books();
		Book* get_book_by_isbn(std::string isbn);
		Book* update_book_by_isbn(std::string isbn, Book* book);
		void delete_book_by_isbn(std::string isbn);

	private:
		mongocxx::collection Collection;
};

#endif REPOSITORY
