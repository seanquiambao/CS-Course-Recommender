#include <iostream>
<<<<<<< HEAD
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
=======
>>>>>>> 5b9f266 (Added Folders, cpp, and header files)

#include "../include/SQL.h"

using namespace std;

<<<<<<< HEAD
//=========================== GENERAL SQL COMMANDS =========================================

=======
>>>>>>> 5b9f266 (Added Folders, cpp, and header files)
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
<<<<<<< HEAD
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



string SQL::_getValue(string selectionColumn, string relativeColumn, string find, string tableName) {
    sqlite3_stmt *selectstmt;
    string s;
    string sql = "SELECT " 
                + selectionColumn
                + " FROM '"
                + tableName
                + "' WHERE "
                + relativeColumn
                +" = '" 
                + find 
                + "';";
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &selectstmt, NULL);
    if(rc != SQLITE_OK) _showErrMsg(db);
    else if((sqlite3_step(selectstmt) == SQLITE_ROW)) s = ((const char*)sqlite3_column_text(selectstmt, 0));
    return s;
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
void SQL::_showErrMsg(sqlite3* dbError) {
    const char* db_error_msg = sqlite3_errmsg(dbError);
    string s; 
    s.append(reinterpret_cast<const char*>(db_error_msg));
    cout << "ERROR: " + s << endl;
}
//=========================== COURSE RECOMMENDER COMMANDS =========================================
vector<string> SQL::_easyClass(string requirementName, int limit){
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
    
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &selectstmt, NULL);
    if(rc != SQLITE_OK) _showErrMsg(db);
    else {
        while(sqlite3_step(selectstmt) == SQLITE_ROW)
        {
            s = ((const char*)sqlite3_column_text(selectstmt, 0));
            listOfClasses.push_back(s);
        }
    }
    return listOfClasses;
}
=======
    if (db != nullptr) {free(db);}
    if (zErrMsg != nullptr) {delete zErrMsg;}
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
>>>>>>> 5b9f266 (Added Folders, cpp, and header files)
