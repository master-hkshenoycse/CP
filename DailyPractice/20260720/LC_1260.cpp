#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int> > tmp=grid;
        int n=grid.size(),m=grid[0].size();
        
        while(k--){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(i==n-1 and j==m-1)tmp[0][0]=grid[i][j];
                    else if(j==m-1) tmp[i+1][0]=grid[i][j];
                    else tmp[i][j+1]=grid[i][j];
                }
            }
            grid=tmp;
        }
        
        return grid;
    }
};