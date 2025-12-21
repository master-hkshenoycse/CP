#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll dp[1005][1005][2];
    ll solve(ll ind,ll rem,ll prev,vector<int> &prices){
        if(ind == prices.size()){
            if(rem%2==0)return 0;
            return -1e18;
        }

        if(dp[ind][rem][prev] != -1){
            return dp[ind][rem][prev];
        }

        //skip this price
        ll res = solve(ind+1,rem,prev,prices);

        if(rem>0 && rem%2==0){
            res=max(res,-prices[ind]+solve(ind+1,rem-1,1,prices));
            res=max(res,prices[ind]+solve(ind+1,rem-1,0,prices));
        }else if(rem>0){
            if(prev){
                res=max(res,prices[ind]+solve(ind+1,rem-1,0,prices));
            }else{
                res=max(res,-prices[ind]+solve(ind+1,rem-1,0,prices));
            }
        }

        return dp[ind][rem][prev] = res;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        ll n = prices.size();
        for(int i=0;i<=n;i++){
            for(int j=0;j<=2*k+1;j++){
                dp[i][j][0]=-1;
                dp[i][j][1]=-1;
            }
        }

        return solve(0,2*k,0,prices);        
    }
};