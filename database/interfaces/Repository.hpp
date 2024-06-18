#ifndef REPOSITORY
#define REPOSITORY

#include "./../../model/Livro.hpp"
#include <mongocxx/collection.hpp>
#include <vector>

using std::vector;

class Repository {
	public:
		Repository();
		~Repository();
		void insert_document(Livro book);
		vector<Livro> get_all_books();
		Livro get_book_by_isbn(int isbn);
		Livro update_book_by_isbn(Livro book);
		void delete_book_by_isbn(int isbn);

	private:
		mongocxx::collection Collection;
};

#endif
