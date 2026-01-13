#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();

        int ans=0,i=0,j=m-1;
        while(i<n and j>=0){
            if(grid[i][j]<0){
                ans=ans+(n-i);
                j--;
            }else{
                i++;
            }
        }

        return ans;
    }
};