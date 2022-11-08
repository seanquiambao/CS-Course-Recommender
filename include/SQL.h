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
 
        //2D Vector thats stores info for SQL Table Columns (column name, data type, condition)
        // vector< vector<string> > coursesDifficultyOutline = {
        //     {"name", "TEXT", "PRIMARY KEY", "NOT NULL"},
        //     {"difficulty", "INT", "NOT NULL"}
        // };

        // create type of SQL table in database based on passed in tableName
        void _createTable(string tableName);

        // Insert data into test table
<<<<<<< HEAD
        void _insertDifficultyTable(string name, string difficulty);
=======
        void _insertDifficultyTable(string, string);
>>>>>>> 9be7c888e1fb8b0fa4e10fece942a00a0618a565

        //_easyClass("SOC-A") -> "ECON 003"
        string _easyClass(string requirementName);

        string _getRating(string courseName);

        

    public:

        // Constructor
        SQL();

        // Destructor
        ~SQL();

<<<<<<< HEAD
=======
        //Getters
        void createTable(string tableName) {_createTable(tableName);}
        void insertDifficultyTable(string name, string age) {_insertDifficultyTable(name, age);}

>>>>>>> 9be7c888e1fb8b0fa4e10fece942a00a0618a565
        // Prints out the data entries of test table
        void printTable(string tableName);

        //getEasiestClass
        string getEasiestCourse(string requirementName, int limit = 3);
<<<<<<< HEAD

        vector<vector<string>> fetchTable(string tableName);
=======
>>>>>>> 9be7c888e1fb8b0fa4e10fece942a00a0618a565
        void readData(string);
};

#endif