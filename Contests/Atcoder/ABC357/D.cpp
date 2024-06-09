#include<bits/stdc++.h>
#include <iterator>
#include <iostream>
#include <numeric>
#include <math.h>
#define ll long long
#define ull long
#define mpa make_pair
#define pb push_back
#define ff first
#define pii pair<ll,ll>
#define dd long double
#define trace(x) cerr << #x << " : " << x << endl
#define ss second
#define boost ios_base::sync_with_stdio(0)
#define forp(i,a,b) for(ll i=a;i<=b;i++)
#define rep(i,n)    for(ll i=0;i<n;++i)
#define ren(i,n)    for(ll i=n-1;i>=0;i--)
#define forn(i,a,b) for(ll i=a;i>=b;i--)
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end();
#define sc(x) scanf("%lld",&x)
#define clr(x,val) memset(x,val,sizeof(x))
#define pr(x) printf("%lld\n",x) 
#define gc getchar
#define pdd pair<dd,dd>
#define prec(x) cout<<fixed<<setprecision(x)
#define fre freopen("rental.in","r",stdin),freopen("rental.out","w",stdout)
#define arr array 
using namespace std;
ll mod=998244353;
ll modpow(ll a,ll n){
    ll res=1;
    while(n>0){
        if(n%2){
            res=(res*a)%mod;
        }
        n/=2;
        a=(a*a)%mod;
    }
    return res;
}
void solve(ll tc){
    ll n;
    cin>>n;

    string num=to_string(n);
    ll sz=num.size();
    

    ll r=modpow(10,sz);
    ll num_terms=n;
    ll den=modpow((r-1+mod)%mod,mod-2);
    ll ans=0,mul=1;

    for(ll i=sz-1;i>=0;i--){
        ll value_a=(mul*(num[i]-'0'))%mod;
        ll contri=value_a*((modpow(r,n)-1+mod)%mod);

        ans=(ans+contri)%mod;
        mul=(mul * 10)%mod;
    }

    ans=(ans * den) %mod;

    cout<<ans<<endl;


}   
int main(){
    boost;

    //pre_cum();
    //prec(10);
	//fre;


    ll t=1;
    ll tc=1;
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}