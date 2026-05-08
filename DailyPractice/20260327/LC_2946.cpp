#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int> >x=mat;
        int n=mat.size(),m=mat[0].size();
        
        
        for(int i=0;i<n;i++){
            if(i%2==0){
                for(int j=0;j<m;j++){
                    x[i][j]=mat[i][(j+k)%m];
                }
            }else{
                for(int j=0;j<m;j++){
                    x[i][j]=mat[i][((j-k)%m+m)%m];
                }
            }
        }
        
        return x==mat;
    }
};