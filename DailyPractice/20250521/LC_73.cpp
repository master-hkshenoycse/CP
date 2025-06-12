#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int n=matrix.size();
            int m=matrix[0].size();
            
            vector<int> row_(n,0),col_(m,0);
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(matrix[i][j]==0){
                        row_[i]=1;
                        col_[j]=1;
                    }
                }
            }
            
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(row_[i] or col_[j]){
                        matrix[i][j]=0;
                    }
                }
            }
        }
    };