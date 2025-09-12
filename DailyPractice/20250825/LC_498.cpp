#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> sol;
        int n=matrix.size();
        
        if(n==0)return sol;
        
        int m=matrix[0].size();
        vector< vector<int> > inter(n+m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                inter[i+j].push_back(j);
            }
        }
        
        int ls=0;
        
        for(int i=0;i<n+m-1;i++){
            
            sort(inter[i].begin(),inter[i].end());
            int x=inter[i].size();
            
            //cout<<i<<" "<<x<<endl;
            
            if(ls%2) for(int j=x-1;j>=0;j--)sol.push_back(matrix[i-inter[i][j]][inter[i][j]]);
            else for(int j=0;j<x;j++)sol.push_back(matrix[i-inter[i][j]][inter[i][j]]);
                
            ls++;
        }
        
        return sol;
        
        
        
        
        
    }
};