#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> in_deg(n,0);
        vector<vector<int> > sol(n);

        vector<int> adj[n];

        for(auto e:edges){
            in_deg[e[1]]++;
            adj[e[0]].push_back(e[1]);
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(in_deg[i]==0){
                q.push(i);
            }
        }
        
        while(q.size()>0){
            int v=q.front();
            q.pop();
            for(auto to:adj[v]){
                in_deg[to]--;
                sol[to].push_back(v);
                
                for(auto x:sol[v]){
                    sol[to].push_back(x);
                }
                
                
                if(in_deg[to]==0){
                    q.push(to);
                    sort(sol[to].begin(),sol[to].end());
                    sol[to].erase(unique(sol[to].begin(),sol[to].end()),sol[to].end());
                }
            }
        }
        
        return sol;
        
        
    }
};