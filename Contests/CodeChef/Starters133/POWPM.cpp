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
        
        ll ans=0;
        vector<ll> a(n+1);
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
        
        for(ll i=1;i<=n;i++){
            if(a[i]==1){
                ans+=n;
            }else{
                ll curr=a[i];
                ll ind=1;
                
                while(curr<=1e9 and ind<=n){
                    if(curr <= a[ind]){
                        ans++;
                    }
                    curr=curr*a[i];
                    ind++;
                }
                
                
            }
        }
        
        cout<<ans<<endl;
        
    }
}
