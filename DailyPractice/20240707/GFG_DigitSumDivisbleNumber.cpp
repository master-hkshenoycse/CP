#include<bits/stdc++.h>
using namespace std;
#define ll long long
//https://practice.geeksforgeeks.org/contest/gfg-weekly-162-rated-contest/problems
class Solution {
  public:
    ll dp[20][2][200];
    ll solve_dp(ll ind,ll ti,ll rem,ll r,string &n){
        
        if(ind==r){
            return (rem==0);
        }
        
        if(dp[ind][ti][rem] != -1){
            return dp[ind][ti][rem];
        }
        
        ll res=0;
        ll d=n[ind]-'0';
        
        if(ti){
            
            for(ll i=0;i<=d;i++){
                if(i==0 and ind==0){
                    continue;
                }
                res=res+solve_dp(ind+1,i==d,(rem+i)%r,r,n);
            }
                
        }else{
            for(ll i=0;i<=9;i++){
                res=res+solve_dp(ind+1,0,(rem+i)%r,r,n);
            }
        }
        
        return dp[ind][ti][rem]=res;
    }
    ll get_sol_len(ll len){
        vector<ll> dp2(len,0);
        dp2[0]=1;
        
        for(ll i=1;i<=len;i++){
            vector<ll> tmp(len,0);
            for(ll j=0;j<=9;j++){
                for(ll k=0;k<len;k++){
                    if(j==0 and i==1){
                        continue;
                    }
                    tmp[(j+k)%len]=(tmp[(j+k)%len]+dp2[k]);
                }
            } 
            
            dp2=tmp;
        }
        
        return dp2[0];
    }
    ll get_sol(ll num){
        string n=to_string(num);
        ll sz=n.size();
        ll res=0;
        
        for(ll i=1;i<sz;i++){
            res=res+get_sol_len(i);
        } 
        
        memset(dp,-1,sizeof(dp));
        res=res+solve_dp(0,1,0,sz,n);
        
        
        return res;
        
    }
    long long countNumbers(long long L, long long R) {
        // code here
        return get_sol(R)-get_sol(L-1);
    }
};