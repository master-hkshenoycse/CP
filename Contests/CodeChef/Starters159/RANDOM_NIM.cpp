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
        a=(a * a)%mod;
    }
    return res;
}
int main() {
	// your code goes here
	ll t;
	cin>>t;
	
	while(t--){
	    ll n,d;
	    cin>>n>>d;
	    
	    ll xo=0,e;
	    
	    for(ll i=1;i<=n;i++){
	        cin>>e;
	        xo=(xo ^ e);
	    }
	    ll ans;
	    if(xo==0){
	        ans=d-1;
	    }else{
	        ans=d+1;
	    }
	    
	    ans=(ans * modpow((2*d)%mod,mod-2))%mod;
	    
	    cout<<ans<<endl;
	}

}
