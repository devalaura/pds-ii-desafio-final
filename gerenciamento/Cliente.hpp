#ifndef CLIENTE
#define CLIENTE

#include "Pessoa.hpp"

// a classe cliente herda o classe pessoa
class Cliente : public Pessoa {
    public:
        Cliente(string nome, string cpf, string username, string senha); // construtor

        void listarLivros();
        void pegarLivro(int isbn);
        void devolverLivro(int isbn);
        void menu();
};

#endif 
