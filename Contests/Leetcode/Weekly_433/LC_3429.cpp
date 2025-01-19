#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll solve(ll ind,ll p,ll q,vector<vector<int> >&cost,vector<vector<vector<ll> > > &dp,int lim){
        if(ind==lim){
            return 0;
        }
        
        if(dp[ind][p][q] != -1){
            return dp[ind][p][q];
        }
        
        ll res=1e18;
        
        ll fs=ind;
        ll ls=lim*2-ind-1;
        
        if(ind==0){
            for(ll i=0;i<3;i++){
                for(ll j=0;j<3;j++){
                    if(i!=j){
                        res=min(res,cost[fs][i]+cost[ls][j]+solve(ind+1,i,j,cost,dp,lim));
                    }
                }
            }
        }else{
            
            for(ll i=0;i<3;i++){
                for(ll j=0;j<3;j++){
                    if(i!=j and i!=p and j!=q){
                        res=min(res,cost[fs][i]+cost[ls][j]+solve(ind+1,i,j,cost,dp,lim));
                    }
                }
            }
        }
        
        return dp[ind][p][q]=res;
    }
    long long minCost(int n, vector<vector<int>>& cost) {
        vector<vector<vector<ll> > > dp(n/2,vector<vector<ll> > (3,vector<ll> (3,-1)));
        return solve(0,0,0,cost,dp,n/2);
    }
};