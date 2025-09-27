#include<bits/stdc++.h>
using namespace std;
class MovieRentingSystem {
public:
    multiset<vector<int> >shops_movie[300005],movie_in_shops[300005],rented_sh,rented_by_price;
    multiset<vector<int> >::iterator it;
    
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        
        for(int i=0;i<entries.size();i++){
            
            int m=entries[i][1];
            int s=entries[i][0];
            int p=entries[i][2];
            
            shops_movie[s].insert({m,p});
            movie_in_shops[m].insert({p,s}); 
        }

    }
    
    vector<int> search(int movie) {
        
        int lim=min(5,(int)movie_in_shops[movie].size());
        vector<int> res;
        vector<vector<int> > tmp;
   
        
        while(lim--){
            auto x=*movie_in_shops[movie].begin();
            
            
            res.push_back(x[1]);
            tmp.push_back(x);
            movie_in_shops[movie].erase(movie_in_shops[movie].begin());
        }
        
        for(auto x:tmp){
            movie_in_shops[movie].insert(x);
        }
        
        return res;
    }
    
    void rent(int shop, int movie) {
        
        it=shops_movie[shop].lower_bound({movie,INT_MIN});
        
        
        int price=(*it)[1];
 
        
        
        shops_movie[shop].erase(*it);
        movie_in_shops[movie].erase({price,shop});
        
        rented_sh.insert({shop,movie,price});
        rented_by_price.insert({price,shop,movie});
        
    }
    
    void drop(int shop, int movie) {
        it=rented_sh.lower_bound({shop,movie,INT_MIN});
        int price=(*it)[2];
        
        rented_sh.erase({shop,movie,price});
        shops_movie[shop].insert({movie,price});
        movie_in_shops[movie].insert({price,shop});
        rented_by_price.erase({price,shop,movie});
        
    }
    
    vector<vector<int>> report() {
        vector<vector<int> > sol;
        
        int lim=min(5,(int)rented_by_price.size());
        vector<vector<int> > tmp;
        
        while(lim--){
            auto x=*rented_by_price.begin();
            
            tmp.push_back(x);
            sol.push_back({x[1],x[2]});
            rented_by_price.erase(rented_by_price.begin());
        }
        
        for(auto x:tmp){
            rented_by_price.insert(x);
        }
        return sol;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */