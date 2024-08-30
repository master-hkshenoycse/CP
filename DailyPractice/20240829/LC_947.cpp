#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> adj[1005];
    int vis[10005];
    int c=0;
    
    void dfs(int v){
        vis[v]=1;
        c++;
        for(auto to:adj[v]){
            if(vis[to])continue;
            dfs(to);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int ans=0,n=stones.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] or stones[i][1]==stones[j][1]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                c=0;
                dfs(i);
                ans=ans+c-1;
            }
        }
        return ans;
        
        
    }
};