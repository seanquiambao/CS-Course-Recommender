// SQL.h
#include <string>
#include <vector>
#include <sqlite3.h> 

#include "DataTable.h"
//#include "../third-party-sqlite/src/sqlite3.h"

using namespace std;

#ifndef __SQL_H__
#define __SQL_H__

class SQL {
    private:
        // Variables
        sqlite3 *db;
        char *zErrMsg;
        int rc;

        // Table vectors {"TableName", "ColA", "ColB", ... }
        vector<string> coursesDifficulty {"Course Difficulty", "name", "difficulty"};
        vector<string> coursesBreadth {"Breadth Courses", "name", "units", "requirements"};
        
        void _insertTable(vector<string>, vector<string>);
        void _showErrMsg(sqlite3*);
        void _createTable(string tableName);
        void _readData(string,vector<string>);

        // Populates DataTable class with data fetched from passed in SQL Queries
        void _fetchSQL(string);
        

    public:

        SQL();
        ~SQL();

        //2D Vector thats stores results select* 
        DataTable *dataTable;

        void printTable(string tableName);
        void fetchTable(string tableName);
        void easyClass(string, int);
};

#endif