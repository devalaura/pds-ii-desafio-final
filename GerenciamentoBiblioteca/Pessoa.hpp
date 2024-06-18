#ifndef PESSOA
#define PESSOA

#include <string>
using namespace std;

class Pessoa {
protected:
    string nome;
    string cpf;
    string username;
    string senha;
    int tipo; // 0 para Cliente, 1 para Admin
public:
    Pessoa(string nome, string cpf, string username, string senha, int tipo);
    virtual ~Pessoa() {}

    virtual void menu() = 0; // Método virtual para o menu

    string getNome();
    string getCpf();
};

#endif