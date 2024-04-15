#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        priority_queue<pair<int,int> ,vector<pair<int,int> > ,greater<pair<int,int> > > pq;
        vector<vector< pair<int,int>  > > adj(n);

        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        } 

        vector<int> sol(n,INT_MAX);
        sol[0]=0;
        pq.push({0,0});

        while(pq.size()>0){
            int v=pq.top().second;
            int d=pq.top().first;
            pq.pop();

            if(sol[v]<d){
                continue;
            }

            for(auto to:adj[v]){
                int nx=to.first;
                int wt=to.second;

                if(sol[nx]>sol[v]+wt and sol[v]+wt<disappear[nx]){
                    sol[nx]=sol[v]+wt;
                    pq.push({sol[nx],nx});
                }

            }

        }


        for(int i=0;i<n;i++){
            if(sol[i]==INT_MAX){
                sol[i]=-1;
            }
        }

        return sol;
    }
};