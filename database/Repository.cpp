#include "./interfaces/Repository.hpp"
#include "./interfaces/Connection.hpp"

#include <bsoncxx/builder/stream/document.hpp>
#include <iostream>

Repository::Repository()
{
	Connection* conn = new Connection();
	this->Collection = conn->connect();
}

Repository::~Repository()
{
	std::cout << "Repository\n";
}

void Repository::insert_document(Book* book)
{
	try {
		bsoncxx::builder::stream::document document{};
		document << "titulo" << book->titulo
			<< "autor" << book->autor
			<< "ano_publicacao" << book->ano_publicacao
			<< "isbn" << book->isbn
			<< bsoncxx::builder::stream::finalize;

		this->Collection.insert_one(document.view());
	}
	catch (const std::exception& e) {
		std::cerr << "Erro ao inserir título na base de dados: " << e.what() << std::endl;
	}
}

vector<Book*> Repository::get_all_books()
{
	try {
		vector<Book*> books;

		auto cursor = this->Collection.find({});
	
		for (auto&& doc : cursor) {
			Book* book = Book::from_bson(doc);
			books.push_back(book);
		}

		return books;
	}
	catch (const std::exception& e) {
		std::cerr << "Erro ao buscar todos os títulos da base de dados: " << e.what() << std::endl;
	}
}

Book* Repository::get_book_by_isbn(std::string isbn)
{
	try {
		bsoncxx::stdx::optional<bsoncxx::document::value> cursor = this->Collection.find_one(bsoncxx::builder::stream::document{} << "isbn" << isbn << bsoncxx::builder::stream::finalize);

		if (!cursor) return nullptr;

		Book* book = Book::from_bson(*cursor);

		return book;
	}
	catch (const std::exception& e) {
		std::cerr << "Erro ao buscar título ISBN = " << isbn << " na base de dados: " << e.what() << std::endl;
	}
}

Book* Repository::update_book_by_isbn(std::string isbn, Book* book)
{
	try {
		this->Collection.update_one(
			bsoncxx::builder::stream::document{} << "isbn" << isbn << bsoncxx::builder::stream::finalize,
			bsoncxx::builder::stream::document{} << "$set"
			<< bsoncxx::builder::stream::open_document
			<< "titulo" << book->titulo
			<< "autor" << book->autor
			<< "ano_publicacao" << book->ano_publicacao
			<< bsoncxx::builder::stream::close_document
			<< bsoncxx::builder::stream::finalize);

		Book* book = this->get_book_by_isbn(isbn);
		
		return book;
	}
	catch (const std::exception& e) {
		std::cerr << "Erro ao atualizar título ISBN = " << isbn << " na base de dados: " << e.what() << std::endl;
	}
}

void Repository::delete_book_by_isbn(std::string isbn)
{
	try {
		this->Collection.delete_one(
			bsoncxx::builder::stream::document{} << "isbn" << isbn << bsoncxx::builder::stream::finalize);
	}
	catch (const std::exception& e) {
		std::cerr << "Erro ao deletar título ISBN = " << isbn << " da base de dados: " << e.what() << std::endl;
	}
}
