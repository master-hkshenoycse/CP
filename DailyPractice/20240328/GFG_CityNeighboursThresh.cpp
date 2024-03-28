#include<bits/stdc++.h>
using namespace std;
//using floyd warshall algo

class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        vector<vector<int> >  dp(n,vector<int> (n,1e9));
        for(int i=0;i<n;i++){
            dp[i][i]=0;
        }
        
        for(auto e:edges){
            dp[e[0]][e[1]]=min(dp[e[0]][e[1]],e[2]);
            dp[e[1]][e[0]]=min(dp[e[1]][e[0]],e[2]);
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        
        
        
        int cnt=INT_MAX,ans=-1;
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(j!=i and dp[i][j]<=distanceThreshold){
                    c++;
                }
            }
            
            //cout<<i<<" "<<c<<endl;
            if(c<=cnt){
                cnt=c;
                ans=i;
            }
        }
        return ans;
    }
};