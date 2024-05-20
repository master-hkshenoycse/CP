#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    
    ll get_ncr(ll n,ll r,vector<vector<ll> > &dp){
        if(r>n){
            return 0;
        }
        
        if(r==0 or n==r){
            return dp[n][r]=1;
        }
        
        if(dp[n][r] != -1){
            return dp[n][r];
        }
        
        return dp[n][r]=get_ncr(n-1,r-1,dp)+get_ncr(n-1,r,dp);
    }
    int waysToReachStair(int k) {
        
        ll sum_total=0;
        ll ans=0;
        vector<vector<ll> > dp(45,vector<ll> (45,-1));
        
        if(k==1){
            ans=1;
        }
        
        if(k==0){
            return 2;
        }
        //starting from 0
        for(ll i=0;i<=40;i++){
            sum_total+=(1ll<<i);
            if(sum_total<k){
                continue;
            }else{
                ll req=sum_total-k;
                if(req<=i+1){
                    ans=ans+get_ncr(i+1,req,dp);
                }
            }
        }
        
        //starting from 1
        k--;
        sum_total=0;
        for(ll i=0;i<=40;i++){
            sum_total+=(1ll<<i);
            if(sum_total<k){
                continue;
            }else{
                ll req=sum_total-k;
                if(req<=i+1){
                    ans=ans+get_ncr(i+1,req,dp);
                }
            }
        }
        
        return ans;
    }
};