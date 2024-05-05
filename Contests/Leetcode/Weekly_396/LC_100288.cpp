#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        ll mod=1e9+7;

        vector<ll> dp(1e6+5,1e18);
        vector<ll> freq(1e6+5,0);
        
        
        dp[0]=0;
        ll ma=0;
        for(auto e:nums){
            freq[e]++;
            ma=max(ma,e*1ll);
        }
        
        
        ll changes=0;
        for(ll i=1;i<=ma;i++){
            dp[i]=min(dp[i],dp[i-1]+freq[i-1]*cost1);
            dp[i]=min(dp[i],dp[i-1]+(freq[i-1]/2)*cost2+(freq[i-1]%2)*cost1);
            freq[i]+=freq[i-1];
            //cout<<i<<" "<<dp[i]<<endl;
        }
        
        return dp[ma]%modte;
    }
};