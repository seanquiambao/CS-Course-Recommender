// SQL.h
#include <string>
#include <vector>
#include "../third-party-sqlite/src/sqlite3.h"

#include "DataTable.h"

using namespace std;

#ifndef __SQL_H__
#define __SQL_H__

class SQL {
    private:
        // Variables
        sqlite3 *db = nullptr;
        char *zErrMsg = nullptr;
        int rc = 0;

        void _showErrMsg(sqlite3*);
        void _createTable(string tableName);
        void _readData(string,string);

        // Populates DataTable class with data fetched from passed in SQL Queries
        void _fetchSQL(string);
        void _executeSQL(string);

    public:

        SQL();
        ~SQL();

        //2D Vector thats stores results select* 
        DataTable *dataTable;

        // Course Recommender Functions
        void fetchTable(string tableName);
        void easyClass(string, int, string);

        // User Database Functions
        bool doesExist(string,string,string);
        void insertTable(vector<string>, string);
        void deleteDataFromTable(string, string, string);
        void getValue(string, string, string, string);
        void createUserTable(string);
        int getRC();
};

#endif
