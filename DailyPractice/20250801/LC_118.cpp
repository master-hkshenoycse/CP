#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > sol(numRows);

        for(int i=0;i<numRows;i++){
            sol[i].resize(i+1);
            
            for(int j=0;j<=i;j++){
                if(j==0 or j==i)sol[i][j]=1;
                else sol[i][j]=sol[i-1][j-1]+sol[i-1][j];
            }
        }
        return sol;
    }
};