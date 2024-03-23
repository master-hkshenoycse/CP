#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int> > csum(n+1,vector<int> (m+1,0));
        
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                csum[i][j]=csum[i-1][j]+csum[i][j-1]-csum[i-1][j-1]+grid[i-1][j-1];
                if(csum[i][j]<=k){
                    ans++;
                }
            }
        }
        return ans;
        
    }
};