#include "../include/loginSystem.h"
#include "../include/SQL.h"
#include "../include/CourseRecommender.h"
#include "../include/DataTable.h"
// #include "../include/Planner.h"

#include <iostream>
#include <string>

using namespace std;

string loginSystem::loginPrompt(SQL* database) {
    string username;
    string password;
    


    while(true) {
        
        
        char choice = 0;
        cout << endl;
        cout << "COMP SCI COURSE RECOMMENDER - Login" << endl;
        cout << "Login? (enter 'y' to login): ";

        cin >> choice;
        tolower(choice);
        if(choice != 'y') return "";
        cin.ignore();
        
        
        cout << endl;
        cout << "Username: ";
        getline(cin, username);
        if(!isRegistered(username, database)) {
            cout << "User is not in the database, register? (enter 'y' to register): ";
            cin >> choice;
            tolower(choice);

            if(choice == 'y') {
                cin.ignore();
                cout << "Enter password: ";
                getline(cin, password);
                registerUser(username, password, database);
                
            }
            choice = 0;
        }
        else {
            cout << "Password: ";
            getline(cin, password);
            
            if(isUser(username, password, database)) {
                cout << "Logged in!" << endl;
                break;
            }
            else cout << "Incorrect!" << endl;
        }
        
        
    }

    cout << "Sucess! Loading data..." << endl;
    return username;

    
}

void loginSystem::registerUser(string userName, string password, SQL* database) {
    vector<string> columns;
    columns.push_back(userName);
    columns.push_back(password);
    database->insertTable(columns, "User Database");
    database->createUserTable(userName);
}
bool loginSystem::isRegistered(string username, SQL* database) {
    bool registered = database->doesExist(username, "username", "User Database");
    delete database->dataTable;
    return registered;
}
bool loginSystem::isUser(string username, string password, SQL* database) {
    bool valid = false;
    database->getValue("password", "username", username, "User Database");
    if(password == database->dataTable->getData(1, 1)) valid = true;
    delete database->dataTable;
    return valid;
}