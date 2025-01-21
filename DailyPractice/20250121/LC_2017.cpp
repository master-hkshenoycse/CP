#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll suff[100005],pref[100005];    
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        ll ans=1e18;
        
        
        
        for(int i=1;i<=n;i++){
            pref[i]=pref[i-1]+grid[1][i-1];
          
        }
      
        for(int i=n;i>=1;i--){
            suff[i]=suff[i+1]+grid[0][i-1];
           
        }
       
        for(int i=1;i<=n;i++){
           
            ans=min(ans,max(suff[i+1],pref[i-1]));
        }
        
        
        
        return ans;
    }
};