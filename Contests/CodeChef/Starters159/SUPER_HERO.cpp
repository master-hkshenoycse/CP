
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// your code goes here
    ll t;
    cin>>t;
    
    while(t--){
        ll h,k;
        cin>>h>>k;
        ll ans=0;
        for(ll i=2;i*i<=h;i++){
            if(h%i==0){
                while(h%i==0){
                    ans++;
                    h/=i;
                }
            }
        }
        
        if(h>1){
            ans++;
        }
        
        ll curr=1;
        while(curr *2<=k){
            curr=curr*2;
            ans++;
        }
        
        cout<<ans<<endl;
    }
}
