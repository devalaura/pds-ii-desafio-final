#ifndef ADMIN
#define ADMIN

#include "Pessoa.hpp"

class Admin : public Pessoa {
public:
    Admin(string nome, string cpf, string username, string senha);

    void set_admin(string username);
    void remove_admin(string username);
    void menu() override; // Implementação do menu para Admin
};

#endif
