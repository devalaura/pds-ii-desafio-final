#ifndef CONNECTION_MONGODB
#define CONNECTION_MONGODB

#include <mongocxx/collection.hpp>

class Connection {
	public:
		mongocxx::collection connect();
};

#endif CONNECTION_MONGODB
