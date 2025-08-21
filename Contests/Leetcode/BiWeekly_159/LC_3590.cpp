#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    vector< ordered_set<int> > dp;
    vector<int> res;
    vector<vector<int> > adj;
    map<int, vector<pair<int,int> > > Q;

    int dfs(int u,int p,vector<int> &vals,int x){
        x = (x ^ vals[u]);
        int sz = 1;
        int mx = -1;
        int who = -1;

        for(auto v:adj[u]){

            if(v == p){
                continue;
            }

            int sz_v = dfs(v,u,vals,x);
            sz+=sz_v;

            if(sz_v > mx){
                mx =sz_v;
                who = v;
            }
        }

        if(who != -1){
            dp[u].swap(dp[who]);
            for(auto v:adj[u]){
                if(v == p){
                    continue;
                }
                for(auto it:dp[v]){
                    dp[u].insert(it);
                }
            }
        }

        dp[u].insert(x);

        for(auto q:Q[u]){
            int i = q.second;
            int k = q.first;

            if(k>dp[u].size()){
                res[i] = -1;
            }else{
                res[i] = *dp[u].find_by_order(k-1);
            }
        }

        return sz;

    }
    vector<int> kthSmallest(vector<int>& par, vector<int>& vals, vector<vector<int>>& queries) {
        
        int q = queries.size();
        int n = par.size();

        adj.resize(n);
        dp.resize(n);
        res.resize(queries.size(),0);

        for(int i=1;i<n;i++){
            adj[i].push_back(par[i]);
            adj[par[i]].push_back(i);
        }

        for(int i=0;i<queries.size();i++){
            int v = queries[i][0];
            int k = queries[i][1];

            Q[v].push_back({k,i});
        }

        dfs(0,0,vals,0);

        return res;


        
    }
};