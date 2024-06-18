#include "./interfaces/Repository.hpp"
#include "./interfaces/Connection.hpp"
#include "./../model/Livro.hpp"

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

void Repository::insert_document(Livro livro)
{
	try {
		bsoncxx::builder::stream::document document{};
		document << "titulo" << livro.getTitulo()
			<< "autor" << livro.getAutor()
			<< "ano_publicacao" << livro.getAnoDePublicacao()
			<< "isbn" << livro.getIsbn()
			<< "disponivel" << livro.getDisponivel();

		this->Collection.insert_one(document.view());
	}
	catch (const std::exception& e) {
		std::cerr << "Erro ao inserir título na base de dados: " << e.what() << std::endl;
	}
}

vector<Livro> Repository::get_all_books()
{
	vector<Livro> livros;

	try {
		auto cursor = this->Collection.find({});
	
		for (auto&& doc : cursor) {
			Livro livro = Livro::from_bson(doc);
			livros.push_back(livro);
		}

		return livros;
	}
	catch (const std::exception& e) {
		std::cerr << "Erro ao buscar todos os títulos da base de dados: " << e.what() << std::endl;
		return livros;
	}
}

Livro Repository::get_book_by_isbn(int isbn)
{
	Livro livro;

	try {
		bsoncxx::stdx::optional<bsoncxx::document::value> cursor = this->Collection.find_one(bsoncxx::builder::stream::document{} << "isbn" << isbn << bsoncxx::builder::stream::finalize);

		if (!cursor) return livro;

		livro = Livro::from_bson(*cursor);

		return livro;
	}
	catch (const std::exception& e) {
		std::cerr << "Erro ao buscar título ISBN = " << isbn << " na base de dados: " << e.what() << std::endl;
		return livro;
	}
}

vector<Livro> Repository::get_available_books()
{
	vector<Livro> livros;

	try {
		bsoncxx::builder::stream::document filter_builder;
		filter_builder << "disponivel" << 0;
		auto filter = filter_builder.view();
		auto cursor = this->Collection.find(filter);

		for (auto&& doc : cursor) {
			Livro livro = Livro::from_bson(doc);
			livros.push_back(livro);
		}

		return livros;
	}
	catch (const std::exception& e) {
		std::cerr << "Erro ao buscar títulos disponíveis na base de dados: " << e.what() << std::endl;
		return livros;
	}
}

vector<Livro> Repository::get_unavailable_books()
{
	vector<Livro> livros;

	try {
		bsoncxx::builder::stream::document filter_builder;
		filter_builder << "disponivel" << 1;
		auto filter = filter_builder.view();
		auto cursor = this->Collection.find(filter);

		for (auto&& doc : cursor) {
			Livro livro = Livro::from_bson(doc);
			livros.push_back(livro);
		}

		return livros;
	}
	catch (const std::exception& e) {
		std::cerr << "Erro ao buscar títulos indisponíveis na base de dados: " << e.what() << std::endl;
		return livros;
	}
}

Livro Repository::update_book_by_isbn(Livro livro)
{
	Livro livroUpd;

	try {
		this->Collection.update_one(
			bsoncxx::builder::stream::document{} << "isbn" << livro.getIsbn() << bsoncxx::builder::stream::finalize,
			bsoncxx::builder::stream::document{} << "$set"
			<< bsoncxx::builder::stream::open_document
			<< "titulo" << livro.getTitulo()
			<< "autor" << livro.getAutor()
			<< "ano_publicacao" << livro.getAnoDePublicacao()
			<< "disponivel" << livro.getDisponivel()
			<< bsoncxx::builder::stream::close_document
			<< bsoncxx::builder::stream::finalize);

		livroUpd = this->get_book_by_isbn(livro.getIsbn());
		
		return livroUpd;
	}
	catch (const std::exception& e) {
		std::cerr << "Erro ao atualizar título ISBN = " << livro.getIsbn() << " na base de dados: " << e.what() << std::endl;
		return livroUpd;
	}
}

void Repository::delete_book_by_isbn(int isbn)
{
	try {
		this->Collection.delete_one(
			bsoncxx::builder::stream::document{} << "isbn" << isbn << bsoncxx::builder::stream::finalize);
	}
	catch (const std::exception& e) {
		std::cerr << "Erro ao deletar título ISBN = " << isbn << " da base de dados: " << e.what() << std::endl;
	}
}
