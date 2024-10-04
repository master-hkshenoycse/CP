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
ll mod=1e9+7;
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

    vector<ll> dp(1024,0);
    dp[0]=1;


    vector<ll> a(n),p(n),p_(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    for(ll i=0;i<n;i++){
        cin>>p[i];
        p_[i]=((10000-p[i])*modpow(10000,mod-2))%mod;
        p[i]=(p[i] * modpow(10000,mod-2))%mod;

    }

    for(ll i=0;i<n;i++){

        vector<ll> tmp(1024,0);
        for(ll j=0;j<1024;j++){
            ll nx_val=(j ^ a[i]);
            tmp[nx_val]=(tmp[nx_val]+dp[j]*p[i])%mod;
        }    

        for(ll j=0;j<1024;j++){
            dp[j]=(dp[j]*p_[i]+tmp[j])%mod;
        }
    }

    ll ans=0;
    for(ll i=0;i<1024;i++){
        ans=ans+(i*i*dp[i]);
        ans%=mod;
    }

    cout<<ans<<endl;



    



}
int main(){
    boost;

    //pre_cum();
    //prec(10);
	//fre;


    ll t=1;
    ll tc=1;
    cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}