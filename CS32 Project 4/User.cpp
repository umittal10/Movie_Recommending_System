#include "User.h"

#include <string>
#include <vector>
using namespace std;

User::User(const string& full_name, const string& email,
           const vector<string>& watch_history):m_name(full_name),m_email(email),m_history(watch_history)
{}

string User::get_full_name() const//name getter
{
    return m_name;  // Replace this line with correct code.
}

string User::get_email() const//email getter
{
    return m_email;  // Replace this line with correct code.
}

vector<string> User::get_watch_history() const//history getter
{
    return m_history;  // Replace this line with correct code.
}
