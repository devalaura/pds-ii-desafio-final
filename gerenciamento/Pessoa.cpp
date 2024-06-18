#include "Pessoa.hpp"

Pessoa::Pessoa(string nome, string cpf, string username, string senha, int tipo)
    : nome(nome), cpf(cpf), username(username), senha(senha), tipo(tipo) 
{
    this->repo = new Repository();
}

string Pessoa::getNome() {
    return nome;
}

string Pessoa::getCpf() {
    return cpf;
}
