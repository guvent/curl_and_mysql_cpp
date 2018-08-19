/* 
 * File:   sql_helper.h
 * Author: guven
 *
 * Created on 17 Ağustos 2018 Cuma, 00:25
 */

#include <cstring>

#include "includes.h"

#ifndef SQL_HELPER_H
#define SQL_HELPER_H

/*
 *  sql hatalarini ekrana yazdirir...
 */
void sql_error(sql::SQLException &err)
{
    cout << "HATA : " << err.what() << endl;
    cout << "MySQL Hata Kodu : " << err.getErrorCode();
    cout << " - SQLState: " << err.getSQLState() << endl;
}

/*
 * sql baglantisi olusturur..
 * method sql::Connection nesnesi cevirir...
 * tcpport parametresi verilmezse 3306 varsayilir
 */
sql::Connection *sql_connect(char *host,char *username,char *password,char *database,char *tcpport="3306")
{
    
    std::string tcp_s = "tcp://";
    std::string host_s = host;
    std::string ddot_s = ":";
    std::string port_s = tcpport;
    
    std::string hosturl = tcp_s + host_s + ddot_s + port_s;
    
    
    sql::Driver *driver;
    sql::Connection *connect;

    try
    {
        driver = get_driver_instance();

        connect = driver->connect(hosturl,username,password);

        connect->setSchema(database);

    }
    catch(sql::SQLException &err)
    {
        sql_error(err);
    }

    return connect;
}

/*
 * veri tabani belirlemek veya farkli bir veri tabanina gecis icin kullanilir..
 * baglanirken parametrede zorunlu olarak bir veri tabani belirlemis oluyorsunuz..
 */
void *sql_select_db(char *database,sql::Connection *connect)
{

    try
    {
        connect->setSchema(database);

    }
    catch(sql::SQLException &err)
    {
          sql_error(err);  
    }
        
}

/*
 * tabloda veri guncellemek icin ideal method guncellenen kayit sayisini geri cevirir...
 * coklu kayit ekleyebilir INSERT INTO (f1,f2,f3) VALUES (1,2,3), (4,5,6); gibi...
 */
int sql_update_query(char *query,sql::Connection *connect)
{
    sql::Statement *statment;

    int updated = 0;

    try
    {
        statment = connect->createStatement();

        updated = statment->executeUpdate(query);

    }
    catch(sql::SQLException &err)
    {
        sql_error(err);
    }

    return updated;
}

/*
 * tabloya kayit eklemek icin ideal method basarili ise true cevirir...
 * coklu kayit ekleyebilir INSERT INTO (f1,f2,f3) VALUES (1,2,3), (4,5,6); gibi...
 */
bool sql_execute_query(char *query,sql::Connection *connect)
{
    sql::Statement *statment;

    bool executed = 0;

    try
    {
        statment = connect->createStatement();

        executed = statment->executeUpdate(query);

    }
    catch(sql::SQLException &err)
    {
        sql_error(err);
    }

    return executed;
}

/*
 * tablodan kayitlari okumak icin kullanilir method kayitlari listelebilmek icin ResultSet nesnesi cevirir...
 * tabloda kayit ekleme veya guncelleme yapmaz...
 */
sql::ResultSet *sql_query(char *query,sql::Connection *connect)
{
    sql::Statement *statment;
    sql::ResultSet *resultset;

    try
    {
        statment = connect->createStatement();

        resultset = statment->executeQuery(query);

    }
    catch(sql::SQLException &err)
    {
        sql_error(err);
    }

    return resultset;
}

/*
 * tablodan kayitlari okurken alternatif olarak kullanilir methodu while dongusune kosul
 * olarak yazin kayit oldugu surece true cevirerek dongunun calismasini saglayacaktir.
 * ayrica okunan kayitlari ilk parametreye referans olarak bir degisken verin ayni degiskene
 * string olarak yazacaktir, field parametresine donmesini istediginiz sutunu yazmaniz yeterlidir..
 */
bool sql_fetch_all(std::string* results,char* field,sql::ResultSet *resultset)
{
    string read;
    
    bool is_avail;


    try
    {
        is_avail = resultset->next();
        if(is_avail)
        {
            read = resultset->getString(field);
        }

    }
    catch(sql::SQLException &err)
    {
        sql_error(err);  
    }

    *results = read;

    return is_avail;
}

#endif /* SQL_HELPER_H */
