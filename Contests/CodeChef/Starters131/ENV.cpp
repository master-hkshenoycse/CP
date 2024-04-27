#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll mod=1e9+7;
int main() {
	// your code goes here
	ll t;
	cin>>t;
	
	while(t--){
	    ll n;
	    cin>>n;
	    
	    vector<ll> a(n);
	    for(ll i=0;i<n;i++){
	        cin>>a[i];
	    }
	    
	    sort(a.begin(),a.end());
	    
	    ll s=0;
	    ll do_mul=0;
	    for(ll i=0;i<n;i++){
	        if(do_mul==0 and s+a[i] >= s*a[i]){
	            s=s+a[i];
	        }else{
	            s=(s*a[i])%mod;
	            do_mul=1;
	        }
	    }
	    
	    cout<<s<<endl;
	}

}
