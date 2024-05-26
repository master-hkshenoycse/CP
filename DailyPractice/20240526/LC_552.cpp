#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[100005][2][3];
    int mod=1e9+7;

    int solve(int ind,int rem,int cons,int n){
        
        if(ind==n){
            return 1;
        }

        if(dp[ind][rem][cons] != -1){
            return dp[ind][rem][cons];
        }

        int res=0;
        res=res+solve(ind+1,rem,2,n);//student is present

        if(res>=mod){
            res-=mod;
        }

        if(rem>0){
            res=res+solve(ind+1,rem-1,2,n);
            if(res>=mod){
                res-=mod;
            }
        }

        if(cons>0){
            res=res+solve(ind+1,rem,cons-1,n);
            if(res>=mod){
                res-=mod;
            }
        }


        return dp[ind][rem][cons]=res;
    }
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,1,2,n);    
    }
};