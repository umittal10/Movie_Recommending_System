#ifndef USERDATABASE_INCLUDED
#define USERDATABASE_INCLUDED

#include <string>
#include "treemm.h"
#include <vector>
class User;

class UserDatabase
{
  public:
    UserDatabase();
    bool load(const std::string& filename);
    User* get_user_from_email(const std::string& email) const;
  private:
    User *ptr;
    TreeMultimap<std::string,User*> tmm;
    std::vector <std::string> watch_history;
    std::string name;
    std::string email;
    bool flag=false;
    
};

#endif // USERDATABASE_INCLUDED

