#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// your code goes here
	ll t;
	cin>>t;
	
	while(t--){
	    ll sum=0,range=0;
	    ll e,n,k;
	    cin>>n>>k;
	    
	    for(ll i=1;i<=n;i++){
	        cin>>e;
	        if(e%k==0){
	            sum=sum+e/k;
	        }else{
	            range++;
	            if(e>0){
	                sum=sum+e/k;
	            }else{
	                sum=sum+e/k-1;
	            }
	        }
	    }
	    

	    
	    if(sum<=0 and sum+range>=0){
	        cout<<"YES"<<endl;
	    }else{
	        cout<<"NO"<<endl;
	    }
	    
	}

}
