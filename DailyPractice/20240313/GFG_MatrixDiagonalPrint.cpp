#include<bits/stdc++.h>
using namespace std;

vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
         int n=mat.size(),m=mat[0].size();
         vector<int> sol;
         
         for(int k=0;k<n+m-1;k++){
             if(k%2==0){
                 for(int i=min(k,n-1);i>=0 and k-i<m;i--){
                     sol.push_back(mat[i][k-i]);
                 }
             }else{
                 for(int i=min(k,m-1);i>=0 and k-i<n;i--){
                     sol.push_back(mat[k-i][i]);
                 }
             }
         }
         
         return sol;
    }