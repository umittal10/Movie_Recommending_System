#ifndef RECOMMENDER_INCLUDED
#define RECOMMENDER_INCLUDED

#include <string>
#include <vector>
//#include "utility.h"
class UserDatabase;
class MovieDatabase;
class Movie;

struct MovieAndRank
{
    MovieAndRank(const std::string& id, int score)
     : movie_id(id), compatibility_score(score)
    {}

    std::string movie_id;
    int compatibility_score;
};
struct MovieSorter{
    MovieSorter(const std::string& id, int score,float rating,std::string title)
    :mov_id(id),comp_score(score),rate(rating),titles(title){}
    
    std::string mov_id,titles;
    int comp_score,rate;
};
class Recommender
{
  public:
    Recommender(const UserDatabase& user_database,
                const MovieDatabase& movie_database);
    std::vector<MovieAndRank> recommend_movies(const std::string& user_email,
                                             int movie_count) const;
    void findMatches(const Recommender& r,
     const MovieDatabase& md,
     const std::string& user_email,
                     int num_recommendations);
  private:
//    std::vector<MovieAndRank> m_recommendations;
    const UserDatabase* ud;
    const MovieDatabase* md;
    Movie* movies;
    
};

#endif // RECOMMENDER_INCLUDED
