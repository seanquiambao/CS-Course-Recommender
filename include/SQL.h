// SQL.h
#include <string>
<<<<<<< HEAD
#include <vector>
#include "../third-party-sqlite/src/sqlite3.h"
=======
#include "../sqlite3/src/sqlite3.h"
>>>>>>> b2779245b6a4f63fffa91aff0caffff723ae3802

using namespace std;

#ifndef __SQL_H__
#define __SQL_H__

class SQL {
    private:
        // Variables
        sqlite3 *db;
        char *zErrMsg;
        int rc;
<<<<<<< HEAD
        
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
=======

        //_easyClass("SOC-A") -> "ECON 003"
        string _easyClass(string requirementName);

        string _getRating(string courseName);

    public:

        // Constructor
        SQL();

        // Destructor
        ~SQL();

        //getEasiestClass
        string getEasiestCourse(string requirementName, int limit = 3);
>>>>>>> b2779245b6a4f63fffa91aff0caffff723ae3802
};

#endif
