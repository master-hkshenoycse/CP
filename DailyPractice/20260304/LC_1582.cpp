#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        map<int,int> h_r,h_c;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]){
                    h_r[i]++;
                    h_c[j]++;
                }
            }
        }
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]){
                   ans+=(h_r[i]==1 && h_c[j]==1);
                }
            }
        }
        return ans;
        
        
        
    }
};