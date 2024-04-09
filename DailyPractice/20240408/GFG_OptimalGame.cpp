#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    ll solve(ll l,ll r,vector<vector<ll> > &dp,vector<ll> &v,ll ch){
        
        if(l==r){
            if(ch)return dp[l][r]=v[l];
            else return dp[l][r]=0;
        }
        
        if(r==l+1){
            if(ch)return dp[l][r]=max(v[l],v[r]);
            else return dp[l][r]=min(v[l],v[r]);
        }
        
        if(dp[l][r] != -1){
            return dp[l][r];
        }
        
        ll res;
        if(ch){
            res=-1e18;
            res=max(res,v[l]+solve(l+1,r,dp,v,1-ch));
            res=max(res,v[r]+solve(l,r-1,dp,v,1-ch));
        }else{
            res=1e18;
            res=min(res,solve(l+1,r,dp,v,1-ch));
            res=min(res,solve(l,r-1,dp,v,1-ch));
        }
        
        return dp[l][r]=res;
    }
    long long maximumAmount(int n, int arr[]){
        // Your code here
        vector<vector<ll> > dp(n,vector<ll> (n));
        vector<ll> v;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=-1;
            }
        }
        for(int i=0;i<n;i++){
            v.push_back(arr[i]);
        }
        
        return solve(0,n-1,dp,v,1);
    }
};