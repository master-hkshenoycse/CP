#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int x,int y, map<pair<int,int> ,vector< pair<int,int> > > &servers,map<pair<int,int>,int> &vis, int &c){
        c++;
        vis[{x,y}]=1;
        

        for(auto v:servers[{x,y}]){
            if(vis.find({v.first,v.second})==vis.end()){
                dfs(v.first,v.second,servers,vis,c);
            }
        }
    }
    int countServers(vector<vector<int>>& grid) {
        map<pair<int,int> , vector< pair<int,int> > >servers;
        int n=grid.size(),m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==0){
                    continue;
                }

              

                for(int k=0;k<j;k++){
                    if(grid[i][k]==1){

                        servers[{i,j}].push_back({i,k});
                        servers[{i,k}].push_back({i,j});
                    }
                }

                for(int k=0;k<i;k++){
                    if(grid[k][j]==1){

                        servers[{i,j}].push_back({k,j});
                        servers[{k,j}].push_back({i,j});
                    }
                }

            }
        }

        map<pair<int,int>,int> vis;
        int ans=0;
        for(auto s:servers){
            
            if(vis.find(s.first)==vis.end()){
                int c=0;
                dfs(s.first.first,s.first.second,servers,vis,c);
                ans=ans+c;
            }

          
        }

        return ans;

    }
};