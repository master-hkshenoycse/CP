#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            int n=recipes.size();
            vector<string> sol;
           
            
            map<string,int> vis;
        
            
            for(int i=0;i<n;i++){
                vis[recipes[i]]=ingredients[i].size();
            }
            
            
            
            map<string,vector<string> >l;
            
            for(int i=0;i<n;i++){
                for(auto u:ingredients[i]){
                    l[u].push_back(recipes[i]);
                }
            }
            
            for(auto s:supplies){
            
                for(auto u:l[s]){
                    vis[u]--;
                }
            }
            
            
            
            
             
            while(1){
                
                map<string,int> to_be_add;
                to_be_add.clear();
                
                vector<string> nx;
                vector<vector<string> >nx_i;
                
                n=recipes.size();
                
                if(n==0){
                    break;
                }
                
                for(int i=0;i<n;i++){
                    if(vis[recipes[i]]==0){
                        to_be_add[recipes[i]]=1;
                        sol.push_back(recipes[i]);
                    }else{
                        nx.push_back(recipes[i]);
                    }
                }
                
                if(to_be_add.size()==0){
                    break;
                }
                
                for(auto it:to_be_add){
                    for(auto aff:l[it.first]){
                        vis[aff]--;
                    }
                }
                
                recipes=nx;
                
            }
        
            return sol;
        }
    };