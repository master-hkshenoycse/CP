#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int c1=0,c2=0,c0=0;
        
        int y_c1=0,y_c2=0,y_c0=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                
                
                if((i==j and i<=n/2) or (i+j==n-1 and i<=n/2) or(j==n/2 and i>n/2)){
                    y_c0+=(grid[i][j]==0);
                    y_c1+=(grid[i][j]==1);
                    y_c2+=(grid[i][j]==2);
                    //cout<<i<<" "<<j<<endl;
                    
                }else{
                    c0+=(grid[i][j]==0);
                    c1+=(grid[i][j]==1);
                    c2+=(grid[i][j]==2);    
                }
            }
        }
        
        int ans=n*n;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                
                if(i==j){
                    continue;
                }
                
                int ops=0;
                if(i==0){
                    ops+=(c1+c2);
                }else if(i==1){
                    ops+=(c0+c2);
                }else{
                    ops+=(c0+c1);
                }
                
                if(j==0){
                    ops+=(y_c1+y_c2);
                }else if(j==1){
                    ops+=(y_c0+y_c2);
                }else{
                    ops+=(y_c0+y_c1);
                }
                
                ans=min(ans,ops);
                
            }
        }
        
        return ans;
    }
};