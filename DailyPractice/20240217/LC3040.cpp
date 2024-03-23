#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void clear_matrix(vector<vector<int> >&dp){
        int n=dp.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=-1;
            }
        }
    }
    int get_solve(int l,int r,vector<vector<int> >&dp,vector<int> &nums,int req){
        if(r-l+1<2){
            return 0;
        }
        
        if(dp[l][r] != -1){
            return dp[l][r];
        }
        
        int res=0;
        if(req==nums[l]+nums[l+1]){
            res=max(res,1+get_solve(l+2,r,dp,nums,req));
        }
        
        if(req==nums[l]+nums[r]){
            res=max(res,1+get_solve(l+1,r-1,dp,nums,req));
        }
        
        if(req==nums[r]+nums[r-1]){
            res=max(res,1+get_solve(l,r-2,dp,nums,req));
        }
        
        return dp[l][r]=res;
        
    }
    int maxOperations(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int> > dp(n+1,vector<int> (n+1,-1));
        int ans=get_solve(0,n-1,dp,nums,nums[0]+nums[1]);
        
        clear_matrix(dp);
        ans=max(ans,get_solve(0,n-1,dp,nums,nums[n-1]+nums[n-2]));
        
        clear_matrix(dp);
        ans=max(ans,get_solve(0,n-1,dp,nums,nums[0]+nums[n-1]));
        
        return ans;
        
        
    }
};

int main(){
    
}