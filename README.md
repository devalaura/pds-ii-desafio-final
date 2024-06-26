## Definições do projeto
1. Requisitos Funcionais
    - CRUD de Livros:
        - Inserção de Livro:
            - O sistema deve permitir a inserção de novos livros.
            - Os dados de um livro incluem: título, autor, ano de publicação e ISBN.
            - Caso sejam incluídos dados faltantes deve-se retornar uma mensagem de erro ao usuário.
        - Consulta de Livros:
            - O sistema deve permitir a consulta de livros.
            - Deve ser possível listar todos os livros e pesquisar pelo ISBN.
            - Caso seja informado um ISBN errado deve-se retornar uma mensagem de erro ao usuário.
        - Atualização de Livro:
            - O sistema deve permitir a atualização dos dados de um livro pelo ISBN.
            - Caso seja informado um ISBN errado deve-se retornar uma mensagem de erro ao usuário.
        - Deleção de Livro:
            - O sistema deve permitir a deleção de um livro pelo ISBN.
            - Caso seja informado um ISBN errado deve-se retornar uma mensagem de erro ao usuário.

    - Conexão com Banco de Dados: o sistema deve conectar-se a um banco de dados MongoDB para armazenamento e recuperação de informações dos livros.

    - Interação via Console: 
        - O sistema deve exibir um menu no console para o usuário selecionar a operação que o deseja efetuar.
        - O sistema deve permitir a interação do usuário através do console para listar livros.
        - O sistema deve permitir a interação do usuário através do console para criar livros.
        - O sistema deve permitir a interação do usuário através do console para atualizar livros.
        - O sistema deve permitir a interação do usuário através do console para deletar livros.
    
    - Testes de unidade: o sistema deve ter suas classes cobertas por testes de unidade.

2. Requisitos Não-Funcionais
    - Desempenho:
        - As operações de CRUD devem ser realizadas de forma eficiente.
        - O sistema deve responder rapidamente às consultas de usuário.
    - Confiabilidade:
        - O sistema deve tratar erros de conexão com o banco de dados de forma adequada.
        - O sistema deve garantir a integridade dos dados.
    - Usabilidade:
        - A interface de console deve ser intuitiva e fácil de usar.
        - O sistema deve fornecer mensagens de erro e sucesso claras.

## Instruções para compilação e execução

1. Pre-requisitos:
    - CMake -> [Tutorial de instalação no Windows](https://terminalroot.com.br/2023/03/como-instalar-o-cmake-no-windows.html)
    - mongo-cxx-driver -> [Tutorial de instalação](https://www.mongodb.com/docs/languages/cpp/cpp-driver/current/installation/)

2. Configure corretamente as variáveis do arquivo `CMakeLists.txt`:
    ```
    set(CMAKE_TOOLCHAIN_FILE "C:/caminho/para/seu/vcpkg/scripts/buildsystems/vcpkg.cmake")
    set(CMAKE_PREFIX_PATH "C:/caminho/para/seu/vcpkg/installed/x64-windows/share")
    ```

3. Compilação/build:
    ```
    // no diretório raiz do projeto

    $ mkdir build

    $ cd build

    $ cmake ..

    $ cmake --build .
    ```

4. O arquivo executável `main.exe` estará em `build > Debug`.