#ifndef __LOGINSYSTEM_H__
#define __LOGINSYSTEM_H__

#include <iostream>
#include <string>
#include "SQL.h"

using namespace std;


class loginSystem {
    private:
    public:
    string loginPrompt(SQL*);
    void registerUser(string,string, SQL*);
    bool isRegistered(string, SQL*);
    bool isUser(string, string, SQL*);
};


#endif