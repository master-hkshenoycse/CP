#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    ll n,k,q;
    cin>>n>>k;

    cin>>q;

    vector<vector<ll> > field(n+1,vector<ll>(n+1,0));
    ll r,c,v;
    ll ret=0;
    while(q--){
        cin>>r>>c>>v;
        field[r][c]=v;

        
        for(ll i=max(1ll,r+1-k);i+k-1<=n && (i<=r);i++){
            for(ll j=max(1ll,c+1-k);j+k-1<=n && j<=c;j++){
                ll curr=0;
                for(ll x=i;x<=i+k-1;x++){
                    for(ll y=j;y<=j+k-1;y++){
                        curr+=field[x][y];
                    }
                }
                ret=max(ret,curr);
            }
        }


        cout<<ret<<endl;
    }
    return 0;
}