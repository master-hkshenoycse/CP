#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll mod=1e9+7;
ll fact[200005],inv_fact[200005];
ll modpow(ll a,ll n){
    ll res=1;
    while(n>0){
        if(n%2){
            res=(res * a)%mod;
        }
        n/=2;
        a=(a*a)%mod;
    }
    return res;
}

void prec(){
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
int main() {
	// your code goes here
	prec();
    ll t;
    cin>>t;
    
    while(t--){
        ll n,k;
        cin>>n>>k;
        
        ll tot_pairs=0;
        for(ll i=1;i<=n;i++){
            if(k-i>=1 and k-i<=n and k-i !=i ){
                tot_pairs++;
            }
        }
        
        tot_pairs/=2ll;
        
        ll ans=0;
        
        for(ll i=1;i<=tot_pairs;i++){
            ll ways_pairs=ncr(tot_pairs,i);
            ll ways_others=fact[n-i];
            ll ways=(ways_pairs * modpow(2,i))%mod;
            ways=(ways * ways_others)%mod;
            
            if(i%2){
                ans=(ans+ways)%mod;
            }else{
                ans=(ans-ways+mod)%mod;
            }
        }
        
        
        cout<<ans<<endl;
    }
}
