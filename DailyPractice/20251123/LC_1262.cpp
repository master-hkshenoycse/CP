#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3,-1e9);
        dp[0]=0;
        for(auto e:nums){
            vector<int> tmp(3,-1e9);
            for(int j=0;j<3;j++){
                tmp[(j+e)%3]=max(tmp[(j+e)%3],dp[j]+e);
            }
            
            if(e%3==0){
                dp[0]=max(dp[0],e);
            }

            if(e%3==1){
                dp[1]=max(dp[1],e);
            }
            
            if(e%3==2){
                dp[2]=max(dp[2],e);
            }
            
            dp[0]=max(dp[0],tmp[0]);
            dp[1]=max(dp[1],tmp[1]);
            dp[2]=max(dp[2],tmp[2]);
        }

        return dp[0];
    }
};