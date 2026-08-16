#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> cost(n);

        if (k == 0) return 0;
        if (k > n / 2) return -1;

        for(int i=0;i<n;i++){
            int left_idx = (i==0)?n-1:i-1;
            int right_idx = (i==n-1)?0:i+1;
            cost[i]=max(0,max(nums[right_idx],nums[left_idx])+1-nums[i]);
        }

        auto solve_dp = [&](bool pick_first) -> int{
            vector<array<int,2> > dp(k+1,{INT_MAX,INT_MAX});
            //dp[i][0] -> picked i items so far , and last not picked
            //dp[i][1] -> picked i items so far , and last picked.
            if(pick_first)
                dp[1][1]=cost[0];
            else
                dp[0][0]=0;
            
            for(int i=1;i<n;i++){
                vector<array<int,2> > ndp(k+1,{INT_MAX,INT_MAX});
                for(int j=0;j<=k;j++){
                    ndp[j][0]=min(dp[j][0],dp[j][1]);
                    if(j>0 && dp[j-1][0]!=INT_MAX)ndp[j][1]=dp[j-1][0]+cost[i];
                }
                dp=ndp;
            }

            if(pick_first)
                return dp[k][0];
            else
                return min(dp[k][1],dp[k][0]);
        };

        return min(solve_dp(0),solve_dp(1));
    }
};