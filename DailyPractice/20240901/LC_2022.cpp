#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int> > sol(m,vector<int>(n,-1));
        int x=original.size();
        
        if(x != n*m){
            vector<vector<int> > sol;
            return sol;
        }
        for(int i=0;i<x;i++){
            sol[i/n][i%n]=original[i];
        }
        
        return sol;
        
    
    }
};