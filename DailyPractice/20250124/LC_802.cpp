#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> in_deg(n,0);
        vector<int> rev_adj[n];

        vector<int> is_safe(n,1),vis(n,0);
        queue<int> q;

        for(int i=0;i<n;i++){
            for(auto e:graph[i]){
                rev_adj[e].push_back(i);
                in_deg[i]++;
            }
        }

        for(int i=0;i<n;i++){
            if(in_deg[i]==0){
                q.push(i);
            }
        }

        while(q.size()>0){
            int v=q.front();
            vis[v]=1;
            q.pop();

            for(auto to:rev_adj[v]){
                in_deg[to]--;
                is_safe[to]=(is_safe[to] & is_safe[v]);
                if(in_deg[to]==0){
                    q.push(to);
                }
            }
        }







        vector<int> sol;
        for(int i=0;i<n;i++){
            if(is_safe[i] and vis[i]==1){
                sol.push_back(i);
            }
        }

        return sol;
                
    }
};