#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <iostream>
#include "./interfaces/Connection.hpp"
#include "./../model/Livro.hpp"

Connection::Connection() 
    : _client(std::make_unique<mongocxx::client>(mongocxx::uri("mongodb+srv://public:sitemate-2024@pds-ii-desafio-final.tupphsk.mongodb.net/?retryWrites=true&w=majority&appName=pds-ii-desafio-final"))) 
{}

mongocxx::collection Connection::connect()
{

    try {
        mongocxx::database db = (*_client)["pds-ii"];
        mongocxx::collection coll = db["desafio-final"];

        return coll;
    }
    catch (const std::exception& e) {
        std::cerr << "Erro ao conectar ao servidor MongoDB: " << e.what() << std::endl;
    }

}
