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
        Pessoa(string nome, string cpf, string username, string senha, int tipo); // construtor
        virtual ~Pessoa() {}

        virtual void menu() = 0; // Método virtual para o menu - pode ser sobrescrito nas classes derivadas (Admin e Cliente) 

        // funções para resgatar valor salvo nas variaveis
        string getNome();
        string getCpf();
};

#endif
