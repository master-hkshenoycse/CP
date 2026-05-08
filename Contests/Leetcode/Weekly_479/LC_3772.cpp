#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int v,int p,vector<vector<int> >&adj,vector<int>&good,vector<int> &sub_good){
        if(good[v]==0)
            good[v]=-1;
        
        int subs=0;
        for(auto to:adj[v]){
            if(to==p)continue;
            dfs(to,v,adj,good,sub_good);
            subs+=max(0,sub_good[to]);
        }
        
        sub_good[v]=subs+good[v];
        //cout<<v<<": "<<good[v]<<" "<<subs<<" "<<sub_good[v]<<endl;
    }

    void dfs2(int v, int p,vector<vector<int> >&adj,vector<int> &good, vector<int> &sub_good,int good_par,vector<int> &ret){
        
        ret[v]=max(ret[v],good_par+sub_good[v]);
        
        vector<int> pref_sum,suff_sum;
        for(auto to:adj[v]){
            if(to==p)
                continue;
            pref_sum.push_back(max(0,sub_good[to]));
            suff_sum.push_back(max(0,sub_good[to]));
        }

        int sz=pref_sum.size();
        for(int i=1;i<sz;i++)
            pref_sum[i]+=pref_sum[i-1];

        for(int i=sz-2;i>=0;i--)
            suff_sum[i]+=suff_sum[i+1];

        int c=0;
        for(auto to:adj[v]){
            if(to==p)continue;
            int nx_good_par=good_par;
            if(c-1>=0)nx_good_par+=max(0,pref_sum[c-1]);
            if(c+1<sz)nx_good_par+=max(0,suff_sum[c+1]);
            nx_good_par=max(0,nx_good_par+good[v]);
            dfs2(to,v,adj,good,sub_good,nx_good_par,ret);
            c++;
        }


    }
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        vector<vector<int> > adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> sub_good(n,0);
        dfs(0,-1,adj,good,sub_good);
        vector<int> ret=sub_good;
        dfs2(0,-1,adj,good,sub_good,0,ret);
        return ret;

    }
};