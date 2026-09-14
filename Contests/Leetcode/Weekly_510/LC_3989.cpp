#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int n=grid.size(),m=grid[0].size();

        vector<vector<int> > is_comp(m,vector<int> (m,1));
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<n;k++){
                    if(abs(grid[k][i]-grid[k][j])>limit)
                        is_comp[i][j]=0;
                }
            }
        }

        vector<int> dp(m+1,1);
        dp[0]=0;
        int ans=0;

        for(int i=1;i<=m;i++){
            for(int j=1;j<i;j++){
                if(is_comp[i-1][j-1])
                    dp[i]=max(dp[i],dp[j]+1);
            }
            ans=max(ans,dp[i]);
        }
        return ans;

    }
};