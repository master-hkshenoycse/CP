#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    ll n,q;
    cin>>n>>q;

    vector<ll> prices(n+1);
    for(ll i=1;i<=n;i++){
        cin>>prices[i];
    }

    for(ll i=2;i<=n;i++){
        prices[i]=min(prices[i],prices[i-1]*2);
    }

    while(prices.size()<=36){
        prices.push_back(prices.back()*2);
    }

    while(prices.size()>36){
        prices.pop_back();
    }

    while(q--){
        ll amt;
        cin>>amt;
        

        ll curr=0,ret=1e18;

        for(ll i=35;i>=1;i--){
            ll po=(1ll<<(i-1));
            if(amt & po){
                curr+=prices[i];
            }else{
                ret=min(ret,curr+prices[i]);
            }
            
        }

        ret=min(ret,curr);
        cout<<ret<<endl;
    }


}
