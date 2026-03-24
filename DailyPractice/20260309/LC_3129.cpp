#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll mod=1e9+7;
    ll dp[205][205][2];

    ll solve(ll rem_z,ll rem_o,ll curr,ll limit){

        if(rem_z==0 and rem_o==0){
            return 1;
        }

        

        if(dp[rem_z][rem_o][curr] != -1){
            return dp[rem_z][rem_o][curr];
        }

        ll res=0;

        if(curr){
            for(ll i=1;i<=limit;i++){
                if(i<=rem_o){
                    res=(res+solve(rem_z,rem_o-i,1-curr,limit))%mod;
                }
            }
        }else{
            for(ll i=1;i<=limit;i++){
                if(i<=rem_z){
                    res=(res+solve(rem_z-i,rem_o,1-curr,limit))%mod;
                }
            }
        }

        return dp[rem_z][rem_o][curr]=res;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));

        ll ans=solve(zero,one,0,limit)+solve(zero,one,1,limit);
        ans%=mod;

        return ans;
    }
};