#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<ll,ll> help;
        for(auto p:power){
            help[p]++;
        }
        
        vector<pair<ll,ll> > a;
        for(auto it:help){
            a.push_back({it.first,it.second});
        }
        
        ll n=a.size();       
        vector<ll> dp(n,0);
        ll ans=0;
        
        for(ll i=0;i<n;i++){
            ll value=a[i].first*a[i].second;
            
            dp[i]=value;
            if(i-1>=0){
                dp[i]=max(dp[i],dp[i-1]);
            }
            
            if(i-1>=0 and abs(a[i-1].first-a[i].first)>2){
                dp[i]=max(dp[i],dp[i-1]+value);
            }
            
            if(i-2>=0 and abs(a[i-2].first-a[i].first)>2){
                dp[i]=max(dp[i],dp[i-2]+value);
            }
            if(i-3>=0 and abs(a[i-3].first-a[i].first)>2){
                dp[i]=max(dp[i],dp[i-3]+value);
            }
            ans=max(ans,dp[i]);
            
        }
        return ans;
    }
};