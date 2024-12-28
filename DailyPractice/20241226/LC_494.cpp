
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int ind,int sum,int target,vector<int> &nums,map<pair<int,int> ,int > &dp){
        if(ind==nums.size()){
            return sum==target;
        }

        if(dp.find({ind,sum}) != dp.end()){
            return dp[{ind,sum}];
        }

        int ret=0;
        ret=ret+solve(ind+1,sum-nums[ind],target,nums,dp);
        ret=ret+solve(ind+1,sum+nums[ind],target,nums,dp);
        return dp[{ind,sum}]=ret;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        map<pair<int,int> ,int > dp;
        return solve(0,0,target,nums,dp);
    }
};