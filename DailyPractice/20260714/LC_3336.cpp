#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[201][201][201];
    int mod=1e9+7;
    int solve(int ind,int first,int second,vector<int> &nums){
        if(ind==nums.size()){
            return (first>0) and (second>0) and (first==second);
        }

        if(dp[ind][first][second] != -1){
            return dp[ind][first][second];
        }

        int res=solve(ind+1,first,second,nums);
        res=(res+solve(ind+1,__gcd(first,nums[ind]),second,nums))%mod;
        res=(res+solve(ind+1,first,__gcd(nums[ind],second),nums))%mod;
        return dp[ind][first][second]=res;

    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        return solve(0,0,0,nums);
        
        
    }
};