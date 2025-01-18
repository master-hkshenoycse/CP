#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),skip=0;
        vector<int> ret;

        for(int i=0;i<n;i++){
            if(i%2==0){
                for(int j=0;j<m;j++){
                    if(skip==0){
                        ret.push_back(grid[i][j]);
                    }
                    skip=1-skip;
                }
            }else{

                for(int j=m-1;j>=0;j--){
                    if(skip==0){
                        ret.push_back(grid[i][j]);
                    }
                    skip=1-skip;
                }

            }
        }


        return ret;
    }
};