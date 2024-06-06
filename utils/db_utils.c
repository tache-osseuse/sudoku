#include "db_utils.h"

bool storeEvent(const char* event_text){
    const char* create_sql = "CREATE TABLE IF NOT EXISTS Events("
                                   "id          INTEGER NOT NULL,"
                                   "event       TEXT NOT NULL,"
                                   "datetime    TEXT,"
                                   "PRIMARY KEY(id));";
    const char* insert_sql = "INSERT INTO Events(event, datetime)"
                             "VALUES (?1, ?2)";
    sqlite3_stmt* insert_stmt;
    sqlite3* db = NULL;
    int rt = 0;
    if ((rt = sqlite3_initialize()) != SQLITE_OK){
        printf("Failed to initialize library!\n[code]> %d\n", rt);
        return false;
    }
    if ((rt = sqlite3_open_v2("records.db", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL)) != SQLITE_OK){
        printf("Failed to open connection!\n[code]> %d\n", rt);
        return false;
    }
    if ((rt = sqlite3_exec(db, create_sql, NULL, NULL, NULL)) != SQLITE_OK){
        printf("Failed to open/create table!\n[code]> %d\n", rt);
        sqlite3_close(db);
        return false;
    }
    if ((rt = sqlite3_prepare_v2(db, insert_sql, -1, &insert_stmt, 0)) != SQLITE_OK){
        printf("Failed to prepare insert statement!\n[code]> %d\n", rt);
        sqlite3_close(db);
        return false;
    }
    sqlite3_bind_text(insert_stmt, 1, event_text, -1, SQLITE_STATIC);
    sqlite3_bind_text(insert_stmt, 2, getCurrentTime(), -1, SQLITE_STATIC);
    if ((rt = sqlite3_step(insert_stmt)) != SQLITE_DONE){
        printf("Failed to insert data into table!\n[code]> %d\n", rt);
        sqlite3_close(db);
        return false;
    }
    sqlite3_finalize(insert_stmt);
    if (db != NULL){
        sqlite3_close(db);
    }
    sqlite3_shutdown();
    return true;
}
