#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll mod=1e9+7;
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
int main() {
    
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        
        ll ans=0;
        for(ll len=1;len<=n-1;len++){
            ll value=(len*len)%mod;
            ll contribution=modpow(2,n-len);
            ll no_ocurences=(n-len);
            contribution=(contribution * no_ocurences)%mod;
            value=(value * contribution)%mod;
            
            ans=(ans+value)%mod;
        }
        
        cout<<ans<<endl;
    }
    
    
    

}
