#ifndef CONNECTION_MONGODB
#define CONNECTION_MONGODB

#include <mongocxx/collection.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/client.hpp>

class Connection {
	public:
		mongocxx::collection connect();
		Connection();

	private:
		mongocxx::instance _instance;
		std::unique_ptr<mongocxx::client> _client;
};

#endif
