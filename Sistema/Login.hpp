#ifndef LOGIN
#define LOGIN

#include <string>

void cadastrar(std::string nome, std::string cpf, std::string username, std::string senha);
bool verificar_login(std::string username, std::string senha, std::string &nome, std::string &cpf, int &tipo);
void criar_admin_padrao();

#endif
