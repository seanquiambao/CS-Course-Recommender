#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include "../include/SQL.h"

using namespace std;

//=========================== GENERAL SQL COMMANDS =========================================

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

    // Create Tables
    _createTable("Course Difficulty");
    _createTable("Breadth Courses");

    // Populate Tables from csv files in db directory
    _readData("../db/difficultyDatabase.csv", coursesDifficulty);
    _readData("../db/breadthCourses.csv", coursesBreadth);
}

// Destructor
SQL::~SQL() {

    // Closes connection to local database
    sqlite3_close(db);

    // dealloc private pointer variables
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

// create type of SQL table in database based on passed in tableName
void SQL::_createTable(string tableName) {

    if (tableName == coursesDifficulty.at(0)) {

        //SQL language: Create Table with passed in tableName
        string sql = "CREATE TABLE IF NOT EXISTS '" + coursesDifficulty.at(0) + "'"
                    "("
                    + coursesDifficulty.at(1) + " TEXT NOT NULL,"
                    + coursesDifficulty.at(2) + " REAL NOT NULL,"
                    "UNIQUE(";
                    for (unsigned i = 1; i < coursesDifficulty.size(); ++i) {
                        sql += coursesDifficulty.at(i);
                        if (i < coursesDifficulty.size() - 1) sql += ", ";
                        else sql += "));";
                    }
        
        cout << "SQL:" << sql << endl;
        // Execute SQL Statement
         rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);
         if (rc != SQLITE_OK) _showErrMsg(db);
         
    }
    if(tableName == coursesBreadth.at(0)) {

        string sql = "CREATE TABLE IF NOT EXISTS '" + coursesBreadth.at(0) + "'"
                    "("
                    + coursesBreadth.at(1) + " TEXT NOT NULL,"
                    + coursesBreadth.at(2) + " INTEGER NOT NULL," 
                    + coursesBreadth.at(3) + " TEXT NOT NULL,"
                    "UNIQUE(";
                    for (unsigned i = 1; i < coursesBreadth.size(); ++i) {
                        sql += coursesBreadth.at(i);
                        if (i < coursesBreadth.size() - 1) sql += ", ";
                        else sql += "));";
                    }

        cout << "SQL:" << sql << endl;
        rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);
    }
}

void SQL::_insertTable(vector<string> columns, vector<string> tableName) {
    // Load insert test statement
    string sql = "INSERT INTO '" + tableName.at(0)
               + "' VALUES(";
    
    for(int i = 0; i < columns.size(); ++i)
    {
        if(i == columns.size() - 1) sql += "'" + columns[i] + "');";
        else sql += "'" + columns[i] + "', ";
    }
    // Execute SQL Statement
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

}

// Fetch a a list of data entries from a table
void SQL::_fetchSQL(string sql) {
    int pnRow;
    int pnColumn;
    char *cErrMsg;
    char **pazResult;

    rc = sqlite3_get_table(
        db,          /* An open database */
        sql.c_str(),     /* SQL to be evaluated */
        &pazResult,    /* Results of the query */
        &pnRow,           /* Number of result rows written here */
        &pnColumn,        /* Number of result columns written here */
        &cErrMsg       /* Error msg written here */
        );

    if (rc == SQLITE_OK){dataTable = new DataTable(pazResult, pnColumn, pnRow);}
    else {_showErrMsg(db);} 
}

// Prints all data entries from passed in tableName
void SQL::printTable(string tableName) {
    string sql = "SELECT * FROM '" +  tableName + "';";
    // Execute SQL Statement
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    cout << zErrMsg << endl;
}

// Fetch a a list of data entries from a table
void SQL::fetchTable(string tableName) {
    string sql = "SELECT * FROM '" +  tableName + "';";
    // Execute SQL Statement and store into DataTable struct
    _fetchSQL(sql);
}

// Reading data from CSV file
void SQL::_readData(string fileName, vector<string> tableName) {
    ifstream inFS;
    vector<string> dataVector;
    string data;
    string line;
    
    cout << "Opening " + fileName + " file" << endl;
    inFS.open(fileName);

    if(!inFS.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }
    else cout << "Success!" << endl;

    while(getline(inFS, line)) // Reads every line in CSV file
    {
        stringstream ss (line);
        while(getline(ss, data, ',')) dataVector.push_back(data); // Reads through the line and pushes data in data vector.
        _insertTable(dataVector, tableName); // Insert to table
        dataVector.clear();
    }
    inFS.close();

}
void SQL::_showErrMsg(sqlite3* dbError) {
    const char* db_error_msg = sqlite3_errmsg(dbError);
    string s; 
    s.append(reinterpret_cast<const char*>(db_error_msg));
    cout << "ERROR: " + s << endl;
}
//=========================== COURSE RECOMMENDER COMMANDS =========================================
void SQL::easyClass(string requirementName, int limit){
    sqlite3_stmt* selectstmt;
    vector<string> listOfClasses;
    string s;
    string sql = "SELECT 'Course Difficulty'.name FROM 'Course Difficulty' "
                "INNER JOIN 'Breadth Courses' ON 'Breadth Courses'.name = 'Course Difficulty'.name "
                "WHERE 'Breadth Courses'.requirements = '" + requirementName 
                + "' ORDER BY 'Course Difficulty'.difficulty ASC "
                + "LIMIT "
                + to_string(limit)
                + ";"; 
    _fetchSQL(sql);
}