#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int solve(int prev,int ind,vector<int> &nums,vector<vector<int> > &dp){
            if(ind==nums.size()){
                return nums[prev];
            }
    
            if(ind==nums.size()-1){
                return max(nums[prev],nums[ind]);
            }
    
            if(dp[ind][prev] != -1){
                return dp[ind][prev];
            }
    
            int ret=max(nums[ind],nums[ind+1])+solve(prev,ind+2,nums,dp);
            ret=min(ret,max(nums[prev],nums[ind+1])+solve(ind,ind+2,nums,dp));
            ret=min(ret,max(nums[prev],nums[ind])+solve(ind+1,ind+2,nums,dp));
    
            return dp[ind][prev]=ret; 
        }
        int minCost(vector<int>& nums) {
            int n=nums.size();
            vector<vector<int> > dp(n+1,vector<int> (n+1,-1));
            return solve(0,1,nums,dp);
    
          
        }
    };