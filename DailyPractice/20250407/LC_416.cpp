#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            
            int n=nums.size();
            int dp[20005]={0};
            int s=0;
            for(int i=0;i<n;i++)s+=nums[i];
            if(s%2) return 0;
            dp[0]=1;
            for(int i=0;i<n;i++){
                int temp[20005]={0};
                for(int j=0;j<=s;j++){
                    if(dp[j])temp[j+nums[i]]=max(temp[j+nums[i]],1);
                }
                for(int j=0;j<=s;j++)dp[j]=max(dp[j],temp[j]);
                
                
                if(dp[s/2])return 2;
            }
            
            
            return 0;
        }
    };