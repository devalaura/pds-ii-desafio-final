#ifndef CLIENTE
#define CLIENTE

#include "Pessoa.hpp"

// a classe cliente herda o classe pessoa
class Cliente : public Pessoa {
    public:
        Cliente(string nome, string cpf, string username, string senha); // construtor

        void menu() override; // sobrescrita do método menu() presente na classe Pessoa
};

#endif 
