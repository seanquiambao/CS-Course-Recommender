#include "../include/loginSystem.h"
#include "../include/SQL.h"
#include "../include/CourseRecommender.h"
#include "../include/DataTable.h"
// #include "../include/Planner.h"

#include <iostream>
#include <string>
#include <thread>

using namespace std;

string loginSystem::loginPrompt(SQL* database) {
    string username;
    string password;
    


    while(true) {
        
        system("clear");  
        char choice = 0;
        cout << "============================================" << endl;
        cout << "COMP SCI COURSE RECOMMENDER - Login" << endl;
        cout << "============================================" << endl;
        cout << "Login? (enter 'y' to login, enter any other key to exit program): ";

        cin >> choice;
        tolower(choice);
        if(choice != 'y') {
            system("clear");
            return "";
        }
        cin.ignore();
        

        cout << "Username: ";
        getline(cin, username);
        if(!isRegistered(username, database)) {
            system("clear");

            cout << "The username '" + username 
                        +"' is not in the database.\n"
                        + "Do you wish to register? (enter 'y' to register, otherwise enter any other key): ";
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
    system("clear");

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
    if(database->doesExist(username, "username", "User Database")) {
        delete database->dataTable;
        return true;
    }

    delete database->dataTable;
    return false;

    
}
bool loginSystem::isUser(string username, string password, SQL* database) {
    bool access = false;
    database->getValue("password", "username", username, "User Database");
    if(password == database->dataTable->getData(1, 1)) access = true;
    
    delete database->dataTable;
    return access;
}