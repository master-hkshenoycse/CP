#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> ret(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                ret[i]+=matrix[i][j];
        }   
        return ret;
    }
};