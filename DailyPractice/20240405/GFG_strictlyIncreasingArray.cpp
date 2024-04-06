#include<bits/stdc++.h>
using namespace std;
//https://www.geeksforgeeks.org/problems/convert-to-strictly-increasing-array3351/1
class Solution {
  public:

    int min_operations(vector<int>& nums) {
        // Code here
        //modified lis with picked up subsequence should have differnce of atleast their differnce in indices
        //need to modify those elements not part of LIS
        
        int n=nums.size();
        vector<int> dp(n,1);
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]-nums[j]>=i-j){
                    dp[i]=max(dp[i],dp[j]+1);
                    ans=max(ans,dp[i]);
                }
                
            }
        }
        
        return n-ans;
    }
};