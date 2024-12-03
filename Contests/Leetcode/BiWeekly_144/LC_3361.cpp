#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        ll ans=0,n=s.size();
        vector<vector<ll> > dp(26,vector<ll> (26,1e18));
        for(ll i=0;i<26;i++){
            dp[i][i]=0;
        }    

        for(ll i=0;i<26;i++){
            ll nx=(i+1)%26;
            ll pr=(i-1+26)%26;
            dp[i][nx]=min(dp[i][nx],nextCost[i]*1ll);
            dp[i][pr]=min(dp[i][pr],previousCost[i]*1ll);
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }

        for(ll i=0;i<n;i++){
            ans=ans+dp[s[i]-'a'][t[i]-'a'];
        }


        return ans;
    }
};