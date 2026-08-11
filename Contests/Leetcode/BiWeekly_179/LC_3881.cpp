#define ll long long
#include<bits/stdc++.h>
using namespace std;
ll mod=1e9+7;
    ll fact[100001],inv_fact[100001];
    ll pre_done=0;
    ll modpow(ll a,ll n){
        ll ret=1;
        while(n>0){
            if(n%2)
                ret=(ret *a)%mod;
            n/=2;
            a=(a*a)%mod;
        }
        return ret;
    }
    ll ncr(ll n,ll r){
        if(r>n) return 0;
        ll ret=fact[n];
        ret=(ret*inv_fact[r])%mod;
        ret=(ret*inv_fact[n-r])%mod;
        return ret;
    }
    void pre_cum(){
        if(pre_done)
            return;
        
        pre_done=1;
        fact[0]=1;
        inv_fact[0]=1;
        for(int i=1;i<=100000;i++){
            fact[i]=(fact[i-1] * i)%mod;
            inv_fact[i]=modpow(fact[i],mod-2);
        }

    }
class Solution {
public:
    
    int countVisiblePeople(int n, int pos, int k) {
        ll tot_left=pos;
        ll tot_right=n-pos-1;
        pre_cum();
        ll ans=0;
        for(ll i=0;i<=k;i++){
            ans=ans+(ncr(tot_left,i)*ncr(tot_right,k-i))%mod;
            ans%=mod;
        }

        ans=(ans*2)%mod;
        return ans;

        

    }
};