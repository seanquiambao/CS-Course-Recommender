// SQL.h
#include <string>
#include "sqlite3.h"

using namespace std;

#ifndef __SQL_H__
#define __SQL_H__

class SQL {
    private:
        // Variables
        sqlite3 *db;
        char *zErrMsg;
        int rc;

        

        // Returns course name with lowest difficulty rating for passed in breadth requirement
        string _easyClass(string requirementName);//_easyClass("SOC-A") -> "ECON003"

        //Returns average difficulty rating for passed in course name (based on UCR difficulty database)
        string _getRating(string courseName); //_getRating("ECON003") -> 2.4

    public:

        // Constructor
        SQL();

        // Destructor
        ~SQL();

        //getEasiestClass
        string getEasiestCourse(string requirementName, int limit = 3);
};

#endif
