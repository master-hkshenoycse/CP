#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int row_palindrome=0,col_palindrome=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m/2;j++){
                row_palindrome+=(grid[i][j] != grid[i][m-j-1]);
            }
        }
        
        for(int j=0;j<m;j++){
            for(int i=0;i<n/2;i++){
                col_palindrome+=(grid[i][j] != grid[n-i-1][j]);
            }
        }
        
        return min(row_palindrome,col_palindrome);
    }
};