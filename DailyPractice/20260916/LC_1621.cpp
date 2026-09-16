#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll mod=1e9+7;
    ll inv_mod(ll v){
        ll res=1;
        ll po=mod-2;
        while(po){
            if(po%2)res=(res*v)%mod;
            v=(v*v)%mod;
            po/=2;
        }
        return res;
    }
    ll get_comb(ll n,ll r){
        if(r>n)return 0;
        
        ll fact_n=1,fact_r=1,fact_n_r=1;
        for(int i=1;i<=n;i++) fact_n=(fact_n*i)%mod;

        for(int i=1;i<=r;i++) fact_r=(fact_r*i)%mod;

        for(int i=1;i<=n-r;i++) fact_n_r=(fact_n_r*i)%mod;

        ll ans=fact_n;
        ans=ans*inv_mod(fact_r);
        ans%=mod;
        ans=ans*inv_mod(fact_n_r);
        ans%=mod;
        return ans;    
    }
        
     int numberOfSets(int n, int k) {
       
       int u=n+k-1;
       int l=n-(k+1);
      
       return (int)get_comb(u*1ll,l*1ll);
    
    }
};