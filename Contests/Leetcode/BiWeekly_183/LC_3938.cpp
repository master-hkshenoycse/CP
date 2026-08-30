#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_kadane2(vector<int> &arr){
        int n=arr.size();
        vector<int> dp(n);
        dp[0]=arr[0];
        int ret=INT_MIN;
        for(int i=1;i<n;i++){
            dp[i]=max(arr[i],dp[i-1]+arr[i]);
            ret=max(ret,dp[i-1]+arr[i]);
        }

        return ret;   
    }
    int maxScore(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();

        int ans=INT_MIN;
        //Case 1: Single interior shared shell
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                ans=max(ans,grid[i][j]);
            }
        }

        //Case 2: Shared segment lies in a row
        for(int i=0;i<n;i++)
            ans=max(ans,get_kadane2(grid[i]));
        
        //Case 3: Shared segment lies in a column
        for(int j=0;j<m;j++){
            vector<int> col;
            for(int i=0;i<n;i++)
                col.push_back(grid[i][j]);
            
            ans=max(ans,get_kadane2(col));
        }

        return ans;

    }
};