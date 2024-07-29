#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<ll> > dp(26,vector<ll> (26,1e10));
        
        for(ll i=0;i<26;i++){
            dp[i][i]=0;
        }
        
        ll sz=original.size();
        for(ll i=0;i<sz;i++){
            dp[original[i]-'a'][changed[i]-'a']=min(dp[original[i]-'a'][changed[i]-'a'],cost[i]*1ll);
        }
        
        for(ll k=0;k<26;k++){
            for(ll i=0;i<26;i++){
                for(ll j=0;j<26;j++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        
        ll ans=0;
        ll n=source.size();
        
        for(ll i=0;i<n;i++){
            if(dp[source[i]-'a'][target[i]-'a'] == 1e10){
                return -1;
            }
            
            ans=ans+dp[source[i]-'a'][target[i]-'a'];
        }
        
        return ans;
    }
};