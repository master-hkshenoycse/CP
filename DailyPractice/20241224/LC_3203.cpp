
#include<bits/stdc++.h>
using namespace std;
class process_tree{
public:
    vector<vector<int> > adj;
    vector<int> dp;
    int n;
    process_tree(vector<vector<int> >&edges){
        n=edges.size()+1;
        adj.resize(n);
        dp.resize(n,0);

        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0,-1);
        dfs2(0,-1,0);


    }

    void dfs(int v,int p){
        for(auto to:adj[v]){
            if(to==p){
                continue;
            }
            dfs(to,v);
            dp[v]=max(dp[v],dp[to]+1);
        }
    }

    void dfs2(int v,int p,int prev){
        dp[v]=max(dp[v],prev);

        vector<int> pref,suff;

        for(auto to:adj[v]){
            if(to==p){
                continue;
            }
            pref.push_back(dp[to]+2);
            suff.push_back(dp[to]+2);
        }
        int sz=pref.size();
        for(int i=1;i<sz;i++){
            pref[i]=max(pref[i],pref[i-1]);
        }

        for(int i=sz-2;i>=0;i--){
            suff[i]=max(suff[i],suff[i+1]);
        }

        int c=0;

        for(auto to:adj[v]){
            if(to==p){
                continue;
            }
            int nx_prev=prev+1;
            if(c-1>=0){
                nx_prev=max(nx_prev,pref[c-1]);
            }
            if(c+1<sz){
                nx_prev=max(nx_prev,suff[c+1]);
            }
            dfs2(to,v,nx_prev);
            c++;
        }
        

    }
};
class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        
        process_tree t1(edges1);
        process_tree t2(edges2);

        int d1=0,d2=0,min_d1=1e9,min_d2=1e9;
        for(auto e:t1.dp){
            d1=max(d1,e);
            min_d1=min(min_d1,e);
        }

        for(auto e:t2.dp){
            d2=max(d2,e);
            min_d2=min(min_d2,e);
        }

        return max({d1,d2,min_d1+min_d2+1});






    }
};