#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            //setting the most significant bit in all rows as 1 by row toggling
            if(grid[i][0]==0){
                for(int j=0;j<m;j++){
                    grid[i][j]=1-grid[i][j];
                }
            }
        }
        int ans=(1<<(m-1))*n;

        //for remaining columns toggle based on count
        for(int j=1;j<m;j++){
            int cnt=0;
            for(int i=0;i<n;i++){
                cnt=cnt+grid[i][j];
            }

            cnt=max(cnt,n-cnt);
            ans=ans+(1<<(m-j-1))*cnt;
        }

        return ans;

    }
};