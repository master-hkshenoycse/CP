#include <bits/stdc++.h>
#define ll long long
using namespace std;

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
	    
	    ll last=0,ans=0;
	        
	    //optimal to take the lesser value.
	    for(ll i=1;i<n;i++){
	        if(a[i]<a[last]){
	            ans=ans+(i-last)*a[last];
	            last=i;
	        }
	    }
	    
	    reverse(a.begin(),a.end());
	    last=0;
	    
	    for(ll i=1;i<n;i++){
	        if(a[i]<=a[last]){
	            ans=ans+(i-last)*a[last];
	            last=i;
	        }
	    }
	    
	    cout<<ans<<endl;
	    
	    
	}

}
