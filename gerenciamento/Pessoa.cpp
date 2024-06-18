#include "Pessoa.hpp"

// implementação do construtor 
// inicializa os atributos da classe com os valores passados como argumentos
Pessoa::Pessoa(string nome, string cpf, string username, string senha, int tipo)
    : nome(nome), cpf(cpf), username(username), senha(senha), tipo(tipo) {}

string Pessoa::getNome() {
    return nome;
}

string Pessoa::getCpf() {
    return cpf;
}
