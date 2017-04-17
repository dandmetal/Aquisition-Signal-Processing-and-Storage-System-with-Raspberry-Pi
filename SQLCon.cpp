#include  "SQLCon.hpp"

SQLCon::SQLCon(string ip,string user,string password,string schema){
	try{
		string ip_port="tcp://"+ ip;
		driver=get_driver_instance();
		con=driver->connect(ip_port, user, password);
		con->setSchema(schema);
		cout << "Conexao estabelecida com o banco de dados" << endl;
	}catch (sql::SQLException &e) {
		cout << "Nao foi possivel se conectar com o servidor" << endl;
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode()<<endl;
	}
}

void SQLCon::sql_send(string table,string id){
	double temp;
	try{
	string prepare="INSERT INTO "+table+"("+id+") "+"VALUES (?)";
	pstmt = con->prepareStatement(prepare);
	ifstream rfile("file.bin",ios::out);
	if (rfile.is_open()){
		while(rfile >>temp){
			pstmt->setDouble(1,temp);
			pstmt->executeUpdate();
		}
	rfile.close();
	remove("file.bin");
	cout <<"Dados enviados com sucesso"<<endl;
	}
	}catch (sql::SQLException &e) {
		cout << "Ocorreu um erro ao enviar os dados ao servidor" << endl;
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode()<<endl;
	}
}

void SQLCon::sql_send_fft(string table,string id,string id2){
	Complex temp;
	try{
	string prepare="INSERT INTO "+table+"("+id+","+id2+ ") "+"VALUES (?,?)";
	pstmt = con->prepareStatement(prepare);
	ifstream rfile("file.bin",ios::out);
	if (rfile.is_open()){
		while(rfile >>temp){
			pstmt->setDouble(1,temp.real());
			pstmt->setDouble(2,temp.imag());
			pstmt->executeUpdate();
		}
	}
	rfile.close();
	remove("file.bin");
	cout <<"Dados enviados com sucesso"<<endl;
	}catch (sql::SQLException &e) {
		cout << "Ocorreu um erro ao enviar os dados ao servidor" << endl;
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode()<<endl;
	}
}

void SQLCon::sql_print(string table, string id){
	try{
	string print="SELECT "+ id +" FROM "+table;
	pstmt = con->prepareStatement(print);
	res = pstmt->executeQuery();
	while (res->next())
		cout << res->getDouble(id) << endl;
	}catch (sql::SQLException &e) {
		cout << "Ocorreu um erro ao receber os dados do servidor" << endl;
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode()<<endl;
	}
}

void SQLCon::create_table(string table, string id, string type){
	try{
	stmt=con->createStatement();
	string drop="DROP TABLE IF EXISTS " + table;
	string create ="CREATE TABLE " + table+"("+ id+" "+ type+")";
	stmt->execute(drop);
	stmt->execute(create);
	}catch (sql::SQLException &e) {
		cout << "Ocorreu um erro ao criar uma tabela" << endl;
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode()<<endl;
	}
}

void SQLCon::create_table(string table, string id, string type,string id2, string type2){
	try{
	stmt=con->createStatement();
	string drop="DROP TABLE IF EXISTS " + table;
	string create ="CREATE TABLE " + table+"("+ id+" "+ type+","+"\n"+ id2 +" "+type2+ ")";
	stmt->execute(drop);
	stmt->execute(create);
	}catch (sql::SQLException &e) {
		cout << "Ocorreu um erro ao criar uma tabela" << endl;
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode()<<endl;
	}
}

SQLCon::~SQLCon(){
	delete con;
	delete stmt;
	delete res;
	delete pstmt;
}


