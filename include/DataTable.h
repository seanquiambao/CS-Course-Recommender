// SQL.h
#include <string>
#include <vector>

using namespace std;

#ifndef __DATATABLE_H__
#define __DATATABLE_H__

struct DataTable {
    private:
        int nCol, nRow;
        vector<string*> vecStr;
    public:

        // Construct empty array with initialized size of columns/rows
        DataTable(char** pazResult, int nCol, int nRow);
        
        // Deconstructor
        ~DataTable();

        // Prints contents of DataTable to termiminal
        void printTable();

        // Get data entry cell of DataTable
        string getData(int column, int row);

        // returns true/false if table is empty
        bool isEmpty() {return vecStr.size() == 0;}
};

#endif