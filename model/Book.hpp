#ifndef BOOK
#define BOOK 

#include <string>
#include <bsoncxx/document/view.hpp>
#include <bsoncxx/types.hpp>

class Book {
	public:
		std::string titulo;
		std::string autor;
		std::string isbn;
		int ano_publicacao;

		Book(std::string titulo, std::string autor, std::string isbn, int ano_publicacao);
		~Book();

		static Book* from_bson(bsoncxx::document::view doc) {
			Book* book = new Book();
			book->titulo = doc["titulo"].get_utf8().value;
			book->autor = doc["autor"].get_utf8().value;
			book->isbn = doc["isbn"].get_utf8().value;
			book->ano_publicacao = doc["ano_publicacao"].get_int32();

			return book;
		}

	private:
		Book() {};
};

#endif BOOK
