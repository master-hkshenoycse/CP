#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int> > col_max(n+1,vector<int> (m+1,0));

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                col_max[i][j]=max(col_max[i+1][j],grid[i][j]);
            }
        }


        int ans=INT_MIN;

        for(int i=n-1;i>=0;i--){
            int ma=0;
            for(int j=m-1;j>=0;j--){
                ma=max(ma,col_max[i+1][j]);
                if(i!=n-1 or j!=m-1)ans=max(ans,ma-grid[i][j]);
                ma=max(ma,col_max[i][j]);
            }
        }

        return ans;
    }
};