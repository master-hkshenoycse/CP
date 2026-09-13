#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;    
    int chk(int x,int y){
        if(x>=0 && x<n && y>=0 && y<n)return 1;
        return 0;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        n=A.size();
        int ans=0;
        
        for(int offx=-n;offx<=n;offx++){
          for(int offy=-n;offy<=n;offy++){
              int sol=0;
              for(int i=0;i<n;i++){
                  for(int j=0;j<n;j++){
                      if(chk(i+offx,j+offy) && A[i][j]==B[i+offx][j+offy] && A[i][j]==1)sol++;
                  }
              }
              ans=max(ans,sol);
              
          }
        }
        return ans;
    }
};