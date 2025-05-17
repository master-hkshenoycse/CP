#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int mod=1e9+7;
        void dfs(int v,int p,vector<int> &ret,vector<vector<pair<int,int> > >&adj){
            for(auto to:adj[v]){
                if(to.first == p){
                    continue;
                }
    
                long long curr = ret[v];
                curr = curr *(long long)to.second;
                curr%=mod;
    
                ret[to.first] = curr;
                dfs(to.first,v,ret,adj);
            }
        }
        vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
            int n = conversions.size()+1;
            vector<int> ret(n,1);
    
            vector<vector<pair<int,int> > > rates(n);
            for(auto c:conversions){
                rates[c[0]].push_back({c[1],c[2]});
                rates[c[1]].push_back({c[0],c[2]});
            }
    
            dfs(0,-1,ret,rates);
    
            return ret;
    
        }
    };