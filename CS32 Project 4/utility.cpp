//
//  utility.cpp
//  CS32 Project 4
//
//  Created by UtKaRsH MiTtAl on 3/16/23.
//

#include "utility.h"
#include "Recommender.h"
#include <string>
//std::string mov_id,titles;
//int comp_score,rate;
bool compare(MovieSorter x, MovieSorter y)//sorts based on comparison
{
    if(x.comp_score==y.comp_score){
        if (x.rate == y.rate){
            return x.titles < y.titles;
        }
        return x.rate > y.rate;
    }
    return x.comp_score>y.comp_score;
}
std::string lower(std::string s)//converts string to lower case
{
    std::string c="";
    std::string a="";
    for(int i=0;i<s.size();i++){
        c=s[i]+32;
        a=a+c;
    }
    return a;
}
