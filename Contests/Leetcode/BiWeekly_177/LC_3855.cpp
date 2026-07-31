#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll mod=1e9+7;
    ll modpow(ll a,ll n){
        ll res=1;
        while(n>0){
            if(n%2)res=(res * a)%mod;
            n/=2;
            a=(a*a)%mod;
        }
        return res;
    }
    int sumOfNumbers(int l, int r, int k) {
        ll ways=modpow(r-l+1,k-1);
        ll sum_po=(modpow(10,k)-1+mod)%mod;
        sum_po=(sum_po * modpow(9,mod-2))%mod;
        ll mul=(ways * sum_po)%mod;
        ll ans=0;

        for(ll i=l;i<=r;i++){
            ans=(ans+(mul*i)%mod)%mod;
        }

        return ans;
    }
};