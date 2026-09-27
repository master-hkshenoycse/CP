#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        int n=nums.size();
        vector<int> dp(sum+1,1e9);
        dp[0]=0;

        for(auto e:nums){
            int ops=0,value=e;
            vector<int> tmp(sum+1,1e9);
            
            while(value<=sum){

                for(int j=0;j<=sum-value;j++){
                    if(dp[j] != 1e9)
                        tmp[j+value]=min(tmp[j+value],dp[j]+ops);
                }

                value=value*2;
                ops++;
            }

            ops=0;
            value=e;
            while(value>0){

                for(int j=0;j<=sum-value;j++){
                    if(dp[j] != 1e9)
                        tmp[j+value]=min(tmp[j+value],dp[j]+ops);
                }

                value=value/2;
                ops++;
            }
            for(int j=0;j<=sum;j++)
                dp[j]=min(dp[j],tmp[j]);
            
        }
        if(dp[sum]==1e9)
            dp[sum]=-1;
        return dp[sum];
    }
};