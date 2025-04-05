#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            int n=grid.size();
            int m=grid[0].size();
            
            vector<int> vals;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    vals.push_back(grid[i][j]);
                }
            }
            sort(vals.begin(),vals.end());
            
            for(int i=1;i<n*m;i++){
                if((vals[i]-vals[i-1])%x){
                    return -1;
                }
            }
            
            int mid=(vals[(n*m)/2]);
            int s=0;
            for(int i=0;i<n*m;i++){
                s=s+abs(mid-vals[i]);
            }
            
            return s/x;
        }
    };