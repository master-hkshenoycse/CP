#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    long long maximumStrength(vector<int>& nums, int k) {
        ll n=nums.size();
        vector<vector<ll> >dp(n+1,vector<ll> (k+1,-1e18));
        
        vector<ll> csum(n+1,0);
        for(ll i=1;i<=n;i++){
            csum[i]=csum[i-1]+nums[i-1];
        }
        
        
        dp[0][0]=0;
        
        vector<ll> max_dp(k+1,-1e18);
        max_dp[0]=0;
        
        for(ll i=1;i<=n;i++){
            
            dp[i][0]=dp[i-1][0];
            for(ll j=1;j<=k;j++){
                
                dp[i][j]=dp[i-1][j];
                
                    
                if(j%2){
                    dp[i][j]=max(dp[i][j],max_dp[j-1]+(k-j+1)*csum[i]);  
                }else{
                    dp[i][j]=max(dp[i][j],max_dp[j-1]-(k-j+1)*csum[i]);
                }
        
            }
            
            for(ll j=0;j<=k;j++){
                if(j%2){
                    max_dp[j]=max(max_dp[j],dp[i][j]+(k-j)*csum[i]);
                }else{
                    max_dp[j]=max(max_dp[j],dp[i][j]-(k-j)*csum[i]);
                }             
            }
            
        }
        
        return dp[n][k];
    }
};