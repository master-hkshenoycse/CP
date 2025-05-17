#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    
        int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
            vector<int> req_mask(n,0),in_deg(n,0);
            vector<vector<int> > adj(n);
        
            for(auto e:edges){
                adj[e[0]].push_back(e[1]);
                in_deg[e[1]]++;        
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
                    req_mask[to]=(req_mask[to] | (1<<v));
                    if(in_deg[to]==0){
                        q.push(to);
                    }
                }
            }
    
            vector<int> dp(1<<n,-1);
            dp[0]=0;
    
            for(int mask=0;mask<(1<<n);mask++){
                if(dp[mask]==-1){
                    continue;
                }
                int pos=__builtin_popcount(mask)+1;
                for(int i=0;i<n;i++){
                    if(mask & (1<<i)){
                        continue;
                    }
                    if((mask & req_mask[i]) == req_mask[i]){
                        dp[mask|(1<<i)]=max(dp[mask|(1<<i)],dp[mask]+pos*score[i]);
                    }
                }
            }
            return dp[(1<<n)-1];
    
        }
    };