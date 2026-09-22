#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int> > dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mat[i-1][j-1]==1){
                    dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                }
            }
        }
        
        int ret=0,lo=1,hi=n;

        while(hi>=lo){
            int mid=(hi+lo)/2;
            int min_i=n+1,max_i=-1,min_j=m+1,max_j=-1;

            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(dp[i][j]>=mid){
                        min_i=min(min_i,i-mid+1);
                        min_j=min(min_j,j-mid+1);
                        max_i=max(max_i,i-mid+1);
                        max_j=max(max_j,j-mid+1);
                    }
                }
            }

            if(max_i-min_i>=mid || max_j-min_j>=mid){
                ret=max(ret,mid*mid);
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }

        return ret;
    }
};