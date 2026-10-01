#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        for(int i=0;i<n;i++){
            vector<int> tmp(n);
            for(int j=0;j<n;j++)
                tmp[(j-rowShift[i]+n)%n]=grid[i][j];
            grid[i]=tmp;
        }

        for(int i=0;i<n;i++){
            vector<int> tmp(n);
            for(int j=0;j<n;j++)
                tmp[(j-colShift[i]+n)%n]=grid[j][i];
            
            for(int j=0;j<n;j++)
                grid[j][i]=tmp[j];

        }

        return grid;

    }
};