#include "UserDatabase.h"
#include "MovieDatabase.h"
#include "User.h"
#include "Recommender.h"
#include <iostream>
#include <string>
using namespace std;

const string USER_DATAFILE  = "/Users/umittal/Desktop/CS32 Projects/CS32 Project 4/CS32 Project 4/users.txt";
const string MOVIE_DATAFILE = "/Users/umittal/Desktop/CS32 Projects/CS32 Project 4/CS32 Project 4/movies.txt";

int main()
{   auto start = chrono::steady_clock::now();
    UserDatabase udb;
    bool y=udb.load(USER_DATAFILE);
    MovieDatabase ud;
    ud.load(MOVIE_DATAFILE);
    
    Recommender x(udb,ud);
    //    x=new Recommender(udb,ud);
    
    //Enter Email such as KabiL@aol.com and also enter number of movies you want
    x.findMatches(x, ud, "KabiL@aol.com", 8);
    auto stop = chrono::steady_clock::now();
    cout << "Took " << (chrono::duration_cast<chrono::milliseconds>(stop - start).count()) << "ms" << endl;
    if (y==false)  // In skeleton, load always return false
    {
        cout << "Failed to load user data file " << USER_DATAFILE << "!" << endl;
        return 1;
    }
    for (;;)
    {
        cout << "Enter user email address (or quit): ";
        string email;
        getline(cin, email);
        if (email == "quit")
            return 0;
        User* u = udb.get_user_from_email(email);
        if (u == nullptr)
            cout << "No user in the database has that email address." << endl;
        else
            cout << "Found " << u->get_full_name() << endl;
    }
}

