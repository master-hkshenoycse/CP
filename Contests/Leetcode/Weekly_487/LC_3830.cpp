#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int> > suff_dp(n,vector<int> (2,1)),pref_dp(n,vector<int> (2,1));
        int ans=0;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                pref_dp[i][0]=pref_dp[i-1][1]+1;
            }else if(nums[i]<nums[i-1]){
                pref_dp[i][1]=pref_dp[i-1][0]+1;
            }
            ans=max(ans,pref_dp[i][0]);
            ans=max(ans,pref_dp[i][1]);
        }

        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                suff_dp[i][1]=suff_dp[i+1][0]+1;
            }else if(nums[i]>nums[i+1]){
                suff_dp[i][0]=suff_dp[i+1][1]+1;
            }
        }

        for(int i=0;i+2<n;i++){
            int curr_0 = pref_dp[i][0] + suff_dp[i+2][1];
            int curr_1 = pref_dp[i][1] + suff_dp[i+2][0];

            if(nums[i] < nums[i+2]){
                ans=max(ans,pref_dp[i][1]+suff_dp[i+2][0]);
            }

            if(nums[i] > nums[i+2]){
                ans=max(ans,pref_dp[i][0]+suff_dp[i+2][1]);
            }
        }

        return ans;
    }
};