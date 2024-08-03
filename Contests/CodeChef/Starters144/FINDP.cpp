#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// your code goes here
	
	ll t;
	cin>>t;
	
	while(t--){
	    
	    ll n,l,r;
	    cin>>n>>l>>r;
	    
	    ll ls_added=n;
	    ll req=r-l+1;
	    
	    deque<ll> ans;
	    
	    while(ls_added>0 and req>0){
	        ans.push_front(ls_added);
	        req-=ls_added;
	        ls_added--;
	    }
	    
	    req=l-1;
	    
	    for(ll i=ls_added;i>=1;i--){
	        if(req>=i){
	            ans.push_front(i);
	            req-=i;
	        }else{
	            ans.push_back(i);
	        }
	    }
	    
	    
	    for(auto e:ans){
	        cout<<e<<" ";
	    }
	    cout<<endl;
	    
	    
	    
	    
	}

}