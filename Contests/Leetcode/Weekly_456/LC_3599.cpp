#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minXor(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> c_xor(n+1,0);
        for(int i=1;i<=n;i++){
            c_xor[i]=(c_xor[i-1] ^ nums[i-1]);
        }

        vector<vector<int> >dp(n+1,vector<int> (k+1,INT_MAX));
        dp[0][0]=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                for(int p=1;p<=min(i,k);p++){
                    dp[i][p]=min(dp[i][p],max(dp[j-1][p-1],c_xor[i]^c_xor[j-1]));
                }
            }
        }

        return dp[n][k];
    }
};