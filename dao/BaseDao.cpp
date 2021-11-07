#include "BaseDao.h"
#include "../Config.h"
using namespace std;





BaseDao::BaseDao() {


	shared_ptr<Config>  config = Config::getInstance();
	host=config->config_map["host"];
	user = config->config_map["user"];
	password = config->config_map["password"];
	db = config->config_map["db"];
	port = atoi(config->config_map["port"].c_str());
}

BaseDao::~BaseDao() {
}




