#ifndef MOVIEDATABASE_INCLUDED
#define MOVIEDATABASE_INCLUDED

#include <string>
#include <vector>
#include "treemm.h"
#include "utility.h"
class Movie;

class MovieDatabase
{
  public:
    MovieDatabase();
    bool load(const std::string& filename);
    Movie* get_movie_from_id(const std::string& id) const;
    std::vector<Movie*> get_movies_with_director(const std::string& director) const;
    std::vector<Movie*> get_movies_with_actor(const std::string& actor) const;
    std::vector<Movie*> get_movies_with_genre(const std::string& genre) const;

  private:
    TreeMultimap<std::string,Movie*> id_to_movie;
    TreeMultimap<std::string, Movie*> director_to_movie;
    TreeMultimap<std::string, Movie*> actor_to_movie;
    TreeMultimap<std::string, Movie*> genre_to_movie;
std::string m_id;
    std::string m_name;
    std::string m_year;
    float m_rating;
    bool flag=false;
    std::vector<std::string>m_director;
    std::vector<std::string>m_actor;
    std::vector<std::string> m_genres;
};

#endif // MOVIEDATABASE_INCLUDED

