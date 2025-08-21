#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll get_pow(ll a,ll n){
        ll res=1;
        while(n){
            if(n%2){
                res=(res*a);
            }
            n/=2;
            a=(a*a);
        }
        return res;
    }
    ll mod=1e9+7;

    
    
    int numberOfWays(int n, int x) {
       vector<ll> dp(n+1,0);
        dp[0]=1;
        
        for(ll i=1;get_pow(i,x)<=n;i++){
            ll p=get_pow(i,x);
            for(ll j=n;j>=1;j--){
                if(j-p>=0){
                    dp[j]=(dp[j]+dp[j-p])%mod;
                }
            }
            
            
        }
        
        return dp[n];
    
    }
};