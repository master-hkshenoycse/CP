#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int longestSubsequence(vector<int>& nums) {
        vector<vector<int> > dp(305,vector<int> (305,-1));
        int n=nums.size();
        int ans=0;
        
        for(int i=n-1;i>=0;i--){
            int curr=nums[i];

            for(int next=1;next<=300;next++){
                int diff=abs(next-curr);
                dp[curr][diff]=max(dp[curr][diff],dp[next][diff]+1);
            }

            for(int j=1;j<=300;j++){
                dp[curr][j]=max(dp[curr][j],dp[curr][j-1]);
                ans=max(ans,dp[curr][j]);
            }


        }

        return ans+1;


    }
};