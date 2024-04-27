#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        
        int x=0,y=0;
        int px=0,py=0;
        int d=0;
        
        while(x>=0 and x<n and y>=0 and y<m){
            px=x;
            py=y;
            
            if(matrix[x][y]){
                d=(d+1)%4;
                matrix[x][y]=0;
            }
            
            x=x+dx[d];
            y=y+dy[d];
            
        }
        
        return {px,py};
    }
};