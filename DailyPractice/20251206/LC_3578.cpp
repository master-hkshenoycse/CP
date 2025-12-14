#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        ll mod=1e9+7,n=nums.size();
        vector<ll> dp(n+1,0);
        vector<ll> prefix_dp(n+1,0);
        dp[0]=1;
        prefix_dp[0]=1;
        multiset<int> cnt;
        int j=0;
        for(int i=1;i<=n;i++){
            cnt.insert(nums[i-1]);

            while(j<=i && *cnt.rbegin()-*cnt.begin()>k){
                cnt.erase(cnt.find(nums[j]));
                j++;
            }

            dp[i]=prefix_dp[i-1];
            if(j>0)dp[i]=(dp[i]-prefix_dp[j-1]+mod)%mod;

            prefix_dp[i]=(prefix_dp[i-1]+dp[i])%mod;

        }

        return dp[n];
    }
};