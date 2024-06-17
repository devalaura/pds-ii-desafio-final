#include <iostream>
#include <string>
#include "Livro.hpp"

using namespace std;

//construtor padrão -> inicializar os atributos 
Livro::Livro(){
    titulo = "";
    autor = "";
    ano_de_publicacao = 0;
    isbn = 0;
}

//implementação do construtor
/* Livro::Livro(string titulo, string autor, int ano_de_publicacao, int isbn){
    this->titulo = titulo;
    this->autor = autor;
    this->ano_de_publicacao = ano_de_publicacao;
    this->isbn = isbn;
} */

string Livro::getTitulo(){
    return titulo;
}

string Livro::getAutor(){
    return autor;
}

int Livro::getAnoDePublicacao(){
    return ano_de_publicacao;
}

int Livro::getIsbn(){
    return isbn;
}

void Livro::setTitulo(string titulo){
    this->titulo = titulo;
}

void Livro::setAutor(string autor){
    this->autor = autor;
}

void Livro::setAnoDePublicacao(int ano_de_publicacao){
    this->ano_de_publicacao = ano_de_publicacao;
}

void Livro::setIsbn(int isbn){
    this->isbn = isbn;
}

