#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int n=A.size();
        vector<vector<int> > dp(n,vector<int> (n,0));

        for(int l=2;l<n;l++){
            for(int i=0;i+l<n;i++){
                for(int j=i+1;j<i+l;j++){
                    if(dp[i][i+l]==0)dp[i][i+l]=A[i]*A[i+l]*A[j]+dp[i][j]+dp[j][i+l];
                    else dp[i][i+l]=min(dp[i][i+l],A[i]*A[i+l]*A[j]+dp[i][j]+dp[j][i+l]);
                }
            }
        }

        return dp[0][n-1];
    }
};