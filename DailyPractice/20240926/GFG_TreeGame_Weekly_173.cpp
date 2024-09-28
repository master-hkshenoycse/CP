#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
  public:
    void dfs(ll v,vector<vector<ll> > &adj,vector<vector<ll> > &dp,vector<int> &a){
        //dp[v][0]==> bext possible ans/
        //dp[v][1]==> remove v.
        //dp[v][2]==> keep v with odd number of children
        //dp[v][3]==> keep v with even number of children.
        
        for(auto to:adj[v]){
            dfs(to,adj,dp,a);
            dp[v][1]+=dp[to][0];//best if node v is removed
        }
        
        
        
        vector<ll> c={0,(ll)-1e18};
        //c[0]==> if node v connected to even number of edge
        //c[1]==> if node v connected to odd number of edge.
        
        for(auto to:adj[v]){
            auto nc=c;
            nc[0]=max(c[0]+dp[to][1],c[1]+dp[to][3]);
            nc[1]=max(c[0]+dp[to][3],c[1]+dp[to][1]);
            c=nc;
        }
        
        dp[v][2]=c[1]+a[v];
        dp[v][3]=c[0]+a[v];
        dp[v][0]=max(dp[v][1],dp[v][2]);
        
        //cout<<v<<" "<<dp[v][0]<<" "<<dp[v][1]<<" "<<dp[v][2]<<" "<<dp[v][3]<<endl;
        
    }
    long long treeGame(int n, vector<int> &p, vector<int> &a) {
        // code here
        vector<vector<ll> > adj(n),dp(n,vector<ll> (4,0));
        
        for(ll i=1;i<n;i++){
            int par=p[i-1]-1;
            adj[par].push_back(i);
        }
        
        dfs(0,adj,dp,a);
        
        return dp[0][0];
        
    
    }
};