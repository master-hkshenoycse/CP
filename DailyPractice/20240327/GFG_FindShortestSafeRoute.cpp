#include<bits/stdc++.h>
using namespace std;

//multisource bfs
class Solution
{
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    
    
    int findShortestPath(vector<vector<int>> &mat){
       // code here
       vector<vector<int> > a=mat;
       int n=mat.size(),m=mat[0].size();
       
       queue<pair<int,int> > q;
       vector<vector<int> > dp(n,vector<int> (m,INT_MAX));
       
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(a[i][j]==1){
                   if(i-1>=0 and mat[i-1][j]==0){
                       a[i][j]=0;
                   }
                   if(i+1<n and mat[i+1][j]==0){
                       a[i][j]=0;
                   }
                   
                   if(j-1>=0 and mat[i][j-1]==0){
                       a[i][j]=0;
                   }
                   
                   if(j+1<m and mat[i][j+1]==0){
                       a[i][j]=0;
                   }
               }
               
               if(j==0 and a[i][j]){
                   q.push({i,j});
                   dp[i][j]=0;
               }
           }
       }
       

       while(q.size()>0){
           int x=q.front().first;
           int y=q.front().second;
           //cout<<x<<" "<<y<<endl;
           q.pop();
           
           if(y==m-1){
               return dp[x][y]+1;
           }
           for(int i=0;i<4;i++){
               int nx=x+dx[i];
               int ny=y+dy[i];
               if(nx>=0 and ny>=0 and nx<n and ny<m and a[nx][ny]==1 and dp[nx][ny]>dp[x][y]+1){
                   dp[nx][ny]=dp[x][y]+1;
                   q.push({nx,ny});
               }
           }
       }
       
       return -1;
       
       
    }
};