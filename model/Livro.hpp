#ifndef LIVRO
#define LIVRO

#include <iostream>
#include <string>
#include <bsoncxx/document/view.hpp>
#include <bsoncxx/types.hpp>

using std::string;

class Livro{
    private:
        string titulo;  
        string autor;
        int ano_de_publicacao;
        int isbn; // número de identificação único para cada livro cadastrado

    public:
        Livro(); // construtor

        // funções para resgatar o valor salvo nas variaveis
        string getTitulo() const;
        string getAutor() const;
        int getAnoDePublicacao() const;
        int getIsbn() const;

        // funções para atribuir um valor as variaveis
        void setTitulo(string titulo);
        void setAutor(string autor);
        void setAnoDePublicacao(int ano_de_publicacao);
        void setIsbn(int isbn);

        static Livro from_bson(bsoncxx::document::view doc) {
            Livro livro;
            livro.titulo = doc["titulo"].get_utf8().value;
            livro.autor = doc["autor"].get_utf8().value;
            livro.isbn = doc["isbn"].get_int32();
            livro.ano_de_publicacao = doc["ano_publicacao"].get_int32();

            return livro;
        }
};

#endif