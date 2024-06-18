#ifndef LIVRO
#define LIVRO

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

        string getTitulo() const;
        string getAutor() const;
        int getAnoDePublicacao() const;
        int getIsbn() const;

        void setTitulo(string titulo);
        void setAutor(string autor);
        void setAnoDePublicacao(int ano_de_publicacao);
        void setIsbn(int isbn);
};

#endif