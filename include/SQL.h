// SQL.h
#include <string>
#include <vector>
#include <sqlite3.h> 

using namespace std;

#ifndef __SQL_H__
#define __SQL_H__

class SQL {
    private:
        // Variables
        sqlite3 *db;
        char *zErrMsg;
        int rc;
        
        void _insertTable(vector<string>, string);
        void _showErrMsg(sqlite3*);
        

    public:

        SQL();
        ~SQL();
        void _createTable(string tableName);
        void printTable(string tableName);
        vector<vector<string>> fetchTable(string tableName);
        void readData(string,string);
        string _getValue(string,string,string,string);
        vector<string> _easyClass(string, int);
};

#endif