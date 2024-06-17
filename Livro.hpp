#ifndef LIVRO_HPP
#define LIVRO_HPP

#include <iostream>
#include <string>

using std::string;

class Livro{
    private:
        string titulo;  
        string autor;
        int ano_de_publicacao;
        int isbn; //número de identificação único para cada livro cadastrado

    public:
        Livro(); //construtor
        // Livro(string titulo, string autor, int ano_de_publicacao, int isbn);

        string getTitulo();
        string getAutor();
        int getAnoDePublicacao();
        int getIsbn();

        void setTitulo(string titulo);
        void setAutor(string autor);
        void setAnoDePublicacao(int ano_de_publicacao);
        void setIsbn(int isbn);

};

#endif