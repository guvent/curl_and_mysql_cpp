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

void sql_error(sql::SQLException &err);

sql::Connection *sql_connect(char*,char*,char*,char*,char*);

void *sql_select_db(char*,sql::Connection*);

int sql_update_query(char*,sql::Connection*);

bool sql_execute_query(char*,sql::Connection*);

sql::ResultSet *sql_query(char*,sql::Connection*);

bool sql_fetch_all(std::string* ,char* ,sql::ResultSet*);


#endif /* SQL_HELPER_H */
