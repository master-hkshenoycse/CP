#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int prev=-1;
        int n=grid.size(),m=grid[0].size();
        
        for(int j=0;j<m;j++){
            
            for(int i=1;i<n;i++){
                if(grid[i][j] != grid[i-1][j]){
                    return 0;
                }
            }
            
            if(prev==grid[0][j]){
              return 0;
            }
            prev=grid[0][j];
        }
        
        return 1;
    }
};