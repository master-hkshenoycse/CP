#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int> >sol(n-2,vector<int> (n-2,0));
        vector<int> dx={-1,0,1};
        vector<int> dy={-1,0,1};
        
        for(int i=1;i<n-1;i++){
            for(int j=1;j<n-1;j++){
                int ma=0;
                for(int x:dx){
                    for(int y:dy){
                        ma=max(ma,grid[i+x][j+y]);
                    }
                }
                sol[i-1][j-1]=ma;

            }
        }
        return sol;
    }
};