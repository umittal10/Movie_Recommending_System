# C++ Movie Recommendation System

## Overview

This repository contains a movie recommendation system implemented in C++. It is a project I chose to make for my CS32 (Data Structures and Algorithms) class at UCLA. It utilizes two main data files: `users.txt`, which contains user data and information about the movies they have watched, and `movies.txt`, which contains details about the movies, including actors, directors, ratings, and more.

## Getting Started

To get started with this C++ movie recommendation system, follow these steps:
1. See the users.txt and identify which user you want recommendations for.
2. If you want to get custom movie recommendations then make the necessary changes in users.txt and movies.txt
3. Run the main and edit the email field and the number of recommendations you want. Default at "KabiL@aol.com" and 8 recommendations.

## Data Files

### 1. `movies.txt`

This file contains data and information about the movies. Each line in the file represents a movie and its information in the following format:

```
movie_id, name, year, Director, Actors, Genre, Rating
```

- `movie_id`: Unique identifier for the movie.
- `name`: Movie Name
- `Director`: Movie's Director
- `Actors`: Actor's Cast
- `Genre`: Movie's Genre
- `rating`: User's rating for the movie (on a scale of 1 to 5).

Example:

```
ID10782
Santosh Subramaniam
2008
M. Raja
Jayam Ravi,Genelia D'Souza,Prakash Raj,Sayaji Shinde,Geetha
Action,Comedy,Romance
5
```

### 2. `users.txt`

This file contains user data and information about the movies they have watched. Each line in the file represents a user and their movie preferences in the following format:

```
Name, Email, Number of Movies Watched, Movie IDs
```

- `movie_id`: Unique identifier for the movie.
- `name`: Name of person
- `email`: Email ID
- `Movie ID`: Multiple Rows of Movie IDs

Example:

```
Anthony Harding
AntHardi869@yahoo.com
22
ID26160
ID15173
ID18676
ID03240
ID01201
ID09987
ID05411
ID00412
ID09405
ID08594
ID21428
ID25725
ID27818
ID03300
ID23441
ID23602
ID16058
ID03705
ID07500
ID25318
ID19614
ID25813
```

## Usage

You can use the provided data files and the C++ code in this repository to:

- Build and run a movie recommendation system.
- Make movie recommendations for users based on their preferences.
- Explore and analyze movie data.

Please refer to the documentation and code in the repository for detailed instructions on how to use the C++ movie recommendation system.

## Contact

If you have any questions or need further assistance, please feel free to [contact us](mailto:umittal10@ucla.edu).

Enjoy using the C++ movie recommendation system! 🎬🍿
