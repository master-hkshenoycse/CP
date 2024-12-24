#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    vector<ll> adj[30005];
    ll ans=0;
    ll dfs(ll v,ll p,ll k,vector<int> &values){
        ll s=values[v];
        
        for(auto to:adj[v]){
            if(to!=p){
                s=s+dfs(to,v,k,values);
            }
        }
        
        if(s%k==0){
            ans++;
        }
        
        return s;
        
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        
        
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        dfs(0,-1,k,values);
        
        return ans;
    }
};