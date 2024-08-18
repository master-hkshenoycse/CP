#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        ll n=energyDrinkA.size();
        
        vector<vector<ll> > dp(n,vector<ll> (2,-1e18));
        dp[0][0]=energyDrinkA[0];
        dp[0][1]=energyDrinkB[0];
        ll ans=0;
        ans=max({ans,dp[0][0],dp[0][1]});
        
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i][0],dp[i-1][0]+energyDrinkA[i]);
            dp[i][1]=max(dp[i][1],dp[i-1][1]+energyDrinkB[i]);
            
            ll ex_A=0;
            if(i-2>=0){
                ex_A=dp[i-2][1];
            }
            
            dp[i][0]=max(dp[i][0],ex_A+energyDrinkA[i]);
            
            
            ll ex_B=0;
            
            if(i-2>=0){
                ex_B=dp[i-2][0];
            }
            
            dp[i][1]=max(dp[i][1],ex_B+energyDrinkB[i]);
            
            ans=max(ans,dp[i][0]);
            ans=max(ans,dp[i][1]);
        }
        
        return ans;
    }
};