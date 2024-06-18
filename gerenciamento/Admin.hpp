#ifndef ADMIN
#define ADMIN

#include "Pessoa.hpp"

class Admin : public Pessoa {
    public:
        Admin(string nome, string cpf, string username, string senha); // construtor

        void set_admin(string username); // método para definir um usuario como administrador
        void remove_admin(string username); // método para remover um usuario como administrador
        void menu() override; // Implementação do menu para Admin - sobrescrita do método da classe Pessoa
    };

#endif
