#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();

        vector<vector<int> > height(n,vector<int> (m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    height[i][j]=0;
                }else{
                    height[i][j]=1;
                    if(i-1>=0){
                        height[i][j]+=height[i-1][j];
                    }
                }
            
            }
            
        }

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                int k=j;
                int ma_height=height[i][j];
                
                while(k<m and ma_height>0){
                    ma_height=min(ma_height,height[i][k]);
                    ans=ans+ma_height;
                    k++;
                }

            }
        }

        return ans;
        
    }
};