#ifndef CLIENTE
#define CLIENTE

#include "Pessoa.hpp"

class Cliente : public Pessoa {
public:
    Cliente(string nome, string cpf, string username, string senha);

    void menu() override; 
};

#endif 
