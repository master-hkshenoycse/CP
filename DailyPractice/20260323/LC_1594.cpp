#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        ll n=grid.size(),m=grid[0].size();
        ll mod=1e9+7;
        vector<vector<ll> >dp1(n+1,vector<ll> (m+1,-3e18));
        vector<vector<ll> >dp2(n+1,vector<ll> (m+1,3e18));
        
        dp1[1][1]=grid[0][0];
        dp2[1][1]=grid[0][0];
        
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                if(i==1 and j==1){
                    continue;
                }
                
                if(i-1>=1){
                    dp1[i][j]=max(dp1[i][j],dp1[i-1][j]*grid[i-1][j-1]);
                    dp1[i][j]=max(dp1[i][j],dp2[i-1][j]*grid[i-1][j-1]);
                    
                    
                    dp2[i][j]=min(dp2[i][j],dp2[i-1][j]*grid[i-1][j-1]);
                    dp2[i][j]=min(dp2[i][j],dp1[i-1][j]*grid[i-1][j-1]);
                }
                
                if(j-1>=1){
                    dp1[i][j]=max(dp1[i][j],dp1[i][j-1]*grid[i-1][j-1]);
                    dp1[i][j]=max(dp1[i][j],dp2[i][j-1]*grid[i-1][j-1]);
                    
                    
                    dp2[i][j]=min(dp2[i][j],dp2[i][j-1]*grid[i-1][j-1]);
                    dp2[i][j]=min(dp2[i][j],dp1[i][j-1]*grid[i-1][j-1]);
                }
            }
            
        }
        
        if(dp1[n][m]<0){
            return -1;
        }
        
        cout<<dp1[n][m]<<" "<<dp2[n][m]<<endl;
        return (dp1[n][m]%mod);
        
    }
};