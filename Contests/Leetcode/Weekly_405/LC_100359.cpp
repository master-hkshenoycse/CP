#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        vector<vector<int> > freq_x(n+1,vector<int> (m+1,0));
        vector<vector<int> > freq_y(n+1,vector<int> (m+1,0));
        int ans=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                freq_x[i][j]=freq_x[i-1][j]+freq_x[i][j-1]-freq_x[i-1][j-1];
                freq_y[i][j]=freq_y[i-1][j]+freq_y[i][j-1]-freq_y[i-1][j-1];
                
                if(grid[i-1][j-1]=='X'){
                    freq_x[i][j]++;
                }
                
                if(grid[i-1][j-1]=='Y'){
                    freq_y[i][j]++;
                }
                

                if(freq_x[i][j]==freq_y[i][j] and freq_x[i][j]>0){
                    ans++;
                }
                
            }
            
            cout<<endl;
        }
        
        return ans;
    }
};