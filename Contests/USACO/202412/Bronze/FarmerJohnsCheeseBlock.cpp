#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    ll n,q;
    cin>>n>>q;

    map<pair<ll,ll>,ll> mp_xy,mp_yz,mp_xz;
    ll ans=0;

    while(q--){
        ll x,y,z;
        cin>>x>>y>>z;

        mp_xy[{x,y}]++;
        mp_yz[{y,z}]++;     
        mp_xz[{x,z}]++;

        if(mp_xy[{x,y}]==n){
            ans++;
        }

        if(mp_yz[{y,z}]==n){
            ans++;
        }

        if(mp_xz[{x,z}]==n){
            ans++;
        }

        cout<<ans<<endl;
    }
}