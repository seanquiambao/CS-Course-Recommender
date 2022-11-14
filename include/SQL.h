// SQL.h
#include <string>
#include <vector>
#include <sqlite3.h> 

#include "DataTable.h"

using namespace std;

#ifndef __SQL_H__
#define __SQL_H__

class SQL {
    private:
        // Variables
        sqlite3 *db;
        char *zErrMsg;
        int rc;

        // Print passed in error message 
        void printErrMsg(const char* db_error_msg);

        // create type of SQL table in database based on passed in tableName
        void _createTable(string tableName);

        // Insert data into test table
        void _insertDifficultyTable(string, string);

        //_easyClass("SOC-A") -> "ECON 003"
        string _easyClass(string requirementName);

        // Get the r
        string _getRating(string courseName);

    public:

        // Constructor
        SQL();
        char** test;

        // Destructor
        ~SQL();

        //2D Vector thats stores results select* 
        DataTable *dataTable;

        // Prints out the data entries of test table
        void printTable(string tableName);

        //getEasiestClass
        string getEasiestCourse(string requirementName, int limit = 3);

        void insertDifficultyTable(string name, string dif) {_insertDifficultyTable(name, dif);}
        void createTable(string tableName) {_createTable(tableName);}

        // Populates DataTable class with data fetched from passed in SQL Queries
        void fetchSQL(string);

        void readData(string);
};

#endif