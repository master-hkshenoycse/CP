#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[505][505][30];
    int solve_dp(int ind,int prev,vector<int> &nums,int rem){
        if(ind==nums.size()+1){
            return 0;
        }
        
        if(dp[ind][prev][rem] != -1){
            return dp[ind][prev][rem];
        }
        
        int res=solve_dp(ind+1,prev,nums,rem);
        int last=-1;
        if(prev != 0){
            last=nums[prev-1];
        }
        
        if(last==-1 or last==nums[ind-1]){
            res=max(res,1+solve_dp(ind+1,ind,nums,rem));
        }else{
            if(rem>0)res=max(res,1+solve_dp(ind+1,ind,nums,rem-1));
        }
        
        return dp[ind][prev][rem]=res;
    }
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                for(int l=0;l<=k;l++){
                    dp[i][j][l]=-1;
                }
            }
        }
        
        return solve_dp(1,0,nums,k);
    }
};