#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> adj[200005];
    int dist[200005][2];
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        int  m=edges.size();
        
        
        for(int i=1;i<=n;i++){
            dist[i][0]=1e9;
            dist[i][1]=1e9;
            adj[i].clear();
        }
        
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        set<vector<int> > s;
        dist[1][0]=0;
        s.insert({0,1,0});
        
        while(s.size()>0){
            
            int v=(*s.begin())[1];
            int ty=(*s.begin())[2];
            s.erase(s.begin());
            
            int d=(dist[v][ty])/change;
            
            if(d%2){
                d=(d+1)*change;
            }else{
                d=dist[v][ty];
            }
            
            
            if(ty==0){
                
                int r_=(d+time);
                r_=(r_)/change;
                
                if(r_ %2){
                    r_=(r_+1)*change;
                }else{
                    r_=(d+time);
                }
                r_+=time;
                //cout<<v<<" "<<r_<<endl;

                if(r_>dist[v][0] and r_<dist[v][1]){
                    dist[v][1]=r_;
                    s.insert({dist[v][1],v,1});
                }   
                
            }
            
            
            
            for(auto to:adj[v]){
                if(d+time < dist[to][0]){
                    dist[to][0]=d+time;
                    s.insert({dist[to][0],to,0});
                }else if(d+time > dist[to][0] and d+time < dist[to][1]){
                    dist[to][1]=d+time;
                    s.insert({dist[to][1],to,1});
                }
            }
            
        }
        
        
        
        return dist[n][1];
        
        
        
        
    }
};