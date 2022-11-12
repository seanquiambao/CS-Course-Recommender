// SQL.h
#include <string>
#include <vector>
#include "../third-party-sqlite/src/sqlite3.h"

using namespace std;

#ifndef __SQL_H__
#define __SQL_H__

class SQL {
    private:
        // Variables
        sqlite3 *db;
        char *zErrMsg;
        int rc;
        
        
        void _showErrMsg(sqlite3*);
        

    public:

        // SQL Functions
        SQL();
        ~SQL();
        void _createTable(string tableName);
        void _insertTable(vector<string>, string);
        void printTable(string tableName);
        void readData(string,string);
        vector<vector<string>> fetchTable(string tableName);
        string _getValue(string,string,string,string);
        
        // Course Recommender Functions
        vector<string> _easyClass(string, int);

        // User Database Functions
        bool _doesExist(string,string,string);
};

#endif
