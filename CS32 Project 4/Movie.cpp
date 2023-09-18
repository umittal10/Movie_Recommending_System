#include "Movie.h"

#include <string>
#include <vector>
using namespace std;

Movie::Movie(const string& id, const string& title, const string& release_year,
             const vector<string>& directors, const vector<string>& actors,
             const vector<string>& genres, float rating):m_id(id),m_title(title),m_year(release_year),m_rating(rating)
{
    for(int i = 0; i< directors.size(); i++)//storing directors,actors,genres this way because i delete memory location in the load function
    {
        m_directors.push_back(directors[i]);
    }
    for(int i = 0; i< actors.size(); i++){
        m_actors.push_back(actors[i]);
    }
    for(int i=0;i<genres.size();i++){
        m_genres.push_back(genres[i]);
    }
}
    // Replace this line with correct code.
string Movie::get_id() const //returns id
{
    return m_id;  // Replace this line with correct code.
}

string Movie::get_title() const
{
    return m_title;  // Replace this line with correct code.
}

string Movie::get_release_year() const
{
    return m_year;  // Replace this line with correct code.
}

float Movie::get_rating() const
{
    return m_rating;  // Replace this line with correct code.
}

std::vector<std::string> Movie::get_directors() const//returns vector of directors
{
    return m_directors;  // Replace this line with correct code.
}
vector<string> Movie::get_actors() const//returns vector of actors
{
    return m_actors;  // Replace this line with correct code.
}

vector<string> Movie::get_genres() const
{
    return m_genres;  // Replace this line with correct code.
}

