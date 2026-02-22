#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll prec=0;
ll sq_rep[100005];
void get_rep(){
    if(prec)
        return;
    
    prec=1;
    sq_rep[1]=1;
    for(ll i=2;i<=100000;i++){
        ll val=i;
        sq_rep[i]=1;
        for(ll j=2;j*j<=val;j++){
            if(val%j==0){
                ll cnt=0;
                while(val%j==0){
                    cnt++;
                    val/=j;
                }
                if(cnt%2){
                    sq_rep[i]*=j;
                }
            }
        }
        if(val>1){
            sq_rep[i]*=val;
        }
    }
}
class Solution {

public:
    void dfs(ll v,ll par, map<int,int> &help, vector<vector<int> >&adj, vector<int> &nums,ll &ans){
        ll rep=sq_rep[nums[v]];

        ans=ans+help[rep]*1ll;
        help[rep]++;

        for(auto to:adj[v]){
            if(to==par)
                continue;
            dfs(to,v,help,adj,nums,ans);
        }


        help[rep]--;
    }
    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        get_rep();
        map<int,int> help;
        vector<vector<int> >adj(n);

        ll ans=0;
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        dfs(0,-1,help,adj,nums,ans);

        return ans;
    }
};