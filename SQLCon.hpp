#ifndef SQLCON_HPP
#define SQLCON_HPP

#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include "FFT.hpp"
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace std;

class SQLCon{
private:
	sql::Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	sql::ResultSet *res;
	sql::PreparedStatement *pstmt;
public:
	SQLCon(string ip,string user,string password,string schema);
	~SQLCon();
	void sql_send(string table,string id);
	void sql_send_fft(string table,string id,string id2);
	void sql_print(string table, string id);
	void create_table(string table, string id, string type);
	void create_table(string table, string id, string type,string id2, string type2);

};

#endif