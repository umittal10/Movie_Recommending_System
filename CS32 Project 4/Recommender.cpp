#include "Recommender.h"
#include "UserDatabase.h"
#include "MovieDatabase.h"
#include "User.h"
#include "Movie.h"
#include "utility.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
//using namespace std;

Recommender::Recommender(const UserDatabase& user_database,
                       const MovieDatabase& movie_database)
{
    ud=&user_database;//referencing values
    md=&movie_database;// Replace this line with correct code.
}

vector<MovieAndRank> Recommender::recommend_movies(const string& user_email, int movie_count) const
{
    std::vector<MovieAndRank> m_recommendations;
    std::vector<std::string> movie_history;
    std::vector<std::string> actors;
    std::vector<std::string> genres;
    std::vector<std::string> directors;
    std::map<const string,int> id_to_score;
    int compatible=0;
    User* p=ud->get_user_from_email(user_email);//gets user from email
    movie_history= p->get_watch_history();//gets the user's watch history
    std::vector<Movie*> m1;
    for(auto it=movie_history.begin();it!=movie_history.end();it++)//gets the Movie pointers to the movies they watch and store in vector
    {
            m1.push_back(md->get_movie_from_id(*it));
    }
    for(int i=0;i<m1.size();i++)//parses the vector of movie pointers
    {
        //int x=i;
        directors=m1[i]->get_directors();//gets director of the movie
        for(int j=0;j<directors.size();j++)//checks movies directed by directors
        {
            vector<Movie*> movies_from_directors=md->get_movies_with_director(directors[j]);
            for(int k=0;k<movies_from_directors.size();k++)
            {
                if(id_to_score.find(movies_from_directors[k]->get_id())==id_to_score.end())
                    id_to_score[movies_from_directors[k]->get_id()]=20;
                else
                id_to_score[movies_from_directors[k]->get_id()]+=20;
            }
        }
        actors=m1[i]->get_actors();
        for(int j=0;j<actors.size();j++)//checks all movies for the actors and increases score accordingly
        {
            vector<Movie*> movies_from_actors=md->get_movies_with_actor(actors[j]);
            for(int k=0;k<movies_from_actors.size();k++)
            {
                if(id_to_score.find(movies_from_actors[k]->get_id())==id_to_score.end())
                    id_to_score[movies_from_actors[k]->get_id()]=30;
                else
                id_to_score[movies_from_actors[k]->get_id()]+=30;
            }
        }
        genres=m1[i]->get_genres();
        for(int j=0;j<genres.size();j++)
        {
            vector<Movie*> movies_from_genres=md->get_movies_with_genre(genres[j]);
            for(int k=0;k<movies_from_genres.size();k++)
            {
                if(id_to_score.find(movies_from_genres[k]->get_id())==id_to_score.end())
                    id_to_score[movies_from_genres[k]->get_id()]=1;
                else
                    id_to_score[movies_from_genres[k]->get_id()]+=1;
            }
        }
        if(i==1)
            i=1;
    }

    for(auto it=id_to_score.begin();it!=id_to_score.end();it++)//removing movies already seen
    {
        vector<string>::iterator ptr;
        ptr=std::find(movie_history.begin(),movie_history.end(),it->first);
        if(ptr!=movie_history.end()&& it->second>=1)
        {
            it->second = 0;
        }
        else{
            compatible++;
        }
    }
    //Perform Sorting
    
    std::vector<MovieSorter> sortingarray;
    for(auto it=id_to_score.begin();it!=id_to_score.end();it++)//creates vector of a new struct to enable sort based on conditions
    {
        Movie* movie_id=md->get_movie_from_id(it->first);
        MovieSorter* s=new MovieSorter(it->first,it->second,movie_id->get_rating(),movie_id->get_title());
        sortingarray.push_back(*s);
    }
    sort(sortingarray.begin(),sortingarray.end(),&compare);//uses STL sort to decrease time
    int counter=0;
    for(int i=0;i<sortingarray.size();i++)
    {
        if(movie_count==0)//if movies needed=0 then return
            return m_recommendations;
        else if(compatible<movie_count)
        {
            if(sortingarray[i].comp_score>=1)
            {
                MovieAndRank* p=new MovieAndRank(sortingarray[i].mov_id,sortingarray[i].comp_score);
                m_recommendations.push_back(*p);
            }
        }
        else{
            while(counter!=movie_count)
            {
                MovieAndRank* p=new MovieAndRank(sortingarray[i].mov_id,sortingarray[i].comp_score);
                m_recommendations.push_back(*p);
                i++;
                counter++;
            }
        }
    }
    return m_recommendations;//returning vector of movie recs
}

void Recommender::findMatches(const Recommender& r,
 const MovieDatabase& md,
 const std::string& user_email,
 int num_recommendations) {
 // get up to ten movie recommendations for the user
 vector<MovieAndRank> recommendations = r.recommend_movies(user_email, num_recommendations);
 if (recommendations.empty())
 cout << "We found no movies to recommend :(.\n";
 else {
for (int i = 0; i < recommendations.size(); i++) {
 const MovieAndRank& mr = recommendations[i];
 Movie* m = md.get_movie_from_id(mr.movie_id);
 cout << i+1 << ". " << m->get_title() << " ("
 << m->get_release_year() << ")\n   Rating: "
 << m->get_rating() << "\n   Compatibility Score: "
 << mr.compatibility_score << "\n";
}
 }
}

