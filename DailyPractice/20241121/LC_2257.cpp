#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int> >a(m,vector<int> (n,0));
        for(auto w:walls){
            a[w[0]][w[1]]=-1;
        }
        
        for(auto g:guards){
            a[g[0]][g[1]]=1;
        }
        
        
        
        for(int i=0;i<m;i++){
            int ls=-1;
            for(int j=0;j<n;j++){
                if(a[i][j]==-1){
                    ls=-1;
                }else if(a[i][j]==1){
                    ls=1;
                }else if(a[i][j]==2){
                    continue;
                }else{
                   if(ls==1)a[i][j]=2;
                }
            }
            
            ls=-1;
            for(int j=n-1;j>=0;j--){
                if(a[i][j]==-1){
                    ls=-1;
                }else if(a[i][j]==1){
                    ls=1;
                }else if(a[i][j]==2){
                    continue;
                }else{
                    if(ls==1)a[i][j]=2;
                }
            }
        }
        
         
        
        
        for(int j=0;j<n;j++){
            int ls=-1;
            for(int i=0;i<m;i++){
                if(a[i][j]==-1){
                    ls=-1;
                }else if(a[i][j]==1){
                    ls=1;
                }else if(a[i][j]==2){
                    continue;
                }else{
                    if(ls==1)a[i][j]=2;
                }
            }
            
            ls=-1;
            for(int i=m-1;i>=0;i--){
                if(a[i][j]==-1){
                    ls=-1;
                }else if(a[i][j]==1){
                    ls=1;
                }else if(a[i][j]==2){
                    continue;
                }else{
                    if(ls==1)a[i][j]=2;
                }
            }
        }
        
       
        
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==0){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};