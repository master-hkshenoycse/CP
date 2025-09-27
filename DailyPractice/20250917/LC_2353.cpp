#include<bits/stdc++.h>
using namespace std;
class FoodRatings {
public:
    map<string,string> foodCusine;
    map<string,int> currRating;
    map<string,set<pair<int,string> > >ratingCusines;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        foodCusine.clear();
        currRating.clear();
        ratingCusines.clear();
        
        int n=foods.size();
        for(int i=0;i<n;i++){
            foodCusine[foods[i]]=cuisines[i];
            currRating[foods[i]]=ratings[i];
            ratingCusines[cuisines[i]].insert({-ratings[i],foods[i]});
        }

    }
    
    void changeRating(string food, int newRating) {
        
        int curr_rating=currRating[food];
        string Cusine=foodCusine[food];
        
        ratingCusines[Cusine].erase({-curr_rating,food});
        
        
        currRating[food]=newRating;
        ratingCusines[Cusine].insert({-newRating,food});
        
        
    }
    
    string highestRated(string cuisine) {
        
        auto it=*ratingCusines[cuisine].begin();
        return it.second;
        
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */