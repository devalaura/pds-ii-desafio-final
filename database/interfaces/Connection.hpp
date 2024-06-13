#ifndef CONNECTION_MONGODB
#define CONNECTION_MONGODB

class Connection {
	public:
		mongocxx::collection connect();
};

#endif
