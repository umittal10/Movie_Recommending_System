#include "MovieDatabase.h"
#include "Movie.h"
#include "utility.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

MovieDatabase::MovieDatabase()
{
    // Replace this line with correct code.
}

bool MovieDatabase::load(const string& filename)//loads data into the MovieDatabase
{
    ifstream infile(filename);
    if(!infile)//checking if file is invalid
        return false;
    std::string s;
    int c=1;
    if(flag==true)//checking if file has been accessed before
        return true;
    
    while (getline(infile,s))//parsing line by line
    {
       
        if(c==1)
            m_id=s;
        else if(c==2)
            m_name=s;
        else if(c==3)
            m_year=s;
        else if(c==4){

            stringstream str(s);
            while (str.good()) {
                string substr;
                getline(str, substr, ',');
                m_director.push_back(substr);
            }
        }
        else if(c==5){
            stringstream str(s);
            while (str.good()) {
                string substr;
                getline(str, substr, ',');
                m_actor.push_back(substr);
                
            }
        }
        else if(c==6){

            stringstream str(s);
            while (str.good()) {
                string substr;
                getline(str, substr, ',');
                m_genres.push_back(substr);
            }
        }
        else if(c==7)//on 7th line each time we store data
        {
            
            m_rating=stof(s);
            getline(infile,s);
            c=0;
            
            Movie* ptr=new Movie(m_id,m_name,m_year,m_director,m_actor,m_genres,m_rating);
            id_to_movie.insert(m_id, ptr);
            for(int i = 0; i< m_director.size(); i++)
            {
                director_to_movie.insert(lower(m_director[i]), ptr);
            }
            for(int i = 0; i< m_actor.size(); i++)
            {
                actor_to_movie.insert(lower(m_actor[i]), ptr);
            }
            for(int i = 0; i< m_genres.size(); i++)
            {
                genre_to_movie.insert(lower(m_genres[i]), ptr);
            }
            
            
            m_director.clear();
            m_actor.clear();
            m_genres.clear();
        }
        c++;
        flag=true;
    }
    
    return flag;
    // Replace this line with correct code.
}

Movie* MovieDatabase::get_movie_from_id(const string& id) const
{
    TreeMultimap<string, Movie*>::Iterator it =id_to_movie.find(id);//accessing movie and getting Movie pointer from its ID
    return it.get_value();  // Replace this line with correct code.
}

vector<Movie*> MovieDatabase::get_movies_with_director(const string& director) const
{
    TreeMultimap<string, Movie*>::Iterator it =director_to_movie.find(lower(director));//accessing movie and getting Movie pointer from its director
    vector<Movie*> values;
    while(it.is_valid()){
        values.push_back(it.get_value());
        //it=director_to_movie.find(director);
        it.advance();
    }
    return values;  // Replace this line with correct code.
}

vector<Movie*> MovieDatabase::get_movies_with_actor(const string& actor) const
{
    TreeMultimap<string, Movie*>::Iterator it =actor_to_movie.find(lower(actor));//accessing movie and getting Movie pointer from its actors
    vector<Movie*> values;
    while(it.is_valid())
    {
        values.push_back(it.get_value());
        //it =actor_to_movie.find(actor);
        it.advance();
    }
    return values;  // Replace this line with correct code.
}

vector<Movie*> MovieDatabase::get_movies_with_genre(const string& genre) const
{
    TreeMultimap<string, Movie*>::Iterator it =genre_to_movie.find(lower(genre));//accessing movie and getting Movie pointer from its genres
    vector<Movie*> values;
    while(it.is_valid()){
        values.push_back(it.get_value());
        it.advance();
    }
    return values;  // Replace this line with correct code.
}

