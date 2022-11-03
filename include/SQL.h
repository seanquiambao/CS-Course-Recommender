// SQL.h
#include <string>
#include "../sqlite3/src/sqlite3.h"

using namespace std;

#ifndef __SQL_H__
#define __SQL_H__

class SQL {
    private:
        // Variables
        sqlite3 *db;
        char *zErrMsg;
        int rc;

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
};

#endif
