#include "UserDatabase.h"
#include "User.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

UserDatabase::UserDatabase()
{
}

bool UserDatabase::load(const string& filename)//loads data into userdatabase
{
    
    if(flag==true)
        return false;
    ifstream file(filename);
    if(!file)//checking for incorrect filename
        return false;
    std::string s;
    getline(file,name);
    getline(file,email);
    getline(file, s);
    int num;
    num=stoi(s);//converting number of movies seen from string to int
    int c=0;
    while (getline(file, s))
    {
        
        if(c==num)
        {

            ptr=new User(name,email,watch_history);
            tmm.insert(email, ptr);//inserting User into Tree Multimap
            //getline(file, s);
            getline(file,name);
            if(name=="")
                break;
            getline(file,email);
            getline(file,s);
            num=stoi(s);
            c=0;
            watch_history.clear();
        }
        else{
            watch_history.push_back(s);
            c++;
        }
    }
    if(c==num){
        ptr=new User(name,email,watch_history);
        tmm.insert(email, ptr);
    }
    flag=true;
    return flag;
}

User* UserDatabase::get_user_from_email(const string& email) const//getter for user from their email
{
    TreeMultimap<string, User*>::Iterator it = tmm.find(email);
        return it.get_value();  // Replace this line with correct code.
}
