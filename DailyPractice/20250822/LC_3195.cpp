#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        int mi_i=1e9,ma_i=-1e9,mi_j=1e9,ma_j=-1e9;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    mi_i=min(mi_i,i);
                    ma_i=max(ma_i,i);
                    mi_j=min(mi_j,j);
                    ma_j=max(ma_j,j);
                }
            }
        }
        
        return (ma_j-mi_j+1)*(ma_i-mi_i+1);
    }
};