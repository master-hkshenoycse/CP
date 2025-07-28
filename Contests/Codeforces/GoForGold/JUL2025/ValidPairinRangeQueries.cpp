#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n,q;
    cin>>n>>q;

    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a.begin(),a.end());
    map<ll,ll> cnt;

    vector<vector<ll> > queries;
    ll x,y;
    for(ll i=0;i<q;i++){
        cin>>x>>y;
        queries.push_back({y,x,i});
    }

    sort(queries.begin(),queries.end());
    vector<ll> sol(q,0);

    ll j=0;
    for(auto qu:queries){
        ll x=qu[1];
        ll y=qu[0];
        ll ind=qu[2];

        while(j<n && a[j]<y){
            cnt[a[j]]++;
            j++;
        }

        sol[ind]=cnt[x]*(j-cnt[x]);
    }

    for(ll i=0;i<q;i++){
        cout<<sol[i]<<endl;
    }

    

}
int main(){
    ll t;
    cin>>t;

    while(t--){
        solve();
    }
}