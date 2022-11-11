#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

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

    if (tableName == "Course Difficulty") {

        //SQL language: Create Table with passed in tableName
        string sql = "CREATE TABLE IF NOT EXISTS 'Course Difficulty'"
                    "("
                    "name TEXT PRIMARY KEY NOT NULL,"
                    "difficulty REAL NOT NULL"
                    ");";
        
        // Execute SQL Statement
         rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);
    }
    if(tableName == "Breadth Courses") {

        string sql = "CREATE TABLE IF NOT EXISTS '" + tableName + "'"
                    "("
                    "name TEXT PRIMARY KEY NOT NULL,"
                    "units INTEGER NOT NULL," 
                    "requirements TEXT NOT NULL"
                    ");";

         rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);
    }
}

// Is there a more dynamic way to pass in different # of parameters?
void SQL::_insertTable(vector<string> columns, string tableName) {
    // Load insert test statement
    string sql = "INSERT INTO '" + tableName 
                + "' VALUES(";
    
    for(int i = 0; i < columns.size(); ++i)
    {
        if(i == columns.size() - 1) sql += "'" + columns[i] + "');";
        else sql += "'" + columns[i] + "', ";
    }

    // Execute SQL Statement
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

}

// Prints all data entries from passed in tableName
void SQL::printTable(string tableName) {
    string sql = "SELECT * FROM '" +  tableName + "';";
    // Execute SQL Statement
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    cout << zErrMsg << endl;
}

// Fetch a a list of data entries from a table
vector<vector<string> > SQL::fetchTable(string tableName) {
    string sql = "SELECT * FROM '" +  tableName + "';";
    // Execute SQL Statement
    vector<vector<string> > test;
    return test;
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

// Reading data from CSV file
void SQL::readData(string fileName, string tableName) {
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