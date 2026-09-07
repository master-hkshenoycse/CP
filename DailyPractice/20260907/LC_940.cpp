#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll mod=1e9+7;
    int distinctSubseqII(string s) {
        int n=s.size();

        vector<ll> dp(n+1,0);
        vector<ll> ls_cnt(26,-1);
        dp[0]=1;

        for(int i=1;i<=n;i++){
            dp[i]=(dp[i-1]*2)%mod;

            ll x=s[i-1]-'a';
            if(ls_cnt[x] != -1){
                dp[i]=(dp[i]-dp[ls_cnt[x]-1]);
                dp[i]=(dp[i]+mod)%mod;
            }
            ls_cnt[x]=i;
        }
        dp[n]--;
        if(dp[n]<0){
            dp[n]+=mod;
        }
        return dp[n];

    
    }
};