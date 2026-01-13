/*https://usaco.org/index.php?page=viewproblem2&cpid=1446*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        vector<ll> a(n+1);
        vector<ll> prefix_sum(n+1,0),suffix_sum(n+2,0);

        for(ll i=1;i<=n;i++){
            cin>>a[i];
            prefix_sum[i]=prefix_sum[i-1]+a[i];
        }

        for(ll i=n;i>=1;i--){
            suffix_sum[i]=suffix_sum[i+1]+a[i];
        }

        ll elsie=0;
        ll sz_req=n/2-1;
        for(ll i=0;i<=sz_req;i++){
            elsie=max(elsie,prefix_sum[i]+suffix_sum[n-(sz_req-i)+1]);
        }
        ll besie=prefix_sum[n]-elsie;


        cout<<besie<<" "<<elsie<<endl;
    }
}