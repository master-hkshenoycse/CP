#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
        
    int find_distance(int n,int src,int dest,vector<vector<pair<int,int> > > &adj){
        
        vector<int> dp(n,1e9+6);
        dp[src]=0;
        priority_queue<pair<int,int> ,vector<pair<int,int> >, greater<pair<int,int> >  >pq;
        pq.push({0,src});

        while(pq.size()>0){
            int v=pq.top().second;
            

            if(dp[v] != pq.top().first){
                pq.pop();
                continue;
            }

            pq.pop();

            for(auto to:adj[v]){
                if(dp[to.first] > dp[v]+to.second){
                    dp[to.first]=dp[v]+to.second;
                    pq.push({dp[to.first],to.first});
                }
            }
        }

        return dp[dest];
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target){


        vector<vector<pair<int,int> > > adj(n);
        for(auto e:edges){
            if(e[2]==-1){
                continue;
            }

            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }

        int isEqual=0;
        int currD=find_distance(n,source,destination,adj);
        if(currD<target){
            return {};
        }

        if(currD==target){
            isEqual=1;
        }
        
        for(auto &e:edges){
            
            if(e[2]!=-1){
                continue;
            }

            if(isEqual){
                e[2]=1e9;
            }else{
                e[2]=1;
            }

            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});

            if(isEqual==0){
                int currD=find_distance(n,source,destination,adj);
                if(currD<=target){
                    e[2]+=(target-currD);
                    isEqual=1;
                }
            }
        }

        if(isEqual==0){
            return {};
        }

        return edges;
        
    }
};