#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	// your code goes here
	ll t;
	cin>>t;
	
	while(t--){
	    ll n;
	    cin>>n;
	    
	    ll ans=0;
	    
	    ll rep=n/9;
	    ll rem=n%9;
	    ans=45*rep;
	    for(ll i=0;i<=rem;i++){
	        ans=ans+i;
	    }
	   
	    cout<<ans<<endl;
	}

}
