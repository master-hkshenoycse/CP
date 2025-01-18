#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int v,vector<vector<pair<int,int> > > &adj,vector<int> &vis,int wt){
        vis[v]=1;
        for(auto to:adj[v]){
            if(vis[to.first]==0 and to.second<=wt){
                dfs(to.first,adj,vis,wt);
            }
        }
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        int lo=0,hi=1e6,ans=hi+1;
        vector<vector<pair<int,int> > > adj(n);
        for(auto e:edges){
            adj[e[1]].push_back({e[0],e[2]});
        }

        vector<int> vis(n,0);

        while(hi>=lo){
            int mid=(hi+lo)/2;

            for(int i=0;i<n;i++){
                vis[i]=0;
            }    



            dfs(0,adj,vis,mid);
            int f=1;
            for(int i=0;i<n;i++){
                if(vis[i]==0){
                    f=0;
                }
            }

            if(f){
                ans=min(ans,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        if(ans>1e6){
            ans=-1;
        }

        return ans;


    }
};