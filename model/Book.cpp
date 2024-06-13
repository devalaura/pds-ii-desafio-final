#include "Book.hpp"
#include <iostream>

Book::Book(std::string titulo, std::string autor, std::string isbn, int ano_publicacao)
: titulo(titulo), autor(autor), isbn(isbn), ano_publicacao(ano_publicacao) { }

Book::~Book()
{
	std::cout << "Book\n";
}
