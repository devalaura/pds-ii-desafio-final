#include "Cliente.hpp"
#include "./../model/Livro.hpp"
#include <iostream>
#include <limits>
#include "./../database/interfaces/Repository.hpp"

// implementação do construtor
Cliente::Cliente(string nome, string cpf, string username, string senha)
    : Pessoa(nome, cpf, username, senha, 0) {} // inicializa os atributos herdados da classe Pessoa
    // o tipo é definido como 0 para indicar um cliente

// implementação do menu do cliente - operações de alugar e devolver livro
void Cliente::menu() {
    int opcao;
    string input;

    Repository* repo = new Repository(); // objeto criado para acessar dados dos livros 
    
    // o menu roda até que o cliente selecione a opção de deslogar 
    while (true) {
        cout << "1. Pegar Livro\n2. Devolver Livro\n3. Listar Livros\n4. Deslogar\nEscolha: ";
        while (true) {
            getline(cin, input); // o getline é utilizado para ler uma string
            
            try {
                opcao = stoi(input); // o stoi converte a string para um numero inteiro
                break;
            } catch (const invalid_argument& e) {
                cout << "Opcao invalida. Tente novamente.\n";
            }
        }

        vector<Livro> livros; // vetor de livros alocado dinamicamente 

        switch (opcao) {
            case 1:
                cout << "Pegar Livro \n";
                break;

            case 2:
                cout << "Devolver Livro \n";
                break;

            case 3:
                cout << "Listar Livros\n";
                livros = repo->get_all_books();

                for (Livro livro : livros) { // iteração sobre cada elemento do tipo Livro dentro do vetor livros
                    // exibe as informações de cada livro
                    cout << "Titulo: " << livro.getTitulo() << "\n";
                    cout << "Autor: " << livro.getAutor() << "\n";
                    cout << "Ano de publicacao: " << livro.getAnoDePublicacao() << "\n";
                    cout << "ISBN: " << livro.getIsbn() << "\n\n";
                }
                break;

            case 4:
                cout << "Deslogando...\n";
                return;

            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }
    }
}