#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll get_contri(ll pos,ll moves){
    ll ret=0;
    while(moves>=0 and pos>=0){
        ret=ret+(1ll<<pos);
        pos--;
        moves--;
    }
    
    return ret;
}
int main() {
	// your code goes here
	ll t;
	cin>>t;
	
	while(t--){
	    ll n,x;
	    cin>>x>>n;
	    
	    ll ans=0;
	    
	    for(ll i=60;i>=0;i--){
	        ll c=get_contri(i,min(n-1,i+1));
	        if(c<=x){
	            x-=c;
	            ans+=(1ll<<i);
	        }
	    }
	    
	    if(x>0){
	        ans=-1;
	    }
	    
	    cout<<ans<<endl;
	}

}
