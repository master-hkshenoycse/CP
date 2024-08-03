#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// your code goes here
	ll t;
	cin>>t;
	
	while(t--){
	    ll ex=0,n,x;
	    cin>>n>>x;
	    
	    vector<ll> a(n);
	    vector<ll> req;
	    ll ans=0;
	    for(ll i=0;i<n;i++){
	        cin>>a[i];
	        if(a[i]>x){
	            ex=ex+a[i]-x;
	            ans++;
	        }else{
	            req.push_back(x-a[i]);
	        }
	    }
	    
	    sort(req.begin(),req.end());
	    
	    for(auto r:req){
	        if(r<=ex){
	            ex-=r;
	            ans++;
	        }
	    }
	    
	    cout<<ans<<endl;
	     
	}

}