#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll mod=1e9+7;
    
    ll modpow(ll a,ll n){
        ll res=1;
        while(n){
            if(n%2)res=(res*a)%mod;
            n/=2;
            a=(a*a)%mod;
        }
        return res;
    }
    
    int countGoodNumbers(long long n) {
        ll od_pos=n/2;
        ll ans=1;
        
        ans=modpow(4,od_pos);
        ll u=modpow(5,n-od_pos);
        u%=mod;
        
        ans=(ans*u)%mod;
        
        
        return (int) ans;
            
    }
};