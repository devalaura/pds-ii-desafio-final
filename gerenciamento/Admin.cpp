#include "Admin.hpp"
#include "./../model/Livro.hpp"
#include "./../database/interfaces/Repository.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <vector>

using namespace std;

// construtor 
Admin::Admin(string nome, string cpf, string username, string senha)
    : Pessoa(nome, cpf, username, senha, 1) // chama o construtor da classe Pessoa e define o tipo como 1 para indicar um administrador
{}

void Admin::set_admin(string username) {
    fstream arquivo("usuarios.txt", ios::in | ios::out);
    string linha;
    bool encontrado = false;
    string conteudo;

    // percorre todas as linhas do arquivo
    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string usuario, senha, nome, cpf, tipo;
        getline(ss, usuario, ',');
        getline(ss, senha, ',');
        getline(ss, nome, ',');
        getline(ss, cpf, ',');
        getline(ss, tipo, ',');

        // verifica se o nome do usuario está salvo no arquivo
        if (usuario == username) {
            encontrado = true;
            // modifica o tipo para setar o usuário como administrador
            linha = usuario + "," + senha + "," + nome + "," + cpf + ",1";
        }
        conteudo += linha + "\n";
    }

    arquivo.close(); // fechar o arquivo para reabrir em modo de escrita
    arquivo.open("usuarios.txt", ios::out | ios::trunc); // abrir em modo de escrita truncando o conteúdo anterior - apaga todo conteúdo que tiver no arquivo

    if (arquivo.is_open()) {
        arquivo << conteudo; // escreve o conteúdo modificado de volta no arquivo
        arquivo.close(); // fecha o arquivo
    } else { 
        cout << "Erro ao abrir o arquivo para escrita.\n";
    }

    if (encontrado) {
        cout << "Admin definido para o usuario.\n";
    } else {
        cout << "Usuario nao encontrado.\n";
    }
}


void Admin::remove_admin(string username) {
    fstream arquivo("usuarios.txt", ios::in | ios::out);
    string linha;
    bool encontrado = false;
    string conteudo;

    // percorre todas as linhas do arquivo
    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string usuario, senha, nome, cpf, tipo;
        getline(ss, usuario, ',');
        getline(ss, senha, ',');
        getline(ss, nome, ',');
        getline(ss, cpf, ',');
        getline(ss, tipo, ',');

        // verifica se o usuario está salvo no arquivo
        if (usuario == username) {
            encontrado = true;
            // altera o tipo para 0 = cliente
            linha = usuario + "," + senha + "," + nome + "," + cpf + ",0";
        }
        conteudo += linha + "\n";
    }

    arquivo.close(); // fecha o arquivo para reabrir em modo de escrita
    arquivo.open("usuarios.txt", ios::out | ios::trunc); // abre em modo de escrita truncando o conteúdo anterior

    if (arquivo.is_open()) {
        arquivo << conteudo; // Escrever o conteúdo modificado de volta no arquivo
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo para escrita.\n";
    }

    if (encontrado) {
        cout << "Administracao removida do usuario.\n";
    } else {
        cout << "Usuário não encontrado.\n";
    }
}


void Admin::menu() {
    int opcao;
    string input;

    Repository* repo = new Repository();

    // exibe o menu do administador até que o usuário decida deslogar da conta
    while (true) {
          cout    << "1. Adicionar livro\n"
                  << "2. Deletar livro\n"
                  << "3. Listar livros\n"
                  << "4. Atualizar livro\n"
                  << "5. Set Admin\n"
                  << "6. Remove Admin\n"
                  << "7. Deslogar\n"
                  << "Escolha: ";
        
        
        getline(cin, input);

        try {
            opcao = stoi(input); // tentativa de converter a string input para int usando a função stoi
        } catch (const   invalid_argument& e) { // lança uma excessão quando o argumento é invalido
                cout << "Opcao invalida. Tente novamente.\n"; // informa ao usuario que a opção foi invalidada
        }
        

        switch (opcao) {
            case 1: {
                Livro livro; // cria um objeto do tipo Livro
                
                // le e armazena as informações sobre o livro
                cout << "Insira as informacoes para adicionar um novo livro:\n";
                cout << "Titulo: ";
                getline(cin, input);
                livro.setTitulo(input);

                cout << "Autor: ";
                getline(cin, input);
                livro.setAutor(input);

                cout << "Ano de publicacao: ";
                getline(cin, input);
                livro.setAnoDePublicacao(stoi(input));

                cout << "ISBN: ";
                getline(cin, input);
                livro.setIsbn(stoi(input));

                // Salvar livro no banco de dados
                repo->insert_document(livro);

                cout << "Livro criado com sucesso!\n";
                break;
            }

            case 2: {
                // le o isbn do livro que o administrador deseja deletar
                cout << "Insira o ISBN do livro que deseja remover: ";
                getline(cin, input);
                int isbn_pesquisa = stoi(input);

                // Deleta livro do banco de dados
                repo->delete_book_by_isbn(isbn_pesquisa);

                cout << "Livro removido com sucesso!\n";
                break;
            }

            case 3: {
                cout << "\nLivros disponiveis na biblioteca:\n";

                // Busca todos os livros do banco de dados
                vector<Livro> livros = repo->get_all_books();
                for (Livro livro : livros) { // itera sobre todos os objetos do tipo Livro dentro do vetor livros
                    // exibe as informações de cada livro
                    cout << "Titulo: " << livro.getTitulo() << "\n";
                    cout << "Autor: " << livro.getAutor() << "\n";
                    cout << "Ano de publicacao: " << livro.getAnoDePublicacao() << "\n";
                    cout << "ISBN: " << livro.getIsbn() << "\n\n";
                }
                break;
            }

            case 4: {
                cout << "Atualizar livro\n";
                cout << "Insira o ISBN do livro que deseja atualizar: ";
                getline(cin, input);
                int isbn_pesquisa = stoi(input);
                Livro livro = repo->get_book_by_isbn(isbn_pesquisa); 
                
                // atualiza as informações do livro - não é possivel alterar o isbn tendo em vista que ele é único
                cout << "Insira as novas informacoes do livro:\n";
                cout << "Titulo: ";
                getline(cin, input);
                livro.setTitulo(input);

                cout << "Autor: ";
                getline(cin, input);
                livro.setAutor(input);

                cout << "Ano de publicacao: ";
                getline(cin, input);
                livro.setAnoDePublicacao(stoi(input));

                repo->update_book_by_isbn(livro);

                cout << "Livro alterado com sucesso!\n";
                break;
            }

            case 5: {
                string usuario;
                cout << "Digite o username do usuario a ser setado como admin: ";
                getline(cin, usuario);
                set_admin(usuario);
                break;
            }

            case 6: {
                string usuario;
                cout << "Digite o username do admin a ter sua administracao removida: ";
                getline(cin, usuario);
                remove_admin(usuario);
                break;
            }

            case 7:
                cout << "Deslogando...\n";
                return;

            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }
    }
}
