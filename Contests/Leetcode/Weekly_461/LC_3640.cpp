#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maxSumTrionic(vector<int>& a) {
        ll n=a.size();
        vector<vector<ll> > dp(4,vector<ll> (n,-1e18));
        ll ans=-1e18;
        for(ll i=0;i<n;i++){
            dp[0][i]=a[i];
            if(i>0){
                if(a[i]>a[i-1])dp[1][i]=max(dp[0][i-1]+a[i],dp[1][i-1]+a[i]);//increasing phase
                if(a[i]<a[i-1])dp[2][i]=max(dp[2][i-1]+a[i],dp[1][i-1]+a[i]);//decresing phase
                if(a[i]>a[i-1])dp[3][i]=max(dp[2][i-1]+a[i],dp[3][i-1]+a[i]);//second increaing
            }   

            ans=max(ans,dp[3][i]);
        }

        return ans;
    }
};