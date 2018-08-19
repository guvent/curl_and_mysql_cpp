/* 
 * File:   main.cpp
 * Author: guven
 *
 * Created on 16 Ağustos 2018 Perşembe, 13:33
 * 
 * Derlemek icin : gcc main.cpp -o main  -lcurl -lmysqlcppconn
 * 
 * Calistirmak icin : ./main
 * 
 */


#include "curl_methods.h"
#include "sql_helper.h"

void insert_record();

void test_curl();


int main(int argc, char** argv) {

    //insert_record();
    
    //get_table1();
    
    //get_table2();
    
    test_curl();
}

void insert_record()
{
    sql::Connection *connect;
    
    int result;
    
    connect = sql_connect("localhost","root","","testdb");
    
    char* command = "INSERT INTO testtable (field1,field2,field3) VALUES ('yeni kayıt','2017-09-08',60), ('yeni kayıt','2017-09-08',60);";
    
    result = sql_update_query(command,connect);
    
    cout << result << endl;
    
}

void get_table1()
{
    sql::Connection *connect;
    sql::ResultSet *resultset;
    
    connect = sql_connect("localhost","root","","testdb");
        
    resultset = sql_query("SELECT * FROM testtable",connect);
    
    while(resultset->next())
    {
        cout << resultset->getString("field1") << endl;
    }
}

void get_table2()
{
    sql::Connection *connect;
    sql::ResultSet *resultset;
    
    connect = sql_connect("localhost","root","","testdb");
    
    resultset = sql_query("SELECT * FROM testtable",connect);
    
    std::string results;
    
    while(sql_fetch_all(&results,"field1",resultset))
    {
        cout << results << endl;
    }
}

void test_curl()
{
    string response_str;

    char *url = "https://api.github.com/users/quvven";

    char *postdata = ""; //"var1=deneme";

    response_str = send_curl(url , postdata);

    cout << response_str << endl;

    
}
