#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1e9+7;
ll fact[200005],inv_fact[200005];
ll pre=0;
ll modpow(ll a,ll n){
    ll res=1;
    while(n>0){
        if(n%2){
            res=(res * a)%mod;
        }
        a=(a*a)%mod;
        n/=2;
    }
    return res;
}
void pre_cum(){
    if(pre){
        return ;
    }
    pre=1;
    fact[0]=1;
    inv_fact[0]=1;
    
    for(ll i=1;i<=200000;i++){
        fact[i]=(fact[i-1]*i)%mod;
        inv_fact[i]=modpow(fact[i],mod-2);
    }
}

ll ncr(ll n,ll r){
    if(r>n){
        return 0;
    }
    
    ll ret=fact[n];
    ret=(ret * inv_fact[r])%mod;
    ret=(ret * inv_fact[n-r])%mod;
    return ret;
}
class Solution {
public:
    int minMaxSums(vector<int>& nums, int k) {
        map<int,int> help;
        pre_cum();
        for(auto e:nums){
            help[e]++;
        }
        
        vector<int> values;
        for(auto it:help){
            values.push_back(it.first);
        }
        
        int sz=values.size();
        int tot=0;
        ll ans=0;
        for(int i=0;i<sz;i++){
            tot=tot+help[values[i]];
            
            for(ll j=1;j<=k;j++){
                ll tot_ways=(ncr(tot,j)-ncr(tot-help[values[i]],j))%mod;
                tot_ways=(tot_ways+mod)%mod;
                ans=ans+(tot_ways*values[i])%mod;
                ans%=mod;
            }
        }
        
        tot=0;
        for(int i=sz-1;i>=0;i--){
            tot=tot+help[values[i]];
            
            for(ll j=1;j<=k;j++){
                ll tot_ways=(ncr(tot,j)-ncr(tot-help[values[i]],j))%mod;
                tot_ways=(tot_ways+mod)%mod;
                ans=ans+(tot_ways*values[i])%mod;
                ans%=mod;
            }
        }
        
        return ans;
        
        
        
    }
};