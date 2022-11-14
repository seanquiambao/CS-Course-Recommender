// DataTable.cpp
#include <string>
#include <vector>
#include <iostream>
#include "../include/DataTable.h"

using namespace std;


// Construct empty array with initialized size of columns/rows
DataTable::DataTable(char** pazResult, int nCol, int nRow) {

    // Initialize variables
    this->nCol = nCol;
    this->nRow = nRow;

    //Populate dataTable vector of strings
    for (unsigned index = 0; index < (nRow + 1) * nCol; ++index) {
        this->vecStr.push_back(new string(pazResult[index]));
    } 
}

// Deconstructor
DataTable::~DataTable() {

    // delete every char* (string) in the dataTable vector
    for (auto strPtr: vecStr) { delete strPtr; }
}

// Prints contents of DataTable to termiminal
void DataTable::printTable() {
    for (unsigned i = 0; i < (nRow + 1) * nCol; ++i) {
        cout << vecStr.at(i)->data() << " ";
        if ((i + 1) % nCol == 0) {cout << endl;}
        if (i == nCol - 1) { cout << string(size_t(strlen(vecStr.at(0)->data())) + size_t(strlen(vecStr.at(1)->data())) + 1,'-') << endl;}
    }
    cout << endl;
}

// Get data entry cell of DataTable
string DataTable::getData(int column, int row) {
    return vecStr.at(row * nCol + column - 1)->data();
}
