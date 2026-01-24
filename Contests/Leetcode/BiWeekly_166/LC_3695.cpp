#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    void dfs(int v,vector<vector<int> >&adj, vector<int> &vis,vector<int> &curr){
        vis[v]=1;
        curr.push_back(v);

        for(auto nx:adj[v]){
            if(vis[nx]==0){
                dfs(nx,adj,vis,curr);
            }
        }
    }
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
       int n=nums.size();
       vector<int> vis(n,0);
       vector<vector<int> >adj(n);
       ll ret=0;
       for(auto s:swaps){
        adj[s[0]].push_back(s[1]);
        adj[s[1]].push_back(s[0]);
       } 

       for(int i=0;i<n;i++){
        if(vis[i]==0){
            vector<int> curr;
            dfs(i,adj,vis,curr);
            ll od_cnt=0,ev_cnt=0;
            sort(curr.begin(),curr.end(),[&](int a,int b){
                return nums[a] > nums[b];
            });

            for(int i=0;i<curr.size();i++){
                if(curr[i]%2){
                    od_cnt++;
                }else{
                    ev_cnt++;
                }
            }
            for(int i=0;i<curr.size();i++){
                if(i<ev_cnt){
                    ret=ret+nums[curr[i]]*1ll;
                }else{
                    ret=ret-nums[curr[i]]*1ll;
                }
            }
        }
       }

       return ret;
    }
};