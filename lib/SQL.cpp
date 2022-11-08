#include <iostream>
#include <vector>
#include <string>

#include "../include/SQL.h"

using namespace std;

// Constructor
SQL::SQL(){

    // Attemp to connect to local database
    rc = sqlite3_open("test.db", &db);

    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        this->~SQL();
        exit(-1);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
}

// Destructor
SQL::~SQL() {

    // Closes connection to local database
    sqlite3_close(db);

    // dealloc private pointer variables
    if (db != nullptr) {free(db);}
    if (zErrMsg != nullptr) {delete zErrMsg;}
}

// Create a callback function  
int callback(void *NotUsed, int argc, char **argv, char **azColName){

    // int argc: holds the number of results
    // (array) azColName: holds each column returned
    // (array) argv: holds each value

    for(int i = 0; i < argc; i++) {
        
        // Show column name, value, and newline
        cout << azColName[i] << ": " << argv[i] << endl;
    }

    // Insert a newline
    cout << endl;

    // Return successful
    return 0;
}

//Ill create a separate SQL method called smth like bool userExist() 

// create type of SQL table in database based on passed in tableName
void SQL::_createTable(string tableName) {

    if (tableName == "test") {

        //SQL language: Create Table with passed in tableName
        string sql = "CREATE TABLE IF NOT EXISTS test"
                    "("
                    "name TEXT PRIMARY KEY NOT NULL,"
                    "age INT NOT NULL"
                    ");";
        
        // Execute SQL Statement
         rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);
    }
}

void SQL::_insertTestTable(string name, string age) {
    // Load insert test statement
    string sql = "INSERT INTO test VALUES('" + name + "', " + age + ");";

    // Execute SQL Statement
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

}

void SQL::printTestTable() {
    string sql = "SELECT * FROM 'test';";
    // Execute SQL Statement
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
}

//_easyClass("SOC-A") -> "ECON 003"
string SQL::_easyClass(string requirementName){
    return "ECON003";
}

string SQL::_getRating(string courseName) {
    return "TOP OF LIST";
}

//create_table("CS100 Class", ["Student Names", "TEXT"], ["SID", "INT"], ["NETID", "TEXT"], ["Year", "INT"])
//create_table(string table_name, int numColms, )

//getEasiestClass
string SQL::getEasiestCourse(string requirementName, int limit) {
    string easyClass = _easyClass(requirementName);
    string rating = _getRating(easyClass);
    return "Class: " + easyClass + " Rating: " + rating;
    //Class: ECON003 Rating: 2.3
}