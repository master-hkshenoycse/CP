#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[1005];
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        dp[1]=0;
        
        for(int i=2;i<=n;i++){
            dp[i]=INT_MIN;
            for(int j=1;j<i;j++){
                if(abs(nums[i-1]-nums[j-1])<=target and dp[j]>=0){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        
        if(dp[n]<0){
            dp[n]=-1;
        }
        
        return dp[n];
    }
};