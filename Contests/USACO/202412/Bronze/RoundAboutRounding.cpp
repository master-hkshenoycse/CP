#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll get_p(ll x){
    ll p=1;
    while(p<x){
        p=p*10;
    }
    return p;
}
string ll_to_str(ll n){
    if(n==0)return "0";
    string s="";
    while(n>0){
        s.push_back((n%10)+'0');
        n=n/10;
    }
    reverse(s.begin(),s.end());
    return s;
}

ll do_round(ll n,ll p){
    ll rem=n%p;
    if(rem*2>=p){
        n=n+(p-rem);
    }else{
        n=n-rem;
    }
    return n;
}
ll get_chain_p(ll n,ll p){
    ll curr_p=10;
    while(curr_p<=p){
        n=do_round(n,curr_p);
        curr_p=curr_p*10;
    }
    return n;
}
int main(){

    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;
        ll curr_po=100;
        ll y=45;
        ll ans=0;

        while(curr_po<=n*10){
            ll lim=curr_po/2;
            ans=ans+max(0ll,min(n,lim-1)-y+1);
            y=y+4*curr_po;
            curr_po=curr_po*10;
        }

        cout<<ans<<endl;
    }
}