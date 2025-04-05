#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int csum[20005];
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
           vector<vector<int> > ord;
           int sz=queries.size();
           
           for(int i=0;i<sz;i++){
               ord.push_back({queries[i],i});
           }
            
            sort(ord.begin(),ord.end());
            
            
            int n=grid.size(),m=grid[0].size();
            vector<vector<int> >vis(n,vector<int> (m,0));
            set<vector<int> >curr;
            curr.insert({grid[0][0],0,0});
            
            
            for(int i=0;i<sz;i++){
                int v=ord[i][0];
                
                while(curr.size()>0 and (*curr.begin())[0]<v){
                    csum[i]++;
                    int x=(*curr.begin())[1];
                    int y=(*curr.begin())[2];
                    curr.erase(curr.begin());
                    vis[x][y]=1;
                    
                    for(int i=0;i<4;i++){
                        int nx=x+dx[i];
                        int ny=y+dy[i];
                        
                        if(nx>=0 and nx<n and ny>=0 and ny<m and vis[nx][ny]==0 and curr.find({grid[nx][ny],nx,ny})==curr.end()){
                            curr.insert({grid[nx][ny],nx,ny});
                        }
                    }        
                }
                
                if(i-1>=0){
                    csum[i]+=csum[i-1];
                }
            }
            
            vector<int> sol(sz,0);
            for(int i=0;i<sz;i++){
                sol[ord[i][1]]=csum[i];
            }
            
        
            
            return sol;
            
            
            
            
            
            
        }
    };